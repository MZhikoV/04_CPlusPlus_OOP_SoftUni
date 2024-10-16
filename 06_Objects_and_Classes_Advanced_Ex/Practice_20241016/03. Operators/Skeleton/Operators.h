#ifndef opp_h
#define opp_h

#include <vector>
#include <string>
#include <sstream>

std::vector<std::string>& operator<<(std::vector<std::string>& inp, const std::string& a) {
    inp.push_back(a);
    return inp;
};

std::string operator+(const std::string & currState, const int a) {
    std::ostringstream ostr;
    ostr<<currState<<a;
    return ostr.str();
}

void operator<<(std::ostream& out, const std::vector<std::string>& data ) {
    //std::ostringstream ostr;
    for (int i=0; i<data.size(); i++) {
        out<<data[i]<<std::endl;
    };
    //return ostr.str();
};



#endif