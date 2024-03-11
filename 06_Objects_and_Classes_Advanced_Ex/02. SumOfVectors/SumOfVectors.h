#ifndef SUMOFVECTORS_H
#define SUMOFVECTORS_H


#include <iostream>
#include <string>
#include <sstream>
#include <map>
#include <set>
#include <vector>
#include <algorithm>
#include <queue>
#include <stack>

using namespace std;

vector <string> operator+(const vector<string> & vector1,const vector<string> & vector2) {
    vector<string> resultVector;
    for (int i=0;i<vector1.size();i++){
    string resultString=vector1[i]+' '+vector2[i];
    resultVector.push_back(resultString);
    }
    return resultVector;
}

#endif // !SUMOFVECTORS_H