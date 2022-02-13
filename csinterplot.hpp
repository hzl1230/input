#ifndef _CSPLOT_
#define _CSPLOT_
#include <iostream>
#include <fstream>
#include <vector>
#include <string>
using namespace std;
typedef double Real;

static double n0, Te0;

const double     PI             = 3.141592653589793;      // mathematical constant Pi
const double     TWO_PI         = 2.0 * PI;               // two times Pi
const double     E_CHARGE       = 1.60217662e-19;         // electron charge [C]
const double     E_MASS         = 9.10938356e-31;         // mass of electron [kg]
const double     AR_MASS        = 6.63352090e-26;         // mass of argon atom [kg]
const double     K_BOLTZMANN    = 1.38064852e-23;         // Boltzmann's constant [J/K]
const double     EPSILON0       = 8.85418781e-12;         // permittivity of free space [F/m]

void gen_mcc_infile(const string& spname, const double num_cs, int de);
void gen_reaction_infile(const string& spname, const double num_cs, const int de, const int ntype, double* th);
void gen_particle_infile();
void gen_mesh_infile();
void gen_control_infile();

#endif