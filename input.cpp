#include <json/json.h>
#include "csinterplot.hpp"
using namespace std;

int main(int argc, char **argv)
{
    Json::Reader reader;
    Json::Value input;
    ifstream in("input.json", ios::binary);
    if(reader.parse(in, input)) {
        const double Te0 = input["non_dim"]["Te0"].asDouble();
        const double n0 = input["non_dim"]["n0"].asDouble();
        int ncs; double de;
        string spec_name;
        spec_name = input["mcc"]["species"].asString();
        ncs = input["mcc"]["cs_number"].asInt();
        de = input["mcc"]["cs_de"].asDouble();
        cout << spec_name << " " << ncs << " " << de << endl;

    }
    else {
        cout << "--------->Input Error<----------" << endl;
    }

    return 0;
}