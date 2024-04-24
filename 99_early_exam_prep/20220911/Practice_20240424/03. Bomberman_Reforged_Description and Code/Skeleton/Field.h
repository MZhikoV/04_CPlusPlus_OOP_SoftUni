#ifndef field_hh
#define field_hh

#include "Defines.h"


class Field {

    FieldData battlefield;

public:
    Field()=default;

    void populateField(const FieldData & data) {
        battlefield=data;
    };

    FieldData getFieldData() const {
        return battlefield;
    }

//populateField
//populateField(fieldData)
//using FieldData = std::vector<std::string>;


};





#endif