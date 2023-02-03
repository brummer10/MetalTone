
/*******************************************************************************
**************************** File generated by *********************************
********************************************************************************
 ./build-plug.py -i MetalZone.sch -b
*******************************************************************************/

// generated automatically
// DO NOT MODIFY!
declare id "metalzone";
declare name "metalzone";
declare category "Extern";
declare shortname "metalzone";
declare description "metalzone";

import("stdfaust.lib");

/*******************************************************************************
  * metalzone_p1 generated by dkbuiler from MetalZone_p1.sch
*******************************************************************************/

p0 = pre : fi.iir((b0/a0,b1/a0),(a1/a0)) with {
    LogPot(a, x) = ba.if(a, (exp(a * x) - 1) / (exp(a) - 1), x);
    Inverted(b, x) = ba.if(b, 1 - x, x);
    s = 0.993;
    fs = float(ma.SR);
    pre = _;


    b0 = 2.04615913707177e-5*fs;

    b1 = -2.04615913707177e-5*fs;

    a0 = 2.08284488165043e-5*fs + 0.000234456807793764;

    a1 = -2.08284488165043e-5*fs + 0.000234456807793764;
};

p1 = pre : fi.iir((b0/a0,b1/a0,b2/a0,b3/a0,b4/a0,b5/a0),(a1/a0,a2/a0,a3/a0,a4/a0,a5/a0)) with {
    LogPot(a, x) = ba.if(a, (exp(a * x) - 1) / (exp(a) - 1), x);
    Inverted(b, x) = ba.if(b, 1 - x, x);
    s = 0.993;
    fs = float(ma.SR);
    pre = _;


    b0 = fs*(fs*(fs*(2.60149822831355e-21*fs + 3.79021415680222e-16) + 6.23800285169196e-12) + 5.15549054919527e-10);

    b1 = fs*(fs*(fs*(-7.80449468494064e-21*fs - 3.79021415680222e-16) + 6.23800285169196e-12) + 1.54664716475858e-9);

    b2 = fs*(fs*(fs*(5.2029964566271e-21*fs - 7.58042831360445e-16) - 1.24760057033839e-11) + 1.03109810983905e-9);

    b3 = fs*(fs*(fs*(5.2029964566271e-21*fs + 7.58042831360445e-16) - 1.24760057033839e-11) - 1.03109810983905e-9);

    b4 = fs*(fs*(fs*(-7.80449468494064e-21*fs + 3.79021415680222e-16) + 6.23800285169196e-12) - 1.54664716475858e-9);

    b5 = fs*(fs*(fs*(2.60149822831355e-21*fs - 3.79021415680222e-16) + 6.23800285169196e-12) - 5.15549054919527e-10);

    a0 = fs*(fs*(fs*(fs*(2.4454389978744e-24*fs + 6.53471849041744e-20) + 2.54299345607219e-16) + 7.88935006893206e-13) + 1.26822396718671e-9) + 3.43703679632746e-7;

    a1 = fs*(fs*(fs*(fs*(-1.2227194989372e-23*fs - 1.96041554712523e-19) - 2.54299345607219e-16) + 7.88935006893206e-13) + 3.80467190156013e-9) + 1.71851839816373e-6;

    a2 = fs*(fs*(fs*(fs*(2.4454389978744e-23*fs + 1.30694369808349e-19) - 5.08598691214437e-16) - 1.57787001378641e-12) + 2.53644793437342e-9) + 3.43703679632746e-6;

    a3 = fs*(fs*(fs*(fs*(-2.4454389978744e-23*fs + 1.30694369808349e-19) + 5.08598691214437e-16) - 1.57787001378641e-12) - 2.53644793437342e-9) + 3.43703679632746e-6;

    a4 = fs*(fs*(fs*(fs*(1.2227194989372e-23*fs - 1.96041554712523e-19) + 2.54299345607219e-16) + 7.88935006893206e-13) - 3.80467190156013e-9) + 1.71851839816373e-6;

    a5 = fs*(fs*(fs*(fs*(-2.4454389978744e-24*fs + 6.53471849041744e-20) - 2.54299345607219e-16) + 7.88935006893206e-13) - 1.26822396718671e-9) + 3.43703679632746e-7;
};

