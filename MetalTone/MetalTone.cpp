
#include <cstdlib>
#include <cmath>
#include <iostream>
#include <cstring>
#include <unistd.h>
#include <algorithm>

#include <lv2.h>

#include "resampler.cc"
#include "resampler-table.cc"
#include "zita-resampler/resampler.h"
#include "gx_resampler.cc"


///////////////////////// DENORMAL PROTECTION WITH SSE /////////////////

#ifdef NOSSE
#undef __SSE__
#endif

#ifdef __SSE__
#include <immintrin.h>
#ifndef _IMMINTRIN_H_INCLUDED
#include <fxsrintrin.h>
#endif
/* On Intel set FZ (Flush to Zero) and DAZ (Denormals Are Zero)
   flags to avoid costly denormals */
#ifdef __SSE3__
#ifndef _PMMINTRIN_H_INCLUDED
#include <pmmintrin.h>
#endif
#else
#ifndef _XMMINTRIN_H_INCLUDED
#include <xmmintrin.h>
#endif
#endif //__SSE3__

#endif //__SSE__

typedef enum
{
   input0,
   output0,
   bypass,
   DIST, 
   HIGH, 
   LEVEL, 
   LOW, 
   MIDFREQ, 
   MIDDLE, 
} PortIndex;

#define max(x, y) (((x) > (y)) ? (x) : (y))
#define min(x, y) (((x) < (y)) ? (x) : (y))

template<class T> inline T mydsp_faustpower2_f(T x) {return (x * x);}
template<class T> inline T mydsp_faustpower3_f(T x) {return ((x * x) * x);}
template<class T> inline T mydsp_faustpower4_f(T x) {return (((x * x) * x) * x);}
template<class T> inline T mydsp_faustpower5_f(T x) {return ((((x * x) * x) * x) * x);}
template<class T> inline T mydsp_faustpower6_f(T x) {return (((((x * x) * x) * x) * x) * x);}

#define always_inline inline __attribute__((__always_inline__))


#include "MetalTone_pre.cc"
#include "MetalTone_dist.cc"
#include "MetalTone_post.cc"
///////////////////////// MACRO SUPPORT ////////////////////////////////

#define PLUGIN_URI "https://github.com/brummer10/MetalTone"

#ifndef max
#define max(x, y) (((x) > (y)) ? (x) : (y))
#endif
#ifndef min
#define min(x, y) (((x) < (y)) ? (x) : (y))
#endif


////////////////////////////// PLUG-IN CLASS ///////////////////////////

namespace metaltone {

class DenormalProtection
{
private:
#if defined (__SSE__) || (__arm64__) || defined (__aarch64__)
  uint32_t  mxcsr_mask;
  uint32_t  mxcsr;
  uint32_t  old_mxcsr;
#endif

public:
  inline void set_() {
#if defined (__arm64__) || defined (__aarch64__)
    asm volatile("mrs %0, fpcr" : "=r" (old_mxcsr));
    mxcsr = old_mxcsr;
    asm volatile("msr fpcr, %0" : : "ri" (mxcsr | 1 << 24));
#elif defined (__SSE__)
    old_mxcsr = _mm_getcsr();
    mxcsr = old_mxcsr;
    _mm_setcsr((mxcsr | _MM_DENORMALS_ZERO_MASK | _MM_FLUSH_ZERO_MASK) & mxcsr_mask);
#endif
  };
  inline void reset_() {
#if defined (__arm64__) || defined (__aarch64__)
    asm volatile("msr fpcr, %0" : : "ri" (old_mxcsr));
#elif defined (__SSE__)
    _mm_setcsr(old_mxcsr);
#endif
  };

  inline DenormalProtection()
  {
#ifdef __SSE__
    mxcsr_mask = 0xffbf; // Default MXCSR mask
    mxcsr      = 0;
#if defined(__x86_64__) || defined(_M_X64)
    uint8_t fxsave[512] __attribute__ ((aligned (16))); // Structure for storing FPU state with FXSAVE command

    memset(fxsave, 0, sizeof(fxsave));
    __builtin_ia32_fxsave(&fxsave);
    uint32_t mask = *(reinterpret_cast<uint32_t *>(&fxsave[0x1c])); // Obtain the MXCSR mask from FXSAVE structure
    if (mask != 0)
        mxcsr_mask = mask;
#endif
#endif
  };

