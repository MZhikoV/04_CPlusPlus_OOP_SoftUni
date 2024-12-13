#ifndef sumofvectors_h
#define sumofvectors_h

#include <vector>
#include <string>

using namespace std;

vector<string> operator+(const vector<string> & vec1, const vector<string> & vec2) {
    vector<string> res;
    int size=vec1.size();
   
    for (int i=0; i<size; i++ ) {
        res[i]=vec1[i]+' '+vec2[i];
    };

    return res;   
};


#endif