p2 = pre : fi.iir((b0/a0,b1/a0,b2/a0,b3/a0,b4/a0,b5/a0),(a1/a0,a2/a0,a3/a0,a4/a0,a5/a0)) with {
    LogPot(a, x) = ba.if(a, (exp(a * x) - 1) / (exp(a) - 1), x);
    Inverted(b, x) = ba.if(b, 1 - x, x);
    s = 0.993;
    fs = float(ma.SR);
    pre = _;


    Dist = vslider("Dist[name:Dist][style:knob]", 0.5, 0, 1, 0.01) : Inverted(0) : LogPot(3) : si.smooth(s);

    b0 = Dist*pow(fs,2)*(fs*(fs*(1.13784372686602e-24*fs + 1.21855396824368e-18) + 8.58499400409908e-15) - 6.09123191579915e-30) + pow(fs,2)*(fs*(fs*(4.55137490746407e-27*fs + 2.76310904102951e-20) + 1.95978343740697e-16) + 1.71698163100351e-15);

    b1 = Dist*pow(fs,2)*(fs*(fs*(-5.68921863433009e-24*fs - 3.65566190473105e-18) - 8.58499400409908e-15) - 6.09123191579915e-30) + pow(fs,2)*(fs*(fs*(-2.27568745373204e-26*fs - 8.28932712308853e-20) - 1.95978343740697e-16) + 1.71698163100351e-15);

    b2 = Dist*pow(fs,2)*(fs*(fs*(1.13784372686602e-23*fs + 2.43710793648737e-18) - 1.71699880081982e-14) + 1.21824638315983e-29) + pow(fs,2)*(fs*(fs*(4.55137490746407e-26*fs + 5.52621808205902e-20) - 3.91956687481394e-16) - 3.43396326200701e-15);

    b3 = Dist*pow(fs,2)*(fs*(fs*(-1.13784372686602e-23*fs + 2.43710793648737e-18) + 1.71699880081982e-14) + 1.21824638315983e-29) + pow(fs,2)*(fs*(fs*(-4.55137490746407e-26*fs + 5.52621808205902e-20) + 3.91956687481394e-16) - 3.43396326200701e-15);

    b4 = Dist*pow(fs,2)*(fs*(fs*(5.68921863433009e-24*fs - 3.65566190473105e-18) + 8.58499400409908e-15) - 6.09123191579915e-30) + pow(fs,2)*(fs*(fs*(2.27568745373204e-26*fs - 8.28932712308853e-20) + 1.95978343740697e-16) + 1.71698163100351e-15);

    b5 = Dist*pow(fs,2)*(fs*(fs*(-1.13784372686602e-24*fs + 1.21855396824368e-18) - 8.58499400409908e-15) - 6.09123191579915e-30) + pow(fs,2)*(fs*(fs*(-4.55137490746407e-27*fs + 2.76310904102951e-20) - 1.95978343740697e-16) + 1.71698163100351e-15);

    a0 = Dist*(fs*(fs*(fs*(fs*(4.09145205062379e-24*fs + 8.24212664514929e-21) + 3.17729560581312e-19) + 2.93619011633722e-18) + 9.77259192888297e-23) - 3.85750837043159e-38) + fs*(fs*(fs*(fs*(1.63658082024952e-26*fs + 8.18620095190564e-20) + 1.63752260202535e-16) + 4.18188856565759e-15) + 2.60543994858159e-14) + 8.67173312581635e-19;

    a1 = Dist*(fs*(fs*(fs*(fs*(-2.0457260253119e-23*fs - 2.47263799354479e-20) - 3.17729560581312e-19) + 2.93619011633722e-18) + 2.93177757866489e-22) - 1.92875418521579e-37) + fs*(fs*(fs*(fs*(-8.18290410124758e-26*fs - 2.45586028557169e-19) - 1.63752260202535e-16) + 4.18188856565759e-15) + 7.81631984574476e-14) + 4.33586656290817e-18;

    a2 = Dist*(fs*(fs*(fs*(fs*(4.09145205062379e-23*fs + 1.64842532902986e-20) - 6.35459121162625e-19) - 5.87238023267445e-18) + 1.95451838577659e-22) - 3.85750837043159e-37) + fs*(fs*(fs*(fs*(1.63658082024952e-25*fs + 1.63724019038113e-19) - 3.27504520405069e-16) - 8.36377713131518e-15) + 5.21087989716317e-14) + 8.67173312581635e-18;

    a3 = Dist*(fs*(fs*(fs*(fs*(-4.09145205062379e-23*fs + 1.64842532902986e-20) + 6.35459121162625e-19) - 5.87238023267445e-18) - 1.95451838577659e-22) - 3.85750837043159e-37) + fs*(fs*(fs*(fs*(-1.63658082024952e-25*fs + 1.63724019038113e-19) + 3.27504520405069e-16) - 8.36377713131518e-15) - 5.21087989716317e-14) + 8.67173312581635e-18;

    a4 = Dist*(fs*(fs*(fs*(fs*(2.0457260253119e-23*fs - 2.47263799354479e-20) + 3.17729560581312e-19) + 2.93619011633722e-18) - 2.93177757866489e-22) - 1.92875418521579e-37) + fs*(fs*(fs*(fs*(8.18290410124758e-26*fs - 2.45586028557169e-19) + 1.63752260202535e-16) + 4.18188856565759e-15) - 7.81631984574476e-14) + 4.33586656290817e-18;

    a5 = Dist*(fs*(fs*(fs*(fs*(-4.09145205062379e-24*fs + 8.24212664514929e-21) - 3.17729560581312e-19) + 2.93619011633722e-18) - 9.77259192888297e-23) - 3.85750837043159e-38) + fs*(fs*(fs*(fs*(-1.63658082024952e-26*fs + 8.18620095190564e-20) - 1.63752260202535e-16) + 4.18188856565759e-15) - 2.60543994858159e-14) + 8.67173312581635e-19;
};

anti_denormal = pow(10,-20);

anti_denormal_ac = 1 - 1' : *(anti_denormal) : + ~ *(-1);

process = +(anti_denormal_ac) : p0 : p1 : p2;