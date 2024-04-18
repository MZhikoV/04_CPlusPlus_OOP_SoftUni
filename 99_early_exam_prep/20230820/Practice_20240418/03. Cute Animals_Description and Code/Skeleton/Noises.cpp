#include "Noises.h"
#include <map>
#include <iostream>
#include <sstream>

        std::string Noises::registerNoise(const std::string & time_, const std::string & noise_) {

            std::string result;

            std::map<std::string, Noise>::iterator itFound;
            itFound=noises.find(noise_);

            if (itFound!=noises.end()) {
                itFound->second.newNoise(stringToTime(time_));
            }
            else {                
                noises[noise_]=Noise(stringToTime(time_));;
            };           
            return result=noise_+": "+noises[noise_].getNewNoiseStatistics();
        };

        void Noises::printStatistics(std::ostream & ostr) const {
            //std::ostringstream ost;
            ostr<<"----"<<std::endl;
            if (noises.empty()) {
                ostr<<"No noises."<<std::endl;
            }
            else {
            for (auto curr:noises) {
                ostr<<curr.first<<curr.second.getFinalStatistics()<<std::endl;
            };
            };
        };


        void Noise::newNoise(size_t time) {
            last=time;
            number++;
            each=(last-first)/number;
        };


        std::string Noise::getNewNoiseStatistics(void) const {
            std::ostringstream ostr;

            ostr<<number;

            if (number>1) {
                ostr<<", each ";

                    if((last-first)/number<=1) {
                        ostr<<"minute";
                    }
                    else {
                        ostr<<(last-first)/number<<" minutes";
                    };
            };

            return ostr.str();
        };


        std::string Noise::getFinalStatistics(void) const {
            
            std::ostringstream ostr;
            if (getNumber()==1) {
                ostr<<": "<<getNumber()<<" at "<<getFirst();
            }
            else {

                ostr<<": "<<getNumber()<<", from "<<getFirst()<<" till "<<getLast()<<", each ";

                    if(each<=1) {
                        ostr<<"minute";
                    }
                    else {
                        ostr<<each<<" minutes";
                    };
            };
            return ostr.str();
        };
// };



// #endif