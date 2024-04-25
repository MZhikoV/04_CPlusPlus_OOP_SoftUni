#include <iostream>
#include <sstream>
#include "Noises.h"



int main() {

    std::string time;
    std::string noise;

    Noises data;

    while (std::cin>>time>>noise) {
        
        if(tolower(noise[0])=='t' && noise.size()==6 && tolower(noise[5])=='d') {
            break;
        };

        std::cout<<noise<<": "<<data.registerNoise(time,noise)<<std::endl;
    };
    
        data.printStatistics(std::cout);



  //  system("pause");

    return 0;
}