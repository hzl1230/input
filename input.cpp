#include <iostream>
#include <fstream>
#include <json/json.h>
#include "csinterplot.hpp"
using namespace std;

int main(int argc, char **argv)
{
    int ncs;
    double de;
    Json::Reader reader;
    Json::Value input;
    ifstream in("input.json", ios::binary);
    if(reader.parse(in, input)) {
        ncs = input["mcc"]["cs_number"].asInt();
        de = input["mcc"]["cs_de"].asDouble();
        cout << ncs << " " << de << endl;
    }
    else {
        cout << "--------->Input Error<----------" << endl;
    }

    return 0;
}