#ifndef JOIN_HH
#define JOIN_HH

#include <iostream>
#include <sstream>
#include <vector>
#include <string>

using namespace std;

template <typename T> string join(const vector<T> & output, const string & joinCh) {
    ostringstream ostr;
            bool isFirst=true;
    for (size_t i=0; i<output.size(); i++) {

    if (isFirst) {
        isFirst=false;
    }
    else {
        ostr<<joinCh;
    }
        ostr<<output[i];
    };
    return ostr.str();
};


#endif