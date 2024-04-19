#ifndef field_h
#define field_h

#include <iostream>
#include <vector> //todo

#include "Defines.h"

class Field {

//std::vector<std::string> battlefield;

public:

    std::vector<std::string> battlefield;

    void populateField(const std::vector<std::string> & fieldData) {
    battlefield=fieldData;
    };

    std::vector<std::string> getFieldData()  {
        return battlefield;
    };
};

#endif