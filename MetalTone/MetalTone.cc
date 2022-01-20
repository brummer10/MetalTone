// generated from file 'metalzone.dsp' by dsp2cc:
// Code generated with Faust 2.37.3 (https://faust.grame.fr)

#include <cmath>
#include <algorithm>

#define FAUSTFLOAT float

using std::signbit;

#define max(x, y) (((x) > (y)) ? (x) : (y))
#define min(x, y) (((x) < (y)) ? (x) : (y))

template<class T> inline T mydsp_faustpower2_f(T x) {return (x * x);}
template<class T> inline T mydsp_faustpower3_f(T x) {return ((x * x) * x);}
template<class T> inline T mydsp_faustpower4_f(T x) {return (((x * x) * x) * x);}
template<class T> inline T mydsp_faustpower5_f(T x) {return ((((x * x) * x) * x) * x);}
template<class T> inline T mydsp_faustpower6_f(T x) {return (((((x * x) * x) * x) * x) * x);}

#define always_inline inline __attribute__((__always_inline__))

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


namespace metalzone {
const static double fmydspSIG0Wave0[200] = {0.0,0.12207917717,0.18497006169800001,0.20850240606100001,0.22841112256599999,0.246627947982,0.263694032626,0.27942446875299998,0.29314239572,0.30622713755100001,0.31870789052800003,0.33061250468800002,0.3419675459,0.352798355078,0.36312910466199999,0.37298285249800001,0.38238159322900001,0.39134630732199999,0.39989700782900001,0.40805278499600001,0.415831848813,0.423251569602,0.430328516735,0.437078495565,0.44351658265799998,0.44965715939299999,0.45551394401799999,0.46110002223300001,0.46642787634600003,0.47150941310799999,0.476355990241,0.48097844176299998,0.48538710212800001,0.48959182927,0.49360202656500002,0.49742666380099998,0.501074297163,0.50455308831199996,0.50787082256600002,0.51103492626799996,0.51405248331999998,0.51693025099500001,0.51967467497399999,0.52229190373900003,0.52478780224999999,0.52716796504700003,0.52943772868899996,0.53160218368099998,0.53366618578699998,0.53563436688900001,0.53751114527199995,0.53930073551400004,0.54100715783700004,0.54263424711099995,0.54418566135900004,0.54566488995200002,0.54707526134600004,0.54841995054000003,0.54970198611700005,0.55092425702900005,0.55208951899699998,0.55320040069999998,0.55425940958499997,0.55526893749999995,0.55623126598899997,0.55714857140999996,0.55802292975000001,0.55885632129399998,0.55965063499400003,0.56040767272400005,0.56112915325400003,0.56181671612100004,0.56247192524199996,0.56309627244399996,0.563691180746,0.56425800757,0.56479804772800002,0.56531253635099998,0.56580265159499998,0.56626951731300001,0.56671420551899998,0.567137738813,0.56754109262700003,0.56792519743299996,0.56829094078300002,0.56863916931900005,0.56897069062899996,0.569286275083,0.56958665750699999,0.56987253886699996,0.57014458778699995,0.57040344208000004,0.57064971013099997,0.57088397229200005,0.57110678213699995,0.57131866773100004,0.571520132776,0.57171165776199995,0.57189370100900006,0.57206669972199997,0.57223107092699999,0.57238721244099999,0.57253550371999995,0.57267630673799996,0.57280996676700002,0.57293681317,0.57305716011100005,0.57317130728099996,0.57327954053899999,0.57338213257799997,0.57347934350300001,0.573571421438,0.57365860305399996,0.57374111412399997,0.57381916999500004,0.57389297609900003,0.573962728383,0.57402861377000003,0.57409081055599998,0.57414948882200001,0.57420481079999997,0.57425693124999999,0.57430599778799996,0.57435215123100003,0.57439552589499998,0.57443624991200004,0.574474445497,0.57451022923700001,0.57454371233799995,0.57457500088400004,0.57460419606000002,0.57463139439499999,0.574656687956,0.574680164577,0.57470190803099996,0.57472199823699999,0.574740511422,0.57475752030600002,0.57477309424699996,0.574787299413,0.574800198915,0.57481185296000004,0.57482231897199998,0.57483165173499995,0.57483990349900005,0.57484712411200001,0.57485336111700003,0.57485865987200002,0.57486306363700002,0.57486661368199998,0.57486934937,0.57487130825499999,0.57487252615200002,0.57487303723100003,0.57487287408200005,0.57487206779599997,0.57487064802700005,0.57486864306499996,0.574866079892,0.57486298425100002,0.57485938069099995,0.57485529263699997,0.57485074242599998,0.57484575137299998,0.574840339802,0.57483452710799998,0.57482833178500004,0.57482177147900004,0.57481486301899998,0.57480762246100003,0.57480006511799997,0.57479220559900002,0.57478405783800002,0.57477563512800001,0.57476695014699997,0.57475801499199997,0.57474884119699998,0.57473943976899999,0.57472982120399996,0.57471999551800002,0.57470997225999998,0.57469976054399996,0.57468936906000001,0.57467880609999999,0.57466807956900001,0.57465719701499995,0.57464616563100002,0.57463499228299997,0.57462368351699999,0.57461224558000001,0.57460068442800005,0.574589005747,0.57457721495500003,0.57456531722500004,0.57455331748899996,0.57454122045300005,0.57452903060299998,0.57451675222300003,0.57450438939600001,0.57449194601700004};
class mydspSIG0 {
	
  private:
	
	int fmydspSIG0Wave0_idx;
	
  public:
	
	int getNumInputsmydspSIG0() {
		return 0;
	}
	int getNumOutputsmydspSIG0() {
		return 1;
	}
	
	void instanceInitmydspSIG0(int sample_rate) {
		fmydspSIG0Wave0_idx = 0;
	}
	
