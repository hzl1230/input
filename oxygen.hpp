#include "csinterplot.h"

static Real e_O2_th[15], e_O2+_th[1], e_O-_th[1];
static Real O-_O2+[1], O-_O2_th[2], O2+_O2_th[1];

Real e_O2_elastic(Real e, Real th = 0.);
Real e_O2_vibration_v1(Real e, Real th = 0.19);
Real e_O2_vibration_v2(Real e, Real th = 0.38);
Real e_O2_vibration_v3(Real e, Real th = 0.57);
Real e_O2_vibration_v4(Real e, Real th = 0.75);
Real e_O2_rotational(Real e, Real th = 0.02);
Real e_O2_excitation_a(Real e , Real th = 0.997);
Real e_O2_excitation_b(Real e , Real th = 1.627);
Real e_O2_excitation_c(Real e , Real th = 4.5);
Real e_O2_diss_attech(Real e, Real th = 4.2);
Real e_O2_diss_3p3p(Real e, Real th = 6.0);
Real e_O2_diss_3p1d(Real e, Real th = 8.4);
Real e_O2_diss_1d1d(Real e, Real th = 9.97);
Real e_O2_ionization(Real e, Real th = 12.06);
Real e_O2_diss_excitation(Real e , Real th = 14.7);


Real e_O2_elastic(Real energy, Real th = 0.)
{
    Real temp1, temp2, temp3;
    Real temp4, temp5;

    if(0.0 <= energy && energy <= 1.2)
    {
        temp1 = energy*energy;
        temp2 = energy*temp1;
        temp3 = energy*temp2;
        
        temp5 = -12.6132*temp3 +39.2258*temp2 -43.3875*temp1 +23.5722*energy +.4464;
        temp5 *= 1e-20;
    }
    else if(1.2 < energy && energy <= 20.)
    {
        temp1 = energy*energy;
        temp2 = energy*temp1;
        temp3 = energy*temp2;
        temp4 = energy*temp3;
        
        temp5 = -4.0554e-5*temp4 +2.7604e-3*temp3 -.07107*temp2 +.82961*temp1 -3.9163*energy +11.735;
        temp5 *= 1e-20;
    }
    else if(20 < energy && energy <= 100.)
    {
        temp1 = energy*energy;
        temp5 = 1.3874e-4*temp1 -.0417*energy +9.254364;
        temp5 *= 1e-20;
    }
    else temp5= 6.5e-20;

    return temp5;
}

Real e_O2_vibration_v1(Real energy, Real th = 0.19)
{
    Real temp1, temp2, temp3;
    Real temp4, temp5, temp6;

    temp6= 0.0;
    if(.19 <= energy && energy <= 1.0) {
        temp1 = energy*energy;
        temp2 = energy*temp1;
        temp3 = energy*temp2;
        temp4 = energy*temp3;
        
        temp6 = -1.508395*temp4 +6.521786*temp3 -9.574636*temp2 +5.092031*temp1 -0.41602*energy -0.066398;
        temp6 *= 1e-20;
        if(temp6 <= 0.0) temp6=0.0;
    }
    else if(1.0 < energy && energy <= 1.67) temp6 = -7.2193e-22*(energy -1.67);
    else if(4.0 <= energy && energy <= 5.5) temp6 = 4.572852e-22*(energy -4.0);
    else if(5.5 < energy && energy <= 16.0)
    {
        temp1 = energy*energy;
        temp2 = energy*temp1;
        temp3 = energy*temp2;
        temp4 = energy*temp3;
        temp5 = energy*temp4;
        
        temp6 = 1.0835e-6*temp5 -9.229e-5*temp4 +0.0030853*temp3 -0.050981*temp2 +0.427934*temp1 -1.6682*energy +2.3919;
        temp6 *= 1e-20;
        if(temp6 <= 0.0) temp6=0.0;
    }
    else if(16.0 < energy && energy <= 25.0) temp6 = -4.098144e-23*(energy -25.0);

    return(temp6);
}

