#include "csinterplot.h"

void gen_mcc_infile(const string& spname, const double num_cs, int de)
{
    ofstream omcc("csection.in");

}
void gen_reaction_infile(const string& spname, const double num_cs, 
                         const int de, const int ntype, double* th)
{
    vector<Real> energy(num_cs), cs_info(ntype);
    vector<vector<Real>> cs_arr;
}