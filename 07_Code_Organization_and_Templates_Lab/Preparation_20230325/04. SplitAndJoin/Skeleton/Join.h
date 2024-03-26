#ifndef JOIN_H
#define JOIN_H


#include <vector>
#include <string>
#include <sstream>


template <typename T> std::string join(const std::vector<T> & numbers, const std::string & separator){
    std::ostringstream ostr;

    bool isFirst=true;

    for (const T & elem:numbers) {
        if (isFirst) {
            isFirst=false;
        }
        else {
            ostr<<separator;
        }
        ostr<<elem;
    };
    return ostr.str();
}



#endif