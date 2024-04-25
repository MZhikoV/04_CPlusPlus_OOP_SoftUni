#include "Noise.h"
#include <sstream>
// #ifndef NOISE_H
// #define NOISE_H

// #include <string>

// class Noise {

//     size_t first;
//     size_t last;
//     size_t number;
//     size_t each;

//     public:
//         Noise() {}
//         Noise(size_t first_) : number(1), last(first_), first(first_), each(1) {}
//         Noise(const Noise &) = default;
//         Noise & operator = (const Noise &) = default;

//         int getFirst(void) const { return first; }
//         int getLast(void) const { return last; }
//         int getNumber(void) const { return number; }

        void Noise::newNoise(size_t time) {
            number++;
            last=time;
            each=(last-first)/number;
        };

        std::string Noise::getNewNoiseStatistics(void) const {
            std::ostringstream ostr;
            ostr<<number;
            if (number>1){
                ostr<<", each ";
                if(each<=1) {
                    ostr<<"minute";
                }
                else {
                    ostr<<each<<" minutes";
                };
            };

            return ostr.str();
        };

        std::string Noise::getFinalStatistics(void) const{
            std::ostringstream ostr;
            ostr<<number;
            if (number>1) {
                ostr<<", from "<<first<<" till "<<last<<", each ";
                    if(each<=1) {
                        ostr<<"minute";
                    }
                    else {
                        ostr<<each<<" minutes";
                    };
            }
            else {
                ostr<<" at "<<first;
            }
            
            //todo
            return ostr.str();
        };
// };

// #endif