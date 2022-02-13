#include "csinterplot.hpp"

static Real th[];
void e_O2_elastic(Real e, Real th = 0.);
void e_O2_vibration_v1(Real e, Real th = 0.19);
void e_O2_vibration_v2(Real e, Real th = 0.38);
void e_O2_vibration_v3(Real e, Real th = 0.57);
void e_O2_vibration_v4(Real e, Real th = 0.75);
void e_O2_rotational(Real e, Real th = 0.02);
void e_O2_excitation_a(Real e , Real th = 0.997);
void e_O2_excitation_b(Real e , Real th = 1.627);
void e_O2_excitation_c(Real e , Real th = 4.5);
void e_O2_diss_attech(Real e, Real th = 4.2);

