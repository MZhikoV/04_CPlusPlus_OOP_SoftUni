#ifndef SumOfVectors_h
#define SumOfVectors_h

#include <vector>
#include <string>

using namespace std;

vector<string> operator+(const vector<string> & a, const vector<string> & b) {
    int maxSize=0;
    if(a.size()>b.size()) {
        maxSize=a.size();
    }
    else {
        maxSize=b.size();
    };

    vector<string> result;
    for (int i=0;i<maxSize; i++) {
        result.push_back(a[i]+' '+b[i]);
    };

    return result;
}


#endif