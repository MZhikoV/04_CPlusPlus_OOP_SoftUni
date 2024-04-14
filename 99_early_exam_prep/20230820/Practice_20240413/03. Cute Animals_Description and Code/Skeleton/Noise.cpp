#include "Noise.h"
#include <sstream>

void Noise::newNoise(size_t time) {
    each = time - last;
    last = time;
    number++;
}


std::string Noise::getNewNoiseStatistics() const {
    std::ostringstream oss;
    oss << getNumber();
    if (getNumber() > 1) {
        
        oss << ", each ";
        if ((getLast()-getFirst()) /getNumber()==0) {
            oss<<"minute";
        }
        else {
            oss<< (getLast()-getFirst()) /getNumber() << " minutes";
        } 
    }
    return oss.str();
}



// std::string Noise::getNewNoiseStatistics() const {
//     std::ostringstream oss;
//     oss << getNumber();
//     if (getNumber() > 1) {
        
//         oss << ", each ";
//         if (each/number==0) {
//             oss<<"minute";
//         }
//         else {
//             oss<< each/number << " minutes";
//         } 
//     }
//     return oss.str();
// }

std::string Noise::getFinalStatistics() const {
    std::ostringstream oss;
    oss << getNumber();
    if (getNumber()==1) {
        oss<<" at "<<getFirst();
    }
    else {
        oss << ", from " << getFirst() << " till " << getLast();
    };

    if (getNumber() > 1) {
        oss << ", each ";
        if ((getLast()-getFirst()) /getNumber()==0) {
            oss<<"minute";
        }
        else {
            oss<< (getLast()-getFirst()) /getNumber() << " minutes";
        }; 
    }
    return oss.str();
}
