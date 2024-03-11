#ifndef OPERATORS_H
#define OPERATORS_H

#include <ostream>
#include <vector>
#include <string>
#include <sstream>

using namespace std;

vector<string>  & operator << (vector<string> & outpVector,const string & inp1) {
    outpVector.push_back(inp1);
    return outpVector;
}

string operator + (const string & leftSideString, const int & element) {
    ostringstream numToString;
    numToString<<element;

    string resultString=leftSideString+numToString.str();

    return resultString;
}

ostream & operator << (ostream & out,const vector<string> & inpVector) {
   string resultStr;
    for (size_t indx=0; indx<inpVector.size();indx++) {
        out<<inpVector[indx]<<endl;
    }
    return out;
};

// Place your code here

#endif // !OPERATORS_H
