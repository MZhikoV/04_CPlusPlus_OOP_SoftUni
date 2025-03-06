#pragma once

#ifndef SUM_H
#define SUM_H


#include <vector>
#include <string>

std::vector<std::string> operator + (const std::vector<std::string> & firstV, const std::vector<std::string>& secV)
{
    std::vector<std::string> result;
    for (int i = 0; i < firstV.size(); i++)
    {
        std::string temp = firstV[i] + secV[i];
        result.push_back(temp);
    }
    return result;
}



#endif