  inline ~DenormalProtection() {};
};

class Xmetaltone
{
private:
    float* input0;
    float* output0;
    float* bypass;
    float bypass_;
    metaltone_pre::Dsp* dsp;
    metaltone_dist::Dsp* dspd;
    metaltone_post::Dsp* dspp;
    // bypass ramping
    bool needs_ramp_down;
    bool needs_ramp_up;
    float ramp_down;
    float ramp_up;
    float ramp_up_step;
    float ramp_down_step;
    bool bypassed;
    DenormalProtection MXCSR;

    // private functions
    inline void run_dsp_(uint32_t n_samples);
    inline void connect_(uint32_t port,void* data);
    inline void init_dsp_(uint32_t rate);
    inline void connect_all__ports(uint32_t port, void* data);
    inline void activate_f();
    inline void clean_up();
    inline void deactivate_f();
public:
    // LV2 Descriptor
    static const LV2_Descriptor descriptor;
    // static wrapper to private functions
    static void deactivate(LV2_Handle instance);
    static void cleanup(LV2_Handle instance);
    static void run(LV2_Handle instance, uint32_t n_samples);
    static void activate(LV2_Handle instance);
    static void connect_port(LV2_Handle instance, uint32_t port, void* data);
    static LV2_Handle instantiate(const LV2_Descriptor* descriptor,
                                double rate, const char* bundle_path,
                                const LV2_Feature* const* features);
    Xmetaltone();
    ~Xmetaltone();
};

// constructor
Xmetaltone::Xmetaltone() :