Real e_O2_vibration_v2(Real e, Real th = 0.38)
{
    Real temp1, temp2, temp3;
    Real temp4, temp5;

    temp5= 0.0;
    if(.38 <= energy && energy <= 1.67)
    {
        temp1 = energy*energy;
        temp2 = energy*temp1;
        temp3 = energy*temp2;
        
        temp5 = -0.606022*temp3 +3.157773*temp2 -5.933895*temp1 +4.664064*energy -1.233443;
        temp5 *= 1e-20;
        if(temp5 <= 0.0) temp5=0.0;
    }
    else if(4.0 <= energy && energy <= 14.5)
    {
        temp1 = energy*energy;
        temp2 = energy*temp1;
        temp3 = energy*temp2;
        temp4 = energy*temp3;
        
        temp5 = -3.1339358e-6*temp4 +2.0994236e-4*temp3 -.00503577*temp2 +0.0515*temp1 -0.2074798*energy +0.279;
        temp5 *= 1e-20;
        if(temp5 <= 0.0) temp5=0.0;
    }
    else if(14.5 < energy && energy <= 25.0) temp5 = -1.71326e-23*(energy -25.0);

    return(temp5);
}

Real e_O2_vibration_v3(Real e, Real th = 0.57)
{
    Real temp1, temp2, temp3;
    Real temp4, temp5;

    temp5= 0.0;
    if(.57 <= energy && energy <= 1.67)
    {
        temp1 = energy*energy;
        
        temp5 = -.055083*temp1 +.12457*energy -.057531;
        temp5 *= 1e-20;
        if(temp5 <= 0.0) temp5=0.0;
    }
    else if(4.0 <= energy && energy <= 15.0)
    {
        temp1 = energy*energy;
        temp2 = energy*temp1;
        temp3 = energy*temp2;
        temp4 = energy*temp3;
        
        temp5 = -7.969385e-6*temp4 +4.78119632e-4*temp3 -.0107124*temp2 +0.1095564*temp1 -0.4962553*energy +0.80444;
        temp5 *= 1e-20;
        if(temp5 <= 0.0) temp5=0.0;
    }
    else if(15.0 < energy && energy <= 20.0) temp5 = -1.76e-23*(energy -20.0);

    return(temp5);
}

Real e_O2_vibration_v4(Real e, Real th = 0.75)
{
    Real temp1, temp2, temp3, temp6;

    temp6= 0.0;
    if(.75 <= energy && energy <= 0.85) temp6 = 2.795e-25*(energy - 0.75);
    
    else if(.85 <= energy && energy <= 1.67)
    {
        temp1 = energy*energy;
        temp2 = energy*temp1;
        
        temp6 = -0.049346*temp2 +0.16616*temp1 -0.174061*energy +0.058213;
        temp6 *= 1e-20;
        if(temp6 <= 0.0) temp6=0.0;
    }
    else if(6.0 <= energy && energy <= 15.0)
    {
        temp1 = energy*energy;
        temp2 = energy*temp1;
        temp3 = energy*temp2;
        
        temp6 = -1.3846154e-5*temp3 +8.8449e-4*temp2 -0.020271*temp1 +0.19111*energy -0.589505;
        temp6 *= 1e-20;
        if(temp6 <= 0.0) temp6=0.0;
    }
    return(temp6);
}

Real e_O2_rotational(Real e, Real th = 0.02)
{
    Real temp1, temp2, temp3;
    Real temp4, temp5, temp6;

    temp6= 0.0;
    if(.07 <= energy && energy <= 1.67)
    {
        temp1 = energy*energy;
        temp2 = energy*temp1;
        temp3 = energy*temp2;
        temp4 = energy*temp3;
        temp5 = energy*temp4;
        
        temp6 = -.0859*temp5 +.4233*temp4 -.7366*temp3 +.5205*temp2 -.1537*temp1 +.0604*energy -.0022;
        temp6 *= 1e-20;
    }
    return(temp6);
}

