#include <iostream>
#include <string>
#include <sstream>


#include "Noises.h"



int main() {


std::string buffer;

Noises a;

while (std::getline(std::cin,buffer)) {
    std::istringstream istr(buffer);

    std::string time,noise;
    istr>>time>>noise;

   


        std::string endCheck=noise;
        for (size_t idx=0;idx<endCheck.size();idx++) {
            endCheck[idx]=tolower(endCheck[idx]);
        };
        if (endCheck=="theend") {
            break;
        };

        
        std::cout<<a.registerNoise(time,noise)<<std::endl;
        
};

a.printStatistics(std::cout);

//    system ("pause");

    return 0;
}