	void fillmydspSIG0(int count, double* table) {
		for (int i1 = 0; (i1 < count); i1 = (i1 + 1)) {
			table[i1] = fmydspSIG0Wave0[fmydspSIG0Wave0_idx];
			fmydspSIG0Wave0_idx = ((1 + fmydspSIG0Wave0_idx) % 200);
		}
	}

};

static mydspSIG0* newmydspSIG0() { return (mydspSIG0*)new mydspSIG0(); }
static void deletemydspSIG0(mydspSIG0* dsp) { delete dsp; }

static double ftbl0mydspSIG0[200];


class Dsp {
private:
	gx_resample::FixedRateResampler smp;
	uint32_t sample_rate;
	uint32_t fSampleRate;
	double fConst0;
	double fConst1;
	int iVec0[2];
	double fRec2[2];
	double fConst4;
	double fConst7;
	double fConst9;
	double fConst12;
	double fConst14;
	double fConst15;
	double fConst17;
	double fConst19;
	double fConst20;
	double fConst21;
	double fConst22;
	double fRec7[6];
	double fConst24;
	double fConst26;
	double fConst27;
	double fConst28;
	double fConst29;
	double fConst31;
	double fConst33;
	FAUSTFLOAT fVslider0;
	FAUSTFLOAT	*fVslider0_;
	double fRec8[2];
	double fConst35;
	double fConst37;
	double fConst38;
	double fConst39;
	double fConst40;
	double fConst41;
	double fConst43;
	double fConst45;
	double fConst46;
	double fConst47;
	double fRec6[6];
	double fConst49;
	double fConst51;
	double fConst53;
	double fConst55;
	double fConst57;
	double fConst59;
	double fConst60;
	double fConst61;
	double fConst62;
	double fConst63;
	double fConst64;
	double fConst65;
	double fConst66;
	double fConst67;
	double fConst68;
	double fConst70;
	double fConst72;
	double fConst73;
	double fConst74;
	double fConst75;
	double fConst76;
	double fRec5[7];
	double fConst78;
	double fConst80;
	double fConst81;
	double fConst82;
	double fConst83;
	double fConst84;
	double fConst85;
	double fRec4[2];
	double fConst87;
	FAUSTFLOAT fVslider1;
	FAUSTFLOAT	*fVslider1_;
	double fRec9[2];
	double fConst89;
	double fConst91;
	FAUSTFLOAT fVslider2;
	FAUSTFLOAT	*fVslider2_;
	double fRec10[2];
	double fConst93;
	double fConst95;
	double fConst97;
	double fConst99;
	double fConst101;
	double fConst103;
	double fConst104;
	double fConst105;
	double fConst106;
	double fConst107;
	double fConst108;
	double fConst109;
	double fConst110;
	double fConst111;
	double fConst112;
	double fConst113;
	double fConst114;
	double fConst115;
	double fConst116;
	double fConst117;
	double fConst118;
	double fConst119;
	double fConst120;
	double fConst121;
	double fConst123;
	double fConst125;
	double fConst127;
	double fConst129;
	double fConst131;
	double fConst133;
	double fConst135;
	double fConst137;
	double fConst139;
	double fConst140;
	double fConst141;
	double fConst142;
	double fConst143;
	double fConst144;
	double fConst145;
	double fConst146;
	double fConst147;
	double fConst148;
	double fRec3[5];
	double fConst150;
	double fConst152;
	double fConst154;
	double fConst156;
	double fConst157;
	double fConst159;
	double fConst160;
	double fConst162;
	double fConst163;
	double fConst165;
	double fConst167;
	double fConst169;
	double fConst171;
	double fConst172;
	double fConst174;
	double fConst175;
	double fConst177;
	double fConst178;
	double fConst179;
	double fConst180;
	double fConst181;
	double fConst183;
	double fConst184;
	double fConst186;
	double fConst187;
	double fConst189;
	double fConst190;
	double fConst191;
	double fConst192;
	double fConst193;
	double fConst194;
	double fConst195;
	double fConst196;
	double fConst197;
	double fConst198;
	double fConst199;
	double fConst200;
	double fConst201;
	double fConst202;
	double fConst203;
	double fConst204;
	double fConst205;
	double fConst206;
	double fConst207;
	double fConst208;
	double fConst210;
	FAUSTFLOAT fVslider3;
	FAUSTFLOAT	*fVslider3_;
	double fRec11[2];
	double fConst212;
	double fConst214;
	double fConst215;
	FAUSTFLOAT fVslider4;
	FAUSTFLOAT	*fVslider4_;
	double fRec12[2];
	double fConst217;
	double fConst219;
	double fConst221;
	double fConst223;
	double fConst225;
	double fConst227;
	double fConst228;
	double fConst230;
	double fConst231;
	double fConst232;
	double fConst233;
	double fConst234;
	double fConst235;
	double fConst236;
	double fConst237;
	double fConst238;
	double fConst239;
	double fConst240;
	double fConst241;
	double fConst242;
	double fConst243;
	double fConst244;
	double fConst245;
	double fConst246;
	double fConst247;
	double fConst248;
	double fConst250;
	double fConst252;
	double fConst254;
	double fConst256;
	double fConst257;
	double fConst259;
	double fConst260;
	double fConst261;
	double fConst262;
	double fConst263;
	double fConst264;
	double fConst265;
	double fConst266;
	double fConst267;
	double fRec1[7];
	double fConst269;
	double fConst271;
	double fConst273;
	double fConst275;
	double fConst277;
	double fConst279;
	double fConst281;
	double fConst283;
	double fConst285;
	double fConst286;
	double fConst287;
	double fConst288;
	double fConst289;
	double fConst290;
	double fConst291;
	double fConst292;
	double fConst293;
	double fConst294;
	double fConst295;
	double fConst296;
	FAUSTFLOAT fVslider5;
	FAUSTFLOAT	*fVslider5_;
	double fRec13[2];
	double fConst297;
	double fConst298;
	double fConst300;
	double fConst302;
	double fConst303;
	double fConst304;
	double fConst305;
	double fConst306;
	double fRec0[3];


public:
	void connect(uint32_t port,void* data);
	void del_instance(Dsp *p);
	void clear_state_f();
	void init(uint32_t sample_rate);
	void compute(int count, FAUSTFLOAT *input0, FAUSTFLOAT *output0);
	Dsp();
	~Dsp();
};



Dsp::Dsp() {
}

Dsp::~Dsp() {
}

inline void Dsp::clear_state_f()
{
	for (int l0 = 0; (l0 < 2); l0 = (l0 + 1)) iVec0[l0] = 0;
	for (int l1 = 0; (l1 < 2); l1 = (l1 + 1)) fRec2[l1] = 0.0;
	for (int l2 = 0; (l2 < 6); l2 = (l2 + 1)) fRec7[l2] = 0.0;
	for (int l3 = 0; (l3 < 2); l3 = (l3 + 1)) fRec8[l3] = 0.0;
	for (int l4 = 0; (l4 < 6); l4 = (l4 + 1)) fRec6[l4] = 0.0;
	for (int l5 = 0; (l5 < 7); l5 = (l5 + 1)) fRec5[l5] = 0.0;
	for (int l6 = 0; (l6 < 2); l6 = (l6 + 1)) fRec4[l6] = 0.0;
	for (int l7 = 0; (l7 < 2); l7 = (l7 + 1)) fRec9[l7] = 0.0;
	for (int l8 = 0; (l8 < 2); l8 = (l8 + 1)) fRec10[l8] = 0.0;
	for (int l9 = 0; (l9 < 5); l9 = (l9 + 1)) fRec3[l9] = 0.0;
	for (int l10 = 0; (l10 < 2); l10 = (l10 + 1)) fRec11[l10] = 0.0;
	for (int l11 = 0; (l11 < 2); l11 = (l11 + 1)) fRec12[l11] = 0.0;
	for (int l12 = 0; (l12 < 7); l12 = (l12 + 1)) fRec1[l12] = 0.0;
	for (int l13 = 0; (l13 < 2); l13 = (l13 + 1)) fRec13[l13] = 0.0;
	for (int l14 = 0; (l14 < 3); l14 = (l14 + 1)) fRec0[l14] = 0.0;
}

inline void Dsp::init(uint32_t RsamplingFreq)
{
	sample_rate = 96000;
	smp.setup(RsamplingFreq, sample_rate);
	mydspSIG0* sig0 = newmydspSIG0();
	sig0->instanceInitmydspSIG0(sample_rate);
	sig0->fillmydspSIG0(200, ftbl0mydspSIG0);
	deletemydspSIG0(sig0);
	fSampleRate = sample_rate;
	fConst0 = std::min<double>(192000.0, std::max<double>(1.0, double(fSampleRate)));
	fConst1 = mydsp_faustpower2_f(fConst0);
	double fConst2 = (4.3087720323630099e-07 * fConst0);
	double fConst3 = (fConst2 + 0.97931789424465798);
	fConst4 = (0.0 - (0.97921484773852996 / fConst3));
	double fConst5 = (9.4417836379360192e-31 * fConst0);
	double fConst6 = ((fConst0 * ((fConst0 * ((fConst0 * ((fConst0 * ((fConst0 * (fConst5 + 3.0516402141914901e-24)) + 2.5556178881271499e-20)) + 6.7899919390762401e-16)) + 5.3898319044905903e-14)) + 6.6996614046825504e-11)) + 3.3372047119416801e-10);
	fConst7 = (fConst0 / fConst6);
	double fConst8 = (9.4416652478291698e-31 * fConst0);
	fConst9 = ((fConst0 * ((fConst0 * ((fConst0 * ((fConst0 * (fConst8 + 3.4787480770110398e-24)) + 9.4232498304941602e-20)) + 7.2058668901501303e-16)) + 1.5402082244362001e-13)) + 6.6743257337363202e-11);
	double fConst10 = (2.4454389978744e-24 * fConst0);
	double fConst11 = ((fConst0 * ((fConst0 * ((fConst0 * ((fConst0 * (fConst10 + 6.53471849041744e-20)) + 2.5429934560721901e-16)) + 7.8893500689320605e-13)) + 1.26822396718671e-09)) + 3.4370367963274599e-07);
	fConst12 = (fConst0 / fConst11);
	double fConst13 = (2.60149822831355e-21 * fConst0);
	fConst14 = ((fConst0 * ((fConst0 * (fConst13 + 3.7902141568022202e-16)) + 6.2380028516919599e-12)) + 5.1554905491952698e-10);
	fConst15 = (1.0 / fConst11);
	double fConst16 = (1.2227194989371999e-23 * fConst0);
	fConst17 = ((fConst0 * ((fConst0 * ((fConst0 * ((fConst0 * (-1.9604155471252301e-19 - fConst16)) + -2.5429934560721901e-16)) + 7.8893500689320605e-13)) + 3.8046719015601301e-09)) + 1.71851839816373e-06);
	double fConst18 = (2.4454389978743999e-23 * fConst0);
	fConst19 = ((fConst0 * ((fConst0 * ((fConst0 * ((fConst0 * (fConst18 + 1.3069436980834899e-19)) + -5.0859869121443703e-16)) + -1.5778700137864101e-12)) + 2.5364479343734201e-09)) + 3.4370367963274599e-06);
	fConst20 = ((fConst0 * ((fConst0 * ((fConst0 * ((fConst0 * (1.3069436980834899e-19 - fConst18)) + 5.0859869121443703e-16)) + -1.5778700137864101e-12)) + -2.5364479343734201e-09)) + 3.4370367963274599e-06);
	fConst21 = ((fConst0 * ((fConst0 * ((fConst0 * ((fConst0 * (fConst16 + -1.9604155471252301e-19)) + 2.5429934560721901e-16)) + 7.8893500689320605e-13)) + -3.8046719015601301e-09)) + 1.71851839816373e-06);
	fConst22 = ((fConst0 * ((fConst0 * ((fConst0 * ((fConst0 * (6.53471849041744e-20 - fConst10)) + -2.5429934560721901e-16)) + 7.8893500689320605e-13)) + -1.26822396718671e-09)) + 3.4370367963274599e-07);
	double fConst23 = (7.8044946849406405e-21 * fConst0);
	fConst24 = ((fConst0 * ((fConst0 * (-3.7902141568022202e-16 - fConst23)) + 6.2380028516919599e-12)) + 1.54664716475858e-09);
	double fConst25 = (5.2029964566270999e-21 * fConst0);
	fConst26 = ((fConst0 * ((fConst0 * (fConst25 + -7.5804283136044503e-16)) + -1.24760057033839e-11)) + 1.03109810983905e-09);
	fConst27 = ((fConst0 * ((fConst0 * (fConst25 + 7.5804283136044503e-16)) + -1.24760057033839e-11)) + -1.03109810983905e-09);
	fConst28 = ((fConst0 * ((fConst0 * (3.7902141568022202e-16 - fConst23)) + 6.2380028516919599e-12)) + -1.54664716475858e-09);
	fConst29 = ((fConst0 * ((fConst0 * (fConst13 + -3.7902141568022202e-16)) + 6.2380028516919599e-12)) + -5.1554905491952698e-10);
	double fConst30 = (5.4088445277391402e-26 * fConst0);
	fConst31 = ((fConst0 * ((fConst0 * ((fConst0 * (-3.4531594479445001e-19 - fConst30)) + -2.3482834695055598e-16)) + 1.4897904352364899e-14)) + 5.1665220775489204e-13);
	double fConst32 = (1.3522111319347899e-23 * fConst0);
	fConst33 = ((fConst0 * ((fConst0 * ((fConst0 * (-1.7637351711248199e-20 - fConst32)) + -1.06817415024386e-18)) + 1.4844236642698899e-17)) + 1.4821946450804801e-21);
	double fConst34 = (1.0817689055478301e-25 * fConst0);
	fConst35 = ((fConst0 * ((fConst0 * ((fConst0 * (fConst34 + 2.3021062986296699e-19)) + -4.6965669390111304e-16)) + -2.9795808704729698e-14)) + 3.4443480516992802e-13);
	double fConst36 = (2.7044222638695698e-23 * fConst0);
	fConst37 = ((fConst0 * ((fConst0 * ((fConst0 * (fConst36 + 1.17582344741655e-20)) + -2.1363483004877299e-18)) + -2.9688473285397897e-17)) + 9.8812976338698691e-22);
	fConst38 = ((fConst0 * ((fConst0 * ((fConst0 * (2.3021062986296699e-19 - fConst34)) + 4.6965669390111304e-16)) + -2.9795808704729698e-14)) + -3.4443480516992802e-13);
	fConst39 = ((fConst0 * ((fConst0 * ((fConst0 * (1.17582344741655e-20 - fConst36)) + 2.1363483004877299e-18)) + -2.9688473285397897e-17)) + -9.8812976338698691e-22);
	fConst40 = ((fConst0 * ((fConst0 * ((fConst0 * (fConst30 + -3.4531594479445001e-19)) + 2.3482834695055598e-16)) + 1.4897904352364899e-14)) + -5.1665220775489204e-13);
	fConst41 = ((fConst0 * ((fConst0 * ((fConst0 * (fConst32 + -1.7637351711248199e-20)) + 1.06817415024386e-18)) + 1.4844236642698899e-17)) + -1.4821946450804801e-21);
	double fConst42 = (1.08176890554783e-26 * fConst0);
	fConst43 = ((fConst0 * ((fConst0 * ((fConst0 * (1.1510531493148299e-19 - fConst42)) + -2.3482834695055598e-16)) + 1.4897904352364899e-14)) + -1.7221740258496401e-13);
	double fConst44 = (2.7044222638695701e-24 * fConst0);
	fConst45 = ((fConst0 * ((fConst0 * ((fConst0 * (5.8791172370827298e-21 - fConst44)) + -1.06817415024386e-18)) + 1.4844236642698899e-17)) + -4.9406488169349298e-22);
	fConst46 = ((fConst0 * ((fConst0 * ((fConst0 * (fConst42 + 1.1510531493148299e-19)) + 2.3482834695055598e-16)) + 1.4897904352364899e-14)) + 1.7221740258496401e-13);
	fConst47 = ((fConst0 * ((fConst0 * ((fConst0 * (fConst44 + 5.8791172370827298e-21)) + 1.06817415024386e-18)) + 1.4844236642698899e-17)) + 4.9406488169349298e-22);
	double fConst48 = (3.0084281762721699e-27 * fConst0);
	fConst49 = ((fConst0 * ((fConst0 * (fConst48 + 6.4030596924903599e-20)) + 4.5556661466723199e-16)) + 1.1349133002384799e-14);
	double fConst50 = (7.52107044068041e-25 * fConst0);
	fConst51 = (fConst0 * ((fConst0 * (fConst50 + 8.0065104645446096e-18)) + 5.6745931716549698e-14));
	double fConst52 = (1.5042140881360799e-26 * fConst0);
	fConst53 = ((fConst0 * ((fConst0 * (-1.9209179077471099e-19 - fConst52)) + -4.5556661466723199e-16)) + 1.1349133002384799e-14);
	double fConst54 = (3.76053522034021e-24 * fConst0);
	fConst55 = (fConst0 * ((fConst0 * (-2.4019531393633801e-17 - fConst54)) + -5.6745931716549698e-14));
	double fConst56 = (3.0084281762721598e-26 * fConst0);
	fConst57 = ((fConst0 * ((fConst0 * (fConst56 + 1.28061193849807e-19)) + -9.1113322933446397e-16)) + -2.2698266004769699e-14);
	double fConst58 = (7.5210704406804096e-24 * fConst0);
	fConst59 = (fConst0 * ((fConst0 * (fConst58 + 1.6013020929089201e-17)) + -1.13491863433099e-13));
	fConst60 = ((fConst0 * ((fConst0 * (1.28061193849807e-19 - fConst56)) + 9.1113322933446397e-16)) + -2.2698266004769699e-14);
	fConst61 = (fConst0 * ((fConst0 * (1.6013020929089201e-17 - fConst58)) + 1.13491863433099e-13));
	fConst62 = ((fConst0 * ((fConst0 * (fConst52 + -1.9209179077471099e-19)) + 4.5556661466723199e-16)) + 1.1349133002384799e-14);
	fConst63 = (fConst0 * ((fConst0 * (fConst54 + -2.4019531393633801e-17)) + 5.6745931716549698e-14));
	fConst64 = ((fConst0 * ((fConst0 * (6.4030596924903599e-20 - fConst48)) + -4.5556661466723199e-16)) + 1.1349133002384799e-14);
	fConst65 = (fConst0 * ((fConst0 * (8.0065104645446096e-18 - fConst50)) + -5.6745931716549698e-14));
	fConst66 = ftbl0mydspSIG0[199];
	fConst67 = ftbl0mydspSIG0[0];
	fConst68 = (1.0 / fConst6);
	double fConst69 = (5.6650701827616098e-30 * fConst0);
	fConst70 = ((fConst0 * ((fConst0 * ((fConst1 * ((fConst0 * (-1.2206560856766e-23 - fConst69)) + -5.1112357762542902e-20)) + 1.07796638089812e-13)) + 2.6798645618730201e-10)) + 2.0023228271650098e-09);
	double fConst71 = (1.4162675456904e-29 * fConst0);
	fConst72 = ((fConst0 * ((fConst0 * ((fConst0 * ((fConst0 * ((fConst0 * (fConst71 + 1.5258201070957399e-23)) + -2.5556178881271499e-20)) + -2.0369975817228701e-15)) + -5.3898319044905903e-14)) + 3.3498307023412798e-10)) + 5.0058070679125201e-09);
	fConst73 = ((fConst1 * ((fConst1 * (1.02224715525086e-19 - (1.8883567275872e-29 * fConst1))) + -2.1559327617962399e-13)) + 6.6744094238833601e-09);
	fConst74 = ((fConst0 * ((fConst0 * ((fConst0 * ((fConst0 * ((fConst0 * (fConst71 + -1.5258201070957399e-23)) + -2.5556178881271499e-20)) + 2.0369975817228701e-15)) + -5.3898319044905903e-14)) + -3.3498307023412798e-10)) + 5.0058070679125201e-09);
	fConst75 = ((fConst0 * ((fConst0 * ((fConst1 * ((fConst0 * (1.2206560856766e-23 - fConst69)) + -5.1112357762542902e-20)) + 1.07796638089812e-13)) + -2.6798645618730201e-10)) + 2.0023228271650098e-09);
	fConst76 = ((fConst0 * ((fConst0 * ((fConst0 * ((fConst0 * ((fConst0 * (fConst5 + -3.0516402141914901e-24)) + 2.5556178881271499e-20)) + -6.7899919390762401e-16)) + 5.3898319044905903e-14)) + -6.6996614046825504e-11)) + 3.3372047119416801e-10);
	double fConst77 = (5.6649991486975001e-30 * fConst0);
	fConst78 = ((fConst0 * ((fConst1 * ((fConst0 * (-1.39149923080442e-23 - fConst77)) + -1.8846499660988301e-19)) + 3.0804164488724102e-13)) + 2.6697302934945302e-10);
	double fConst79 = (1.4162497871743799e-29 * fConst0);
	fConst80 = ((fConst0 * ((fConst0 * ((fConst0 * ((fConst0 * (fConst79 + 1.73937403850552e-23)) + -9.4232498304941602e-20)) + -2.1617600670450401e-15)) + -1.5402082244362001e-13)) + 3.3371628668681602e-10);
	fConst81 = (fConst0 * ((fConst1 * (3.7692999321976602e-19 - (1.8883330495658301e-29 * fConst1))) + -6.1608328977448205e-13));
	fConst82 = ((fConst0 * ((fConst0 * ((fConst0 * ((fConst0 * (fConst79 + -1.73937403850552e-23)) + -9.4232498304941602e-20)) + 2.1617600670450401e-15)) + -1.5402082244362001e-13)) + -3.3371628668681602e-10);
	fConst83 = ((fConst0 * ((fConst1 * ((fConst0 * (1.39149923080442e-23 - fConst77)) + -1.8846499660988301e-19)) + 3.0804164488724102e-13)) + -2.6697302934945302e-10);
	fConst84 = ((fConst0 * ((fConst0 * ((fConst0 * ((fConst0 * (fConst8 + -3.4787480770110398e-24)) + 9.4232498304941602e-20)) + -7.2058668901501303e-16)) + 1.5402082244362001e-13)) + -6.6743257337363202e-11);
	fConst85 = ((0.97931789424465798 - fConst2) / fConst3);
	double fConst86 = (7.0400571136071893e-21 * fConst0);
	fConst87 = ((fConst1 * (-8.0078455147435801e-15 - fConst86)) + 3.01449593071743e-09);
	double fConst88 = (2.2689898956886401e-20 * fConst0);
	fConst89 = ((fConst1 * (-2.5785659195546901e-14 - fConst88)) + 2.8336690626334099e-09);
	double fConst90 = (2.90899689459521e-20 * fConst0);
	fConst91 = ((fConst1 * (fConst90 + 3.3058822486064198e-14)) + -3.6329408758091402e-09);
	double fConst92 = (3.5509911478994701e-20 * fConst0);
	fConst93 = (fConst92 + 4.0437906149326201e-14);
	double fConst94 = (2.9106484818323203e-20 * fConst0);
	fConst95 = (-3.3145884355804401e-14 - fConst94);
	double fConst96 = (2.9106129719208402e-20 * fConst0);
	fConst97 = (-3.3145511993556e-14 - fConst96);
	double fConst98 = (2.2702767092803499e-20 * fConst0);
	fConst99 = (fConst98 + 2.5853531103439001e-14);
	double fConst100 = (7.1850090332444799e-21 * fConst0);
	fConst101 = ((fConst1 * (-8.1910225583183598e-15 - fConst100)) + 9.75088549859571e-08);
	double fConst102 = (7.0440682036892302e-21 * fConst0);
	fConst103 = ((fConst1 * (fConst102 + 8.0289386899708896e-15)) + -7.9925498511277097e-08);
	fConst104 = ((1.05600856704108e-20 * fConst1) + -1.7563131193709001e-11);
	fConst105 = ((3.4034848435329498e-20 * fConst1) + -3.3309268753080901e-12);
	fConst106 = (4.2704346619705603e-12 - (4.3634953418928202e-20 * fConst1));
	fConst107 = (1.9501505649412399e-10 - (5.3264867218491997e-20 * fConst1));
	fConst108 = ((4.3659727227484801e-20 * fConst1) + -1.59848695208376e-10);
	fConst109 = ((4.36591945788126e-20 * fConst1) + -1.5984689978980099e-10);
	fConst110 = (1.24680735435677e-10 - (3.4054150639205197e-20 * fConst1));
	fConst111 = ((1.07775135498667e-20 * fConst1) + -5.9678280830641404e-11);
	fConst112 = (5.5258291490493902e-11 - (1.05661023055338e-20 * fConst1));
	fConst113 = ((fConst1 * (8.0078455147435801e-15 - fConst86)) + -3.01449593071743e-09);
	fConst114 = ((fConst1 * (2.5785659195546901e-14 - fConst88)) + -2.8336690626334099e-09);
	fConst115 = ((fConst1 * (fConst90 + -3.3058822486064198e-14)) + 3.6329408758091402e-09);
	fConst116 = (fConst92 + -4.0437906149326201e-14);
	fConst117 = (3.3145884355804401e-14 - fConst94);
	fConst118 = (3.3145511993556e-14 - fConst96);
	fConst119 = (fConst98 + -2.5853531103439001e-14);
	fConst120 = ((fConst1 * (8.1910225583183598e-15 - fConst100)) + -9.75088549859571e-08);
	fConst121 = ((fConst1 * (fConst102 + -8.0289386899708896e-15)) + 7.9925498511277097e-08);
	double fConst122 = (1.7600142784018e-21 * fConst0);
	fConst123 = ((fConst0 * ((fConst0 * (fConst122 + -4.0039227573717901e-15)) + 8.7815655968545197e-12)) + -1.5072479653587101e-09);
	double fConst124 = (5.6724747392215897e-21 * fConst0);
	fConst125 = ((fConst0 * ((fConst0 * (fConst124 + -1.28928295977734e-14)) + 1.6654634376540501e-12)) + -1.4168345313167e-09);
	double fConst126 = (7.2724922364880296e-21 * fConst0);
	fConst127 = ((fConst0 * ((fConst0 * (1.6529411243032099e-14 - fConst126)) + -2.1352173309852801e-12)) + 1.8164704379045701e-09);
	double fConst128 = (8.8774778697486707e-21 * fConst0);
	fConst129 = ((fConst0 * (2.0218953074663101e-14 - fConst128)) + -9.7507528247061804e-11);
	double fConst130 = (7.2766212045808007e-21 * fConst0);
	fConst131 = ((fConst0 * (fConst130 + -1.6572942177902201e-14)) + 7.9924347604188206e-11);
	double fConst132 = (7.2765324298021004e-21 * fConst0);
	fConst133 = ((fConst0 * (fConst132 + -1.6572755996778e-14)) + 7.9923449894900598e-11);
	double fConst134 = (5.67569177320088e-21 * fConst0);
	fConst135 = ((fConst0 * (1.2926765551719501e-14 - fConst134)) + -6.2340367717838696e-11);
	double fConst136 = (1.79625225831112e-21 * fConst0);
	fConst137 = ((fConst0 * ((fConst0 * (fConst136 + -4.0955112791591799e-15)) + 2.9839140415320702e-11)) + -4.8754427492978497e-08);
	double fConst138 = (1.7610170509223102e-21 * fConst0);
	fConst139 = ((fConst0 * ((fConst0 * (4.0144693449854503e-15 - fConst138)) + -2.7629145745247e-11)) + 3.9962749255638601e-08);
	fConst140 = ((fConst0 * ((fConst0 * (fConst122 + 4.0039227573717901e-15)) + 8.7815655968545197e-12)) + 1.5072479653587101e-09);
	fConst141 = ((fConst0 * ((fConst0 * (fConst124 + 1.28928295977734e-14)) + 1.6654634376540501e-12)) + 1.4168345313167e-09);
	fConst142 = ((fConst0 * ((fConst0 * (-1.6529411243032099e-14 - fConst126)) + -2.1352173309852801e-12)) + -1.8164704379045701e-09);
	fConst143 = ((fConst0 * (-2.0218953074663101e-14 - fConst128)) + -9.7507528247061804e-11);
	fConst144 = ((fConst0 * (fConst130 + 1.6572942177902201e-14)) + 7.9924347604188206e-11);
	fConst145 = ((fConst0 * (fConst132 + 1.6572755996778e-14)) + 7.9923449894900598e-11);
	fConst146 = ((fConst0 * (-1.2926765551719501e-14 - fConst134)) + -6.2340367717838696e-11);
	fConst147 = ((fConst0 * ((fConst0 * (fConst136 + 4.0955112791591799e-15)) + 2.9839140415320702e-11)) + 4.8754427492978497e-08);
	fConst148 = ((fConst0 * ((fConst0 * (-4.0144693449854503e-15 - fConst138)) + -2.7629145745247e-11)) + -3.9962749255638601e-08);
	double fConst149 = (1.60067201269546e-22 * fConst0);
	fConst150 = ((fConst0 * ((fConst0 * (fConst149 + 4.4756157832158003e-16)) + 1.0517807941630899e-11)) + 9.89915928390436e-09);
	double fConst151 = (7.2723307898573293e-21 * fConst0);
	fConst152 = ((fConst0 * ((fConst0 * (fConst151 + 2.3803403143178002e-14)) + 2.0187473560497501e-11)) + 2.2160438587292599e-09);
	double fConst153 = (7.2724035138924704e-21 * fConst0);
	fConst154 = ((fConst0 * ((fConst0 * (-2.0167403060262301e-14 - fConst153)) + -1.97181527174289e-11)) + -1.8164442812885799e-09);
	double fConst155 = (7.2765484398241294e-21 * fConst0);
	fConst156 = ((fConst0 * (-1.29345022318831e-14 - fConst155)) + -6.2340367733824194e-11);
	fConst157 = ((fConst0 * (fConst155 + 1.65727764517951e-14)) + 7.9923548376697702e-11);
	double fConst158 = (7.2764756743397304e-21 * fConst0);
	fConst159 = ((fConst0 * (fConst158 + 1.6572647106772799e-14)) + 7.9922924973020298e-11);
	fConst160 = ((fConst0 * (-2.02108849439427e-14 - fConst158)) + -9.7505929784087401e-11);
	double fConst161 = (1.6015843200118599e-22 * fConst0);
	fConst162 = ((fConst0 * ((fConst0 * (fConst161 + 2.88365933059091e-16)) + 7.8396168289614906e-12)) + 3.1170495568750797e-08);
	fConst163 = ((fConst0 * ((fConst0 * (-3.6844514905968301e-16 - fConst161)) + -1.0045781804538e-11)) + -3.99621738060907e-08);
	double fConst164 = (6.4026880507818599e-22 * fConst0);
	fConst165 = ((fConst1 * (-8.9512315664316104e-16 - fConst164)) + 1.97983185678087e-08);
	double fConst166 = (2.9089323159429299e-20 * fConst0);
	fConst167 = ((fConst1 * (-4.7606806286355902e-14 - fConst166)) + 4.4320877174585197e-09);
	double fConst168 = (2.90896140555699e-20 * fConst0);
	fConst169 = ((fConst1 * (fConst168 + 4.0334806120524702e-14)) + -3.6328885625771702e-09);
	double fConst170 = (2.9106193759296499e-20 * fConst0);
	fConst171 = (fConst170 + 2.5869004463766101e-14);
	fConst172 = (-3.3145552903590199e-14 - fConst170);
	double fConst173 = (2.9105902697358897e-20 * fConst0);
	fConst174 = (-3.3145294213545598e-14 - fConst173);
	fConst175 = (fConst173 + 4.0421769887885299e-14);
	double fConst176 = (6.4063372800474302e-22 * fConst0);
	fConst177 = ((fConst1 * (-5.7673186611818101e-16 - fConst176)) + 6.2340991137501501e-08);
	fConst178 = ((fConst1 * (fConst176 + 7.3689029811936702e-16)) + -7.9924347612181399e-08);
	fConst179 = ((9.6040320761727809e-22 * fConst1) + -2.1035615883261798e-11);
	fConst180 = ((4.3633984739144e-20 * fConst1) + -4.0374947120995002e-11);
	fConst181 = (3.94363054348578e-11 - (4.3634421083354798e-20 * fConst1));
	double fConst182 = (4.36592906389448e-20 * fConst1);
	fConst183 = (1.24680735467648e-10 - fConst182);
	fConst184 = (fConst182 + -1.5984709675339499e-10);
	double fConst185 = (4.3658854046038397e-20 * fConst1);
	fConst186 = (fConst185 + -1.5984584994604101e-10);
	fConst187 = (1.9501185956817501e-10 - fConst185);
	double fConst188 = (9.6095059200711491e-22 * fConst1);
	fConst189 = (fConst188 + -1.5679233657923001e-11);
	fConst190 = (2.0091563609076e-11 - fConst188);
	fConst191 = ((fConst1 * (8.9512315664316104e-16 - fConst164)) + -1.97983185678087e-08);
	fConst192 = ((fConst1 * (4.7606806286355902e-14 - fConst166)) + -4.4320877174585197e-09);
	fConst193 = ((fConst1 * (fConst168 + -4.0334806120524702e-14)) + 3.6328885625771702e-09);
	fConst194 = (fConst170 + -2.5869004463766101e-14);
	fConst195 = (3.3145552903590199e-14 - fConst170);
	fConst196 = (3.3145294213545598e-14 - fConst173);
	fConst197 = (fConst173 + -4.0421769887885299e-14);
	fConst198 = ((fConst1 * (5.7673186611818101e-16 - fConst176)) + -6.2340991137501501e-08);
	fConst199 = ((fConst1 * (fConst176 + -7.3689029811936702e-16)) + 7.9924347612181399e-08);
	fConst200 = ((fConst0 * ((fConst0 * (fConst149 + -4.4756157832158003e-16)) + 1.0517807941630899e-11)) + -9.89915928390436e-09);
	fConst201 = ((fConst0 * ((fConst0 * (fConst151 + -2.3803403143178002e-14)) + 2.0187473560497501e-11)) + -2.2160438587292599e-09);
	fConst202 = ((fConst0 * ((fConst0 * (2.0167403060262301e-14 - fConst153)) + -1.97181527174289e-11)) + 1.8164442812885799e-09);
	fConst203 = ((fConst0 * (1.29345022318831e-14 - fConst155)) + -6.2340367733824194e-11);
	fConst204 = ((fConst0 * (fConst155 + -1.65727764517951e-14)) + 7.9923548376697702e-11);
	fConst205 = ((fConst0 * (fConst158 + -1.6572647106772799e-14)) + 7.9922924973020298e-11);
	fConst206 = ((fConst0 * (2.02108849439427e-14 - fConst158)) + -9.7505929784087401e-11);
	fConst207 = ((fConst0 * ((fConst0 * (fConst161 + -2.88365933059091e-16)) + 7.8396168289614906e-12)) + -3.1170495568750797e-08);
	fConst208 = ((fConst0 * ((fConst0 * (3.6844514905968301e-16 - fConst161)) + -1.0045781804538e-11)) + 3.99621738060907e-08);
	double fConst209 = (9.2936496343283305e-31 * fConst0);
	fConst210 = ((fConst0 * ((fConst1 * ((fConst0 * (-1.06644965032738e-25 - fConst209)) + -2.2530250529806201e-21)) + 2.88937273789334e-16)) + 3.40910044884256e-15);
	double fConst211 = (4.2234296913936001e-29 * fConst0);
	fConst212 = ((fConst0 * ((fConst1 * ((fConst0 * (-3.9221403182882201e-24 - fConst211)) + -4.9249274848424202e-20)) + 1.98425395320685e-17)) + 7.5857413305164699e-17);
	double fConst213 = (4.7982649833695701e-28 * fConst0);
	fConst214 = (fConst0 * ((fConst1 * ((fConst0 * (-3.4058360249855198e-23 - fConst213)) + -1.5573881049312799e-21)) + 5.9320297842186001e-20));
	fConst215 = mydsp_faustpower3_f(fConst0);
	double fConst216 = (4.19467819701782e-34 * fConst0);
	fConst217 = ((fConst0 * (fConst216 + 1.71187870665812e-26)) + 1.8148178813897101e-21);
	double fConst218 = (9.5333595386768694e-33 * fConst0);
	fConst219 = ((fConst0 * (fConst218 + 3.8888719017657498e-25)) + 4.1227121340066e-20);
	double fConst220 = (2.3234124085820799e-30 * fConst0);
	fConst221 = ((fConst0 * ((fConst0 * ((fConst0 * ((fConst0 * (fConst220 + 1.33306206290922e-25)) + -1.12651252649031e-21)) + -1.4253701773974901e-17)) + -1.44468636894667e-16)) + 4.2613755610532002e-15);
	double fConst222 = (1.0558574228484e-28 * fConst0);
	fConst223 = ((fConst0 * ((fConst0 * ((fConst0 * ((fConst0 * (fConst222 + 4.90267539786028e-24)) + -2.4624637424212101e-20)) + -2.3266525652338e-18)) + -9.9212697660342607e-18)) + 9.4821766631455905e-17);
	double fConst224 = (1.19956624584239e-27 * fConst0);
	fConst225 = (fConst0 * ((fConst0 * ((fConst0 * ((fConst0 * (fConst224 + 4.2572950312319001e-23)) + -7.78694052465638e-22)) + -4.4355659165854498e-20)) + -2.9660148921093001e-20));
	double fConst226 = (1.04866954925446e-33 * fConst0);
	fConst227 = ((fConst0 * (-2.1398483833226501e-26 - fConst226)) + 9.0740894069485297e-22);
	fConst228 = ((fConst0 * fConst227) + -1.34496199446404e-34);
	double fConst229 = (2.38333988466922e-32 * fConst0);
	fConst230 = ((fConst0 * (-4.8610898772071904e-25 - fConst229)) + 2.0613560670033e-20);
	fConst231 = ((fConst0 * fConst230) + -3.0553430133213101e-33);
	fConst232 = ((fConst1 * (4.5060501059612499e-21 - (3.09788321144278e-30 * fConst1))) + -5.7787454757866899e-16);
	fConst233 = ((fConst1 * (9.8498549696848403e-20 - (1.4078098971312e-28 * fConst1))) + -3.9685079064137e-17);
	fConst234 = ((fConst1 * (3.1147762098625501e-21 - (1.59942166112319e-27 * fConst1))) + -1.18640595684372e-19);
	fConst235 = ((1.3982260656726099e-33 * fConst1) + -3.6296357627794104e-21);
	fConst236 = ((3.1777865128922901e-32 * fConst1) + -8.2454242680132096e-20);
	fConst237 = ((fConst0 * ((fConst0 * ((fConst0 * ((fConst0 * (fConst220 + -1.33306206290922e-25)) + -1.12651252649031e-21)) + 1.4253701773974901e-17)) + -1.44468636894667e-16)) + -4.2613755610532002e-15);
	fConst238 = ((fConst0 * ((fConst0 * ((fConst0 * ((fConst0 * (fConst222 + -4.90267539786028e-24)) + -2.4624637424212101e-20)) + 2.3266525652338e-18)) + -9.9212697660342607e-18)) + -9.4821766631455905e-17);
	fConst239 = (fConst0 * ((fConst0 * ((fConst0 * ((fConst0 * (fConst224 + -4.2572950312319001e-23)) + -7.78694052465638e-22)) + 4.4355659165854498e-20)) + -2.9660148921093001e-20));
	fConst240 = ((fConst0 * (2.1398483833226501e-26 - fConst226)) + 9.0740894069485297e-22);
	fConst241 = ((fConst0 * fConst240) + 1.34496199446404e-34);
	fConst242 = ((fConst0 * (4.8610898772071904e-25 - fConst229)) + 2.0613560670033e-20);
	fConst243 = ((fConst0 * fConst242) + 3.0553430133213101e-33);
	fConst244 = ((fConst0 * ((fConst1 * ((fConst0 * (1.06644965032738e-25 - fConst209)) + -2.2530250529806201e-21)) + 2.88937273789334e-16)) + -3.40910044884256e-15);
	fConst245 = ((fConst0 * ((fConst1 * ((fConst0 * (3.9221403182882201e-24 - fConst211)) + -4.9249274848424202e-20)) + 1.98425395320685e-17)) + -7.5857413305164699e-17);
	fConst246 = (fConst0 * ((fConst1 * ((fConst0 * (3.4058360249855198e-23 - fConst213)) + -1.5573881049312799e-21)) + 5.9320297842186001e-20));
	fConst247 = ((fConst0 * (fConst216 + -1.71187870665812e-26)) + 1.8148178813897101e-21);
	fConst248 = ((fConst0 * (fConst218 + -3.8888719017657498e-25)) + 4.1227121340066e-20);
	double fConst249 = (1.54894160572139e-31 * fConst0);
	fConst250 = ((fConst0 * ((fConst0 * ((fConst0 * ((fConst0 * (fConst249 + -2.6661241258184403e-26)) + 1.12651252649031e-21)) + -4.7512339246582902e-18)) + 1.44468636894667e-16)) + -8.52275112210641e-16);
	double fConst251 = (7.0390494856559904e-30 * fConst0);
	fConst252 = ((fConst0 * ((fConst0 * ((fConst0 * ((fConst0 * (fConst251 + -9.8053507957205596e-25)) + 2.4624637424212101e-20)) + -7.7555085507793196e-19)) + 9.9212697660342607e-18)) + -1.8964353326291199e-17);
	double fConst253 = (7.9971083056159505e-29 * fConst0);
	fConst254 = (fConst0 * ((fConst0 * ((fConst0 * ((fConst0 * (fConst253 + -8.5145900624637996e-24)) + 7.78694052465638e-22)) + -1.47852197219515e-20)) + 2.9660148921093001e-20));
	double fConst255 = (6.9911303283630398e-35 * fConst0);
	fConst256 = ((fConst0 * (4.2796967666453101e-27 - fConst255)) + -9.0740894069485297e-22);
	fConst257 = ((fConst0 * fConst256) + -4.4832066482134701e-35);
	double fConst258 = (1.5888932564461401e-33 * fConst0);
	fConst259 = ((fConst0 * (9.7221797544143698e-26 - fConst258)) + -2.0613560670033e-20);
	fConst260 = ((fConst0 * fConst259) + -1.0184476711071e-33);
	fConst261 = ((fConst0 * ((fConst0 * ((fConst0 * ((fConst0 * (fConst249 + 2.6661241258184403e-26)) + 1.12651252649031e-21)) + 4.7512339246582902e-18)) + 1.44468636894667e-16)) + 8.52275112210641e-16);
	fConst262 = ((fConst0 * ((fConst0 * ((fConst0 * ((fConst0 * (fConst251 + 9.8053507957205596e-25)) + 2.4624637424212101e-20)) + 7.7555085507793196e-19)) + 9.9212697660342607e-18)) + 1.8964353326291199e-17);
	fConst263 = (fConst0 * ((fConst0 * ((fConst0 * ((fConst0 * (fConst253 + 8.5145900624637996e-24)) + 7.78694052465638e-22)) + 1.47852197219515e-20)) + 2.9660148921093001e-20));
	fConst264 = ((fConst0 * (-4.2796967666453101e-27 - fConst255)) + -9.0740894069485297e-22);
	fConst265 = ((fConst0 * fConst264) + 4.4832066482134701e-35);
	fConst266 = ((fConst0 * (-9.7221797544143698e-26 - fConst258)) + -2.0613560670033e-20);
	fConst267 = ((fConst0 * fConst266) + 1.0184476711071e-33);
	double fConst268 = (7.0142010584466404e-35 * fConst0);
	fConst269 = ((fConst0 * ((fConst0 * ((fConst0 * ((fConst0 * (fConst268 + -1.21840999977658e-26)) + -1.74095101616584e-22)) + -4.7325256235815704e-18)) + -4.7082656768348503e-17)) + -1.1712397241167799e-16);
	double fConst270 = (1.5941366041924201e-33 * fConst0);
	fConst271 = ((fConst0 * ((fConst0 * ((fConst0 * (fConst270 + -6.5128358242887097e-25)) + -3.9879477801707701e-21)) + -3.7833348396828302e-19)) + -1.7826268601057401e-18);
	double fConst272 = (8.5074553512784105e-24 * fConst0);
	fConst273 = (fConst0 * ((fConst0 * (-6.0354236449383803e-22 - fConst272)) + -2.7880190392875799e-21));
	double fConst274 = (4.2085206350679797e-34 * fConst0);
	fConst275 = ((fConst0 * ((fConst1 * ((fConst0 * (4.8736399991063297e-26 - fConst274)) + 3.4819020323316701e-22)) + -9.4165313536697006e-17)) + -4.6849588964671098e-16);
	double fConst276 = (9.5648196251544994e-33 * fConst0);
	fConst277 = ((fConst1 * ((fConst0 * (2.6051343297154901e-24 - fConst276)) + 7.9758955603415402e-21)) + -3.5652537202114702e-18);
	double fConst278 = (3.4029821405113701e-23 * fConst0);
	fConst279 = (fConst1 * (fConst278 + 1.20708472898768e-21));
	double fConst280 = (1.0521301587669999e-33 * fConst0);
	fConst281 = ((fConst0 * ((fConst0 * ((fConst0 * ((fConst0 * (fConst280 + -6.0920499988829198e-26)) + 1.74095101616584e-22)) + 1.41975768707447e-17)) + 4.7082656768348503e-17)) + -5.8561986205838902e-16);
	double fConst282 = (2.3912049062886301e-32 * fConst0);
	fConst283 = ((fConst0 * ((fConst0 * ((fConst0 * (fConst282 + -3.2564179121443601e-24)) + 3.9879477801707701e-21)) + 1.1350004519048499e-18)) + 1.7826268601057401e-18);
	double fConst284 = (4.2537276756392101e-23 * fConst0);
	fConst285 = (fConst0 * ((fConst0 * (6.0354236449383803e-22 - fConst284)) + 8.3640571178627402e-21));
	fConst286 = ((fConst1 * (-6.9638040646633403e-22 - (1.40284021168933e-33 * fConst1))) + 1.8833062707339401e-16);
	fConst287 = ((fConst1 * (-1.5951791120683101e-20 - (3.1882732083848299e-32 * fConst1))) + 7.1305074404229496e-18);
	fConst288 = ((fConst0 * ((fConst0 * ((fConst0 * ((fConst0 * (fConst280 + 6.0920499988829198e-26)) + 1.74095101616584e-22)) + -1.41975768707447e-17)) + 4.7082656768348503e-17)) + 5.8561986205838902e-16);
	fConst289 = ((fConst0 * ((fConst0 * ((fConst0 * (fConst282 + 3.2564179121443601e-24)) + 3.9879477801707701e-21)) + -1.1350004519048499e-18)) + 1.7826268601057401e-18);
	fConst290 = (fConst0 * ((fConst0 * (fConst284 + 6.0354236449383803e-22)) + -8.3640571178627402e-21));
	fConst291 = ((fConst0 * ((fConst1 * ((fConst0 * (-4.8736399991063297e-26 - fConst274)) + 3.4819020323316701e-22)) + -9.4165313536697006e-17)) + 4.6849588964671098e-16);
	fConst292 = ((fConst1 * ((fConst0 * (-2.6051343297154901e-24 - fConst276)) + 7.9758955603415402e-21)) + -3.5652537202114702e-18);
	fConst293 = (fConst1 * (1.20708472898768e-21 - fConst278));
	fConst294 = ((fConst0 * ((fConst0 * ((fConst0 * ((fConst0 * (fConst268 + 1.21840999977658e-26)) + -1.74095101616584e-22)) + 4.7325256235815704e-18)) + -4.7082656768348503e-17)) + 1.1712397241167799e-16);
	fConst295 = ((fConst0 * ((fConst0 * ((fConst0 * (fConst270 + 6.5128358242887097e-25)) + -3.9879477801707701e-21)) + 3.7833348396828302e-19)) + -1.7826268601057401e-18);
	fConst296 = (fConst0 * ((fConst0 * (fConst272 + -6.0354236449383803e-22)) + 2.7880190392875799e-21));
	fConst297 = (3.8841113779793501e-10 * fConst1);
	fConst298 = (7.7093564379726002e-10 * fConst1);
	double fConst299 = (3.8546782189863001e-10 * fConst0);
	fConst300 = (fConst299 + -3.8681053643969802e-10);
	double fConst301 = (1.9420556889896701e-10 * fConst0);
	fConst302 = (fConst301 + -9.6971419202025294e-11);
	fConst303 = (9.6971419202025294e-11 - fConst301);
	fConst304 = (fConst299 + 3.8681053643969802e-10);
	fConst305 = (fConst301 + 9.6971419202025294e-11);
	fConst306 = (-9.6971419202025294e-11 - fConst301);
	clear_state_f();
}

void always_inline Dsp::compute(int count, FAUSTFLOAT *input0, FAUSTFLOAT *output0)
{
#define fVslider0 (*fVslider0_)
#define fVslider1 (*fVslider1_)
#define fVslider2 (*fVslider2_)
#define fVslider3 (*fVslider3_)
#define fVslider4 (*fVslider4_)
#define fVslider5 (*fVslider5_)
	FAUSTFLOAT buf[smp.max_out_count(count)];
	int ReCount = smp.up(count, input0, buf);
	double fSlow0 = (0.00036676987543879196 * (std::exp((3.0 * double(fVslider0))) + -1.0));
	double fSlow1 = (0.0070000000000000062 * double(fVslider1));
	double fSlow2 = (0.0070000000000000062 * (1.0 - double(fVslider2)));
	double fSlow3 = (0.00036676987543879196 * (std::exp((3.0 * (1.0 - double(fVslider3)))) + -1.0));
	double fSlow4 = (0.0070000000000000062 * double(fVslider4));
	double fSlow5 = (0.00036676987543879196 * (std::exp((3.0 * double(fVslider5))) + -1.0));
	for (int i0 = 0; (i0 < ReCount); i0 = (i0 + 1)) {
		iVec0[0] = 1;
		fRec2[0] = ((9.9999999999999995e-21 * double((1 - iVec0[1]))) - fRec2[1]);
		fRec7[0] = ((double(buf[i0]) + fRec2[0]) - (fConst15 * (((((fConst17 * fRec7[1]) + (fConst19 * fRec7[2])) + (fConst20 * fRec7[3])) + (fConst21 * fRec7[4])) + (fConst22 * fRec7[5]))));
		fRec8[0] = (fSlow0 + (0.99299999999999999 * fRec8[1]));
		double fTemp0 = ((fConst0 * (fConst46 + (fConst47 * fRec8[0]))) + 5.7319572224284999e-18);
		fRec6[0] = ((fConst12 * ((((((fConst14 * fRec7[0]) + (fConst24 * fRec7[1])) + (fConst26 * fRec7[2])) + (fConst27 * fRec7[3])) + (fConst28 * fRec7[4])) + (fConst29 * fRec7[5]))) - ((((((fRec6[1] * ((fConst0 * (fConst31 + (fConst33 * fRec8[0]))) + 2.8659786112142497e-17)) + (fRec6[2] * ((fConst0 * (fConst35 + (fConst37 * fRec8[0]))) + 5.7319572224284994e-17))) + (fRec6[3] * ((fConst0 * (fConst38 + (fConst39 * fRec8[0]))) + 5.7319572224284994e-17))) + (fRec6[4] * ((fConst0 * (fConst40 + (fConst41 * fRec8[0]))) + 2.8659786112142497e-17))) + (fRec6[5] * ((fConst0 * (fConst43 + (fConst45 * fRec8[0]))) + 5.7319572224284999e-18))) / fTemp0));
		double fTemp1 = (fConst1 * (((((((fRec6[0] * (fConst49 + (fConst51 * fRec8[0]))) + (fRec6[1] * (fConst53 + (fConst55 * fRec8[0])))) + (fRec6[2] * (fConst57 + (fConst59 * fRec8[0])))) + (fRec6[3] * (fConst60 + (fConst61 * fRec8[0])))) + (fRec6[4] * (fConst62 + (fConst63 * fRec8[0])))) + (fRec6[5] * (fConst64 + (fConst65 * fRec8[0])))) / fTemp0));
		double fTemp2 = (142.143 * std::fabs(fTemp1));
		int iTemp3 = int(fTemp2);
		double fTemp4 = double(iTemp3);
		double fThen0 = ((ftbl0mydspSIG0[iTemp3] * (fTemp4 + (1.0 - fTemp2))) + ((fTemp2 - fTemp4) * ftbl0mydspSIG0[(iTemp3 + 1)]));
		double fThen1 = ((iTemp3 > 198) ? fConst66 : fThen0);
		fRec5[0] = ((std::fabs(((iTemp3 < 0) ? fConst67 : fThen1)) * double(((fTemp1 < 0.0) ? -1 : 1))) - (fConst68 * ((((((fConst70 * fRec5[1]) + (fConst72 * fRec5[2])) + (fConst73 * fRec5[3])) + (fConst74 * fRec5[4])) + (fConst75 * fRec5[5])) + (fConst76 * fRec5[6]))));
		fRec4[0] = ((fConst7 * (((((((fConst9 * fRec5[0]) + (fConst78 * fRec5[1])) + (fConst80 * fRec5[2])) + (fConst81 * fRec5[3])) + (fConst82 * fRec5[4])) + (fConst83 * fRec5[5])) + (fConst84 * fRec5[6]))) - (fConst85 * fRec4[1]));
		fRec9[0] = (fSlow1 + (0.99299999999999999 * fRec9[1]));
		fRec10[0] = (fSlow2 + (0.99299999999999999 * fRec10[1]));
		double fTemp5 = ((fConst0 * (fConst140 + ((fRec9[0] * (fConst141 + ((fRec9[0] * (fConst142 + (fConst0 * (fRec10[0] * (fConst143 + (fConst144 * fRec10[0])))))) + (fConst0 * (fRec10[0] * (fConst145 + (fConst146 * fRec10[0]))))))) + (fRec10[0] * (fConst147 + (fConst148 * fRec10[0])))))) + 9.0824829748189304e-07);
		fRec3[0] = ((fConst4 * (fRec4[0] + fRec4[1])) - (((((fRec3[1] * ((fConst0 * (fConst87 + ((fRec9[0] * (fConst89 + ((fRec9[0] * (fConst91 + (fConst1 * (fRec10[0] * (fConst93 + (fConst95 * fRec10[0])))))) + (fConst1 * (fRec10[0] * (fConst97 + (fConst99 * fRec10[0]))))))) + (fRec10[0] * (fConst101 + (fConst103 * fRec10[0])))))) + 3.6329931899275701e-06)) + (fRec3[2] * ((fConst1 * (fConst104 + ((fRec9[0] * (fConst105 + ((fRec9[0] * (fConst106 + (fRec10[0] * (fConst107 + (fConst108 * fRec10[0]))))) + (fRec10[0] * (fConst109 + (fConst110 * fRec10[0])))))) + (fRec10[0] * (fConst111 + (fConst112 * fRec10[0])))))) + 5.4494897848913602e-06))) + (fRec3[3] * ((fConst0 * (fConst113 + ((fRec9[0] * (fConst114 + ((fRec9[0] * (fConst115 + (fConst1 * (fRec10[0] * (fConst116 + (fConst117 * fRec10[0])))))) + (fConst1 * (fRec10[0] * (fConst118 + (fConst119 * fRec10[0]))))))) + (fRec10[0] * (fConst120 + (fConst121 * fRec10[0])))))) + 3.6329931899275701e-06))) + (fRec3[4] * ((fConst0 * (fConst123 + ((fRec9[0] * (fConst125 + ((fRec9[0] * (fConst127 + (fConst0 * (fRec10[0] * (fConst129 + (fConst131 * fRec10[0])))))) + (fConst0 * (fRec10[0] * (fConst133 + (fConst135 * fRec10[0]))))))) + (fRec10[0] * (fConst137 + (fConst139 * fRec10[0])))))) + 9.0824829748189304e-07))) / fTemp5));
		fRec11[0] = (fSlow3 + (0.99299999999999999 * fRec11[1]));
		fRec12[0] = (fSlow4 + (0.99299999999999999 * fRec12[1]));
		double fTemp6 = (fRec12[0] * (fConst217 + (fConst219 * fRec11[0])));
		double fTemp7 = (fConst1 * (fRec12[0] * (fConst235 + (fConst236 * fRec11[0]))));
		double fTemp8 = (fRec12[0] * (fConst247 + (fConst248 * fRec11[0])));
		double fTemp9 = ((fConst0 * (fConst261 + ((fRec11[0] * (fConst262 + (fConst263 * fRec11[0]))) + (fConst1 * (fRec12[0] * (fConst265 + (fConst267 * fRec11[0]))))))) + 1.24601533024252e-15);
		fRec1[0] = ((fRec2[0] + ((((((fRec3[0] * ((fConst0 * (fConst150 + ((fRec9[0] * (fConst152 + ((fRec9[0] * (fConst154 + (fConst0 * (fRec10[0] * (fConst156 + (fConst157 * fRec10[0])))))) + (fConst0 * (fRec10[0] * (fConst159 + (fConst160 * fRec10[0]))))))) + (fRec10[0] * (fConst162 + (fConst163 * fRec10[0])))))) + 9.0823122286569797e-07)) + (fRec3[1] * ((fConst0 * (fConst165 + ((fRec9[0] * (fConst167 + ((fRec9[0] * (fConst169 + (fConst1 * (fRec10[0] * (fConst171 + (fConst172 * fRec10[0])))))) + (fConst1 * (fRec10[0] * (fConst174 + (fConst175 * fRec10[0]))))))) + (fRec10[0] * (fConst177 + (fConst178 * fRec10[0])))))) + 3.6329248914627902e-06))) + (fRec3[2] * ((fConst1 * (fConst179 + ((fRec9[0] * (fConst180 + ((fRec9[0] * (fConst181 + (fRec10[0] * (fConst183 + (fConst184 * fRec10[0]))))) + (fRec10[0] * (fConst186 + (fConst187 * fRec10[0])))))) + (fRec10[0] * (fConst189 + (fConst190 * fRec10[0])))))) + 5.4493873371941899e-06))) + (fRec3[3] * ((fConst0 * (fConst191 + ((fRec9[0] * (fConst192 + ((fRec9[0] * (fConst193 + (fConst1 * (fRec10[0] * (fConst194 + (fConst195 * fRec10[0])))))) + (fConst1 * (fRec10[0] * (fConst196 + (fConst197 * fRec10[0]))))))) + (fRec10[0] * (fConst198 + (fConst199 * fRec10[0])))))) + 3.6329248914627902e-06))) + (fRec3[4] * ((fConst0 * (fConst200 + ((fRec9[0] * (fConst201 + ((fRec9[0] * (fConst202 + (fConst0 * (fRec10[0] * (fConst203 + (fConst204 * fRec10[0])))))) + (fConst0 * (fRec10[0] * (fConst205 + (fConst206 * fRec10[0]))))))) + (fRec10[0] * (fConst207 + (fConst208 * fRec10[0])))))) + 9.0823122286569797e-07))) / fTemp5)) - (((((((fRec1[1] * ((fConst0 * (fConst210 + ((fRec11[0] * (fConst212 + (fConst214 * fRec11[0]))) + (fConst215 * fTemp6)))) + 7.4760919814551297e-15)) + (fRec1[2] * ((fConst0 * (fConst221 + ((fRec11[0] * (fConst223 + (fConst225 * fRec11[0]))) + (fConst1 * (fRec12[0] * (fConst228 + (fConst231 * fRec11[0]))))))) + 1.8690229953637799e-14))) + (fRec1[3] * ((fConst1 * (fConst232 + ((fRec11[0] * (fConst233 + (fConst234 * fRec11[0]))) + fTemp7))) + 2.4920306604850401e-14))) + (fRec1[4] * ((fConst0 * (fConst237 + ((fRec11[0] * (fConst238 + (fConst239 * fRec11[0]))) + (fConst1 * (fRec12[0] * (fConst241 + (fConst243 * fRec11[0]))))))) + 1.8690229953637799e-14))) + (fRec1[5] * ((fConst0 * (fConst244 + ((fRec11[0] * (fConst245 + (fConst246 * fRec11[0]))) + (fConst215 * fTemp8)))) + 7.4760919814551297e-15))) + (fRec1[6] * ((fConst0 * (fConst250 + ((fRec11[0] * (fConst252 + (fConst254 * fRec11[0]))) + (fConst1 * (fRec12[0] * (fConst257 + (fConst260 * fRec11[0]))))))) + 1.24601533024252e-15))) / fTemp9));
		fRec13[0] = (fSlow5 + (0.99299999999999999 * fRec13[1]));
		double fTemp10 = ((fConst0 * (fConst304 + (fRec13[0] * (fConst305 + (fConst306 * fRec13[0]))))) + 9.6971419202025294e-11);
		fRec0[0] = ((fConst0 * ((((((((fRec1[0] * (fConst269 + (fConst0 * ((fRec11[0] * (fConst271 + (fConst273 * fRec11[0]))) + (fConst1 * (fRec12[0] * (fConst264 + (fConst266 * fRec11[0])))))))) + (fRec1[1] * (fConst275 + (fConst0 * ((fRec11[0] * (fConst277 + (fConst279 * fRec11[0]))) + (fConst1 * fTemp6)))))) + (fRec1[2] * (fConst281 + (fConst0 * ((fRec11[0] * (fConst283 + (fConst285 * fRec11[0]))) + (fConst1 * (fRec12[0] * (fConst227 + (fConst230 * fRec11[0]))))))))) + (fConst0 * (fRec1[3] * (fConst286 + (fTemp7 + (fRec11[0] * (fConst287 + (fConst1 * (0.0 - (2.4141694579753499e-21 * fRec11[0])))))))))) + (fRec1[4] * (fConst288 + (fConst0 * ((fRec11[0] * (fConst289 + (fConst290 * fRec11[0]))) + (fConst1 * (fRec12[0] * (fConst240 + (fConst242 * fRec11[0]))))))))) + (fRec1[5] * (fConst291 + (fConst0 * ((fRec11[0] * (fConst292 + (fConst293 * fRec11[0]))) + (fConst1 * fTemp8)))))) + (fRec1[6] * (fConst294 + (fConst0 * ((fRec11[0] * (fConst295 + (fConst296 * fRec11[0]))) + (fConst1 * (fRec12[0] * (fConst256 + (fConst259 * fRec11[0]))))))))) / fTemp9)) - (((fRec0[1] * (((fRec13[0] * (0.0 - (fConst297 * (1.0 - fRec13[0])))) + 1.93942838404051e-10) - fConst298)) + (fRec0[2] * ((fConst0 * (fConst300 + (fRec13[0] * (fConst302 + (fConst303 * fRec13[0]))))) + 9.6971419202025294e-11))) / fTemp10));
		buf[i0] = FAUSTFLOAT((fConst1 * ((((fRec0[1] * (0.0 - (7.6526213381953903e-10 * fRec13[0]))) + (3.8263106690976998e-10 * (fRec13[0] * fRec0[0]))) + (3.8263106690976998e-10 * (fRec13[0] * fRec0[2]))) / fTemp10)));
		iVec0[1] = iVec0[0];
		fRec2[1] = fRec2[0];
		for (int j0 = 5; (j0 > 0); j0 = (j0 - 1)) {
			fRec7[j0] = fRec7[(j0 - 1)];
		}
		fRec8[1] = fRec8[0];
		for (int j1 = 5; (j1 > 0); j1 = (j1 - 1)) {
			fRec6[j1] = fRec6[(j1 - 1)];
		}
		for (int j2 = 6; (j2 > 0); j2 = (j2 - 1)) {
			fRec5[j2] = fRec5[(j2 - 1)];
		}
		fRec4[1] = fRec4[0];
		fRec9[1] = fRec9[0];
		fRec10[1] = fRec10[0];
		for (int j3 = 4; (j3 > 0); j3 = (j3 - 1)) {
			fRec3[j3] = fRec3[(j3 - 1)];
		}
		fRec11[1] = fRec11[0];
		fRec12[1] = fRec12[0];
		for (int j4 = 6; (j4 > 0); j4 = (j4 - 1)) {
			fRec1[j4] = fRec1[(j4 - 1)];
		}
		fRec13[1] = fRec13[0];
		fRec0[2] = fRec0[1];
		fRec0[1] = fRec0[0];
	}
	smp.down(buf, output0);
#undef fVslider0
#undef fVslider1
#undef fVslider2
#undef fVslider3
#undef fVslider4
#undef fVslider5
}


void Dsp::connect(uint32_t port,void* data)
{
	switch ((PortIndex)port)
	{
	case DIST: 
		fVslider0_ = static_cast<float*>(data); // , 0.5, 0.0, 1.0, 0.01 
		break;
	case HIGH: 
		fVslider1_ = static_cast<float*>(data); // , 0.5, 0.0, 1.0, 0.01 
		break;
	case LEVEL: 
		fVslider5_ = static_cast<float*>(data); // , 0.5, 0.0, 1.0, 0.01 
		break;
	case LOW: 
		fVslider2_ = static_cast<float*>(data); // , 0.5, 0.0, 1.0, 0.01 
		break;
	case MIDFREQ: 
		fVslider3_ = static_cast<float*>(data); // , 0.5, 0.0, 1.0, 0.01 
		break;
	case MIDDLE: 
		fVslider4_ = static_cast<float*>(data); // , 0.5, 0.0, 1.0, 0.01 
		break;
	default:
		break;
	}
}

Dsp *plugin() {
	return new Dsp();
}

void Dsp::del_instance(Dsp *p)
{
	delete p;
}
} // end namespace metalzone
