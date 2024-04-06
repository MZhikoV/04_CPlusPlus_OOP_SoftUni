#ifndef SERIALIZEE_H
#define SERIALIZEE_H

#include <string>

#include "Company.h"

#include <vector>
#include <sstream>


class SerializableCompany:public Company {
    public:

        void serialize(std::vector<byte> & output) const {
            serializeId(output);
            serializeName(output);
            serializeEmployees(output);
        };

    protected:

        void serializeId(std::vector<byte> & output) const {
            output.push_back((byte)getId());
        };

        void serializeName(std::vector<byte> & output) const {
            const std::string & name = getName();

            for (char c:name) {
                output.push_back(c);
            };
            output.push_back(0); 
        };

        void serializeEmployees(std::vector<byte> & output) const {
            std::vector<std::pair<char,char>> empl(getEmployees());

            output.push_back(empl.size());

            for (auto emp:empl) {
                output.push_back(emp.first);
                output.push_back(emp.second);
            };
        };

};



byte* serializeToMemory(const std::string & buffer, size_t & bytesWritten) {

    std::vector<byte> output (1,0);

    std::istringstream istr(buffer);

    SerializableCompany c;

    while (istr>>c) {

        c.serialize(output);
        output[0]++;

    };

    byte * outBuf= new byte[output.size()];
    
    bytesWritten=0;

    for (byte b:output) {
        outBuf[bytesWritten++]=b;
    };

    return outBuf;
};


#endif