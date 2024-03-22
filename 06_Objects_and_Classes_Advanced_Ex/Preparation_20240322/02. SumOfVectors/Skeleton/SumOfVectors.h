#ifndef SUMOFVECTORS_H
#define SUMOFVECTORS_H

#include <sstream>
#include <string>
#include <vector>

using namespace std;



vector<string> operator+(const vector<string> & a, const vector<string> & b) {
    vector<string>result;
    result.reserve(a.size());

    for (size_t idx=0; idx<a.size(); idx++) {
    ostringstream outp;
    outp<<a[idx]<<' '<<b[idx];
    result.push_back(outp.str());
    };
    return result;
};


#endif