Real e_O2_excitation_a(Real e , Real th = 0.997)
{
    Real temp1, temp2, temp3;
    Real temp4, temp5;

    temp5= 0.0;
    if(0.977 <= energy && energy <= 10.5)
    {
        temp1 = energy*energy;
        temp2 = energy*temp1;
        temp3 = energy*temp2;
        temp4 = energy*temp3;
        
        temp5 = -3.0913e-6*temp4 +1.436e-4*temp3 -.0022876*temp2 +.0133286*temp1 -.0100266*energy -.0015636;
        temp5 *= 1e-20;
        if(temp5 <= 0.0) temp5=0.0;
    }
    else if(10.5 < energy && energy <= 45.0)
    {
        temp1 = energy*energy;
        temp2 = energy*temp1;

        temp5 = -1.0959e-6*temp2 +1.349e-4*temp1 -.005984*energy +.1079;
        temp5 *= 1e-20;
    }
    else if(45 < energy && energy <= 100.0)
    {
        temp5 = -2.18e-4*energy +2.18e-2;
        temp5 *= 1e-20;
    }
    return(temp5);
}

Real e_O2_excitation_b(Real e , Real th = 1.627)
{
    Real temp1, temp2, temp3;
    Real temp4, temp5;

    temp5= 0.0;
    if(1.627 <= energy && energy <= 25.0)
    {
        temp1 = energy*energy;
        temp2 = energy*temp1;
        temp3 = energy*temp2;
        temp4 = energy*temp3;
        
        temp5 = 5.34245e-8*temp4 -4.7117e-6*temp3 +1.581e-4*temp2 -2.4783e-3*temp1 +1.70373e-2*energy -2.2343e-2;
        temp5 *= 1e-20;
        if(temp5 <= 0.0) temp5=0.0;
    }
    else if(25.0 < energy && energy <= 45.0)
    {
        temp1 = energy*energy;
        temp2 = energy*temp1;

        temp5 = 5.445e-7*temp2 -5.674e-5*temp1 +1.7502e-3*energy -1.0375e-2;
        temp5 *= 1e-20;
    }
    else if(45 < energy && energy <= 100.0)
    {
        temp5 = -5.64e-5*energy +5.64e-3;
        temp5 *= 1e-20;
    }
    return(temp5);
}

Real e_O2_excitation_c(Real e , Real th = 4.5)
{
    Real temp1, temp2;
    Real temp5;

    temp5= 0.0;
    if(4.5 <= energy && energy <= 4.8)
    {
        temp5 = 0.01*energy -.045;
        temp5 *= 1e-20;
    }
    else if(4.8 < energy && energy <= 15.0)
    {
        temp1 = energy*energy;
        temp2 = energy*temp1;

        temp5 = 6.113e-4*temp2 -2.11e-2*temp1 +.2216*energy -.638556;
        temp5 *= 1e-20;
    }
    return(temp5);
}

Real e_O2_diss_attech(Real e, Real th = 4.2);
{
    register int i;
    Real detach_sigma;
    static int init_flag=1;
    static Real *detach1, *detach2;
    
    /********  Initialization  ********/
    if(init_flag) {
        Real engy;
        detach1 = (Real *) malloc(150*sizeof(Real));
        detach2 = (Real *) malloc(100*sizeof(Real));
        
        for(i=0; i<150; i++) {
        engy = 0.1*i;
        if(engy <= 7.0)
        detach1[i] = 1.4064e-22*exp(-(engy -6.5)*(engy -6.5)/1.1766);
        else if(7.0 <engy && engy <=15.0)
        detach1[i] = 9.0e-24 -6.0e-25*engy +1.4064e-22*exp(-(engy -6.5)*(engy -6.5)/1.1766);
        }
        for(i=0; i<100; i++) {
        engy = i;
        if(engy <15.0)
        detach2[i] = 0.0;
        else if(15.0<=engy && engy <31.0) 
        detach2[i] = 4.66e-23*exp(-(engy -30.0)*(engy -30.0)/50.0);
        else
        detach2[i] = 5.1745e-23 -1.96e-25*engy; 
        }
        init_flag=0;
    }

    if(energy < 15.0) {
        i= energy*10 +0.5;
        detach_sigma = detach1[i];
    }
    else {
        i = energy;
        if(i >= 100) i = 99;
        detach_sigma = detach2[i];
    }
    return(detach_sigma);
}