    input0(NULL),
    output0(NULL),
    bypass(NULL),
    bypass_(2),
    dsp(metaltone_pre::plugin()),
    dspd(metaltone_dist::plugin()),
    dspp(metaltone_post::plugin()),
    needs_ramp_down(false),
    needs_ramp_up(false),
    bypassed(false) {};

// destructor
Xmetaltone::~Xmetaltone() { 
    dsp->del_instance(dsp);
    dspd->del_instance(dspd);
    dspp->del_instance(dspp);
};

///////////////////////// PRIVATE CLASS  FUNCTIONS /////////////////////

void Xmetaltone::init_dsp_(uint32_t rate)
{
    dsp->init(rate);
    dspd->init(rate);
    dspp->init(rate);
    // set values for internal ramping
    ramp_down_step = 32 * (256 * rate) / 48000; 
    ramp_up_step = ramp_down_step;
    ramp_down = ramp_down_step;
    ramp_up = 0.0;
}

// connect the Ports used by the plug-in class
void Xmetaltone::connect_(uint32_t port,void* data)
{
    switch ((PortIndex)port)
    {
        case 0:
            input0 = static_cast<float*>(data);
            break;
        case 1:
            output0 = static_cast<float*>(data);
            break;
        case 2:
            bypass = static_cast<float*>(data);
            break;
        default:
            break;
    }
}

void Xmetaltone::activate_f()
{
    // allocate the internal DSP mem
}

void Xmetaltone::clean_up()
{
    // delete the internal DSP mem
}

void Xmetaltone::deactivate_f()
{
    // delete the internal DSP mem
}

void Xmetaltone::run_dsp_(uint32_t n_samples)
{
    if(n_samples<1) return;
    MXCSR.set_();

    // do inplace processing on default
    if(output0 != input0)
        memcpy(output0, input0, n_samples*sizeof(float));

    float buf0[n_samples];
    // check if bypass is pressed
    if (bypass_ != static_cast<uint32_t>(*(bypass))) {
        bypass_ = static_cast<uint32_t>(*(bypass));
        if (!bypass_) {
            needs_ramp_down = true;
            needs_ramp_up = false;
        } else {
            needs_ramp_down = false;
            needs_ramp_up = true;
            bypassed = false;
        }
    }

    if (needs_ramp_down || needs_ramp_up) {
         memcpy(buf0, input0, n_samples*sizeof(float));
    }
    if (!bypassed) {
        dsp->compute(n_samples, output0, output0);
        dspd->compute(n_samples, output0, output0);
        dspp->compute(n_samples, output0, output0);
    }
    // check if ramping is needed
    if (needs_ramp_down) {
        float fade = 0;
        for (uint32_t i=0; i<n_samples; i++) {
            if (ramp_down >= 0.0) {
                --ramp_down; 
            }
            fade = max(0.0,ramp_down) /ramp_down_step ;
            output0[i] = output0[i] * fade + buf0[i] * (1.0 - fade);
        }
        if (ramp_down <= 0.0) {
            // when ramped down, clear buffer from dsp
            needs_ramp_down = false;
            bypassed = true;
            ramp_down = ramp_down_step;
            ramp_up = 0.0;
        } else {
            ramp_up = ramp_down;
        }
    } else if (needs_ramp_up) {
        float fade = 0;
        for (uint32_t i=0; i<n_samples; i++) {
            if (ramp_up < ramp_up_step) {
                ++ramp_up ;
            }
            fade = min(ramp_up_step,ramp_up) /ramp_up_step ;
            output0[i] = output0[i] * fade + buf0[i] * (1.0 - fade);
        }
        if (ramp_up >= ramp_up_step) {
            needs_ramp_up = false;
            ramp_up = 0.0;
            ramp_down = ramp_down_step;
        } else {
            ramp_down = ramp_up;
        }
    }
    MXCSR.reset_();
}

void Xmetaltone::connect_all__ports(uint32_t port, void* data)
{
    // connect the Ports used by the plug-in class
    connect_(port,data); 
    dsp->connect(port,data);
    dspd->connect(port,data);
    dspp->connect(port,data);
}

////////////////////// STATIC CLASS  FUNCTIONS  ////////////////////////

LV2_Handle 
Xmetaltone::instantiate(const LV2_Descriptor* descriptor,
                            double rate, const char* bundle_path,
                            const LV2_Feature* const* features)
{
    // init the plug-in class
    Xmetaltone *self = new Xmetaltone();
    if (!self) {
        return NULL;
    }
    self->init_dsp_((uint32_t)rate);
    return (LV2_Handle)self;
}

void Xmetaltone::connect_port(LV2_Handle instance, 
                                   uint32_t port, void* data)
{
    // connect all ports
    static_cast<Xmetaltone*>(instance)->connect_all__ports(port, data);
}

void Xmetaltone::activate(LV2_Handle instance)
{
    // allocate needed mem
    static_cast<Xmetaltone*>(instance)->activate_f();
}

void Xmetaltone::run(LV2_Handle instance, uint32_t n_samples)
{
    // run dsp
    static_cast<Xmetaltone*>(instance)->run_dsp_(n_samples);
}

void Xmetaltone::deactivate(LV2_Handle instance)
{
    // free allocated mem
    static_cast<Xmetaltone*>(instance)->deactivate_f();
}

void Xmetaltone::cleanup(LV2_Handle instance)
{
    // well, clean up after us
    Xmetaltone* self = static_cast<Xmetaltone*>(instance);
    self->clean_up();
    delete self;
}

const LV2_Descriptor Xmetaltone::descriptor =
{
    PLUGIN_URI ,
    Xmetaltone::instantiate,
    Xmetaltone::connect_port,
    Xmetaltone::activate,
    Xmetaltone::run,
    Xmetaltone::deactivate,
    Xmetaltone::cleanup,
    NULL
};

} // end namespace metaltone

////////////////////////// LV2 SYMBOL EXPORT ///////////////////////////

LV2_SYMBOL_EXPORT
const LV2_Descriptor*
lv2_descriptor(uint32_t index)
{
    switch (index)
    {
        case 0:
            return &metaltone::Xmetaltone::descriptor;
        default:
            return NULL;
    }
}

///////////////////////////// FIN //////////////////////////////////////
