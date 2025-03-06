#pragma once

#ifndef operator_h
#define operator_h

#include <vector>
#include <string>
#include <sstream>

std::vector<std::string> & operator<<(std::vector<std::string> & outp, const std::string & inp)
{
    outp.push_back(inp);
    return outp;
}

std::string operator+ (std::string & outp, const int& inp)
{
    std::string result = outp + std::to_string(inp);
    return result;
}

void operator<<(std::ostream& ostr, std::vector<std::string>& inp)
{
    for (auto curr:inp)
    {
        ostr<<curr<<std::endl;
    }
}




#endif