Real e_O2_diss_3p3p(Real e, Real th = 6.0)
{
    Real temp1, temp2, temp3;
    Real temp5;

    temp5= 0.0;
    if(6.0<= energy && energy <= 20.)
    {
        temp1 = energy*energy;
        temp2 = energy*temp1;
        temp3 = energy*temp2;

        temp5 = -1.1894e-4*temp3 +6.8655e-3*temp2 -.143425*temp1 +1.26276*energy -3.7338513;
        temp5 *= 1e-20;
        if(temp5 <= 0.0) temp5=0.0;
    }
    else if(20. < energy && energy <= 100.)
    {
        temp1 = energy*energy;

        temp5 = 9.9341e-6*temp1 -1.7857e-3*energy +7.924e-2;
        temp5 *= 1e-20;
        if(temp5 <= 0.0) temp5=0.0;
    }
    return(temp5);
}

Real e_O2_diss_3p1d(Real e, Real th = 8.4)
{
    Real temp1, temp5;

    temp5= 0.0;
    if(8.4<= energy && energy <= 9.4)
    {
        temp5 = energy -8.4;
        temp5 *= 1e-20;
        if(temp5 <= 0.0) temp5=0.0;
    }
    else if(9.4 < energy && energy <= 100.)
    {
        temp1 = energy*energy;

        temp5 = -1.08852e-4*temp1 +1.10145e-2*energy +.92302246;
        temp5 *= 1e-20;
        if(temp5 <= 0.0) temp5=0.0;
    }
    else if(100. < energy) temp5 = 9.4e-21;
    return(temp5);
}

Real e_O2_diss_1d1d(Real e, Real th = 9.97)
{
    Real temp1, temp2, temp3;
    Real temp5;

    temp5= 0.0;
    if(10. <= energy && energy <= 100.)
    {
        temp1 = energy*energy;
        temp2 = energy*temp1;
        temp3 = energy*temp2;

        temp5 = 1.1656e-9*temp3 -3.1555e-7*temp2 +1.8544e-5*temp1 +9.464e-4*energy -.0110422;
        temp5 *= 1e-20;
        if(temp5 <= 0.0) temp5=0.0;
    }
    else if(100. < energy) temp5= 7e-22;
    
    return (temp5);
}

Real e_O2_ionization(Real e, Real th = 12.06)
{
    Real temp1, temp2, temp3;
    Real temp5;

    temp5= 0.0;
    if(12.06 <= energy && energy <= 100.)
    {
        temp1 = energy*energy;
        temp2 = energy*temp1;
        temp3 = energy*temp2;

        temp5 = 8.035e-8*temp3 -1.594e-5*temp2 +5.1392e-4*temp1 +.0658*energy -.89892;
        temp5 *= 1e-20;
        if(temp5 <= 0.0) temp5=0.0;
    }
    else if(100. < energy) temp5= 2.9e-20;
    
    return(temp5);
}

Real e_O2_diss_excitation(Real e , Real th = 14.7)
{
    Real temp1, temp2;
    Real temp5;

    temp5= 0.0;
    if(14.7<= energy && energy <= 100.)
    {
        temp1 = energy*energy;
        temp2 = energy*temp1;

        temp5 = 1.21665e-7*temp2 -3.0483e-5*temp1 +2.51713e-3*energy -.030335;
        temp5 *= 1e-20;
        if(temp5 <= 0.0) temp5=0.0;
    }
    else if(100. < energy) temp5= 3.8e-22;
    
    return(temp5);
}