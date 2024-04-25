#include "Noises.h"
// #include <map>
// #include <string>
// #include <iostream>

// class Noises {

//     typedef std::map<std::string, Noise> NoisesMap;
//     NoisesMap noises;

//     // transforms the string "+XXXX" to the number XXXX
//     size_t stringToTime(const std::string & time) {
//         return (time[1]-'0')*1000+(time[2]-'0')*100+(time[3]-'0')*10+time[4]-'0';        // ignore the "+" sign
//     }

//     public:

        std::string Noises::registerNoise(const std::string & time_, const std::string & noise_) {
            //todo
            Noise c(stringToTime(time_));
            auto itFound=noises.find(noise_);
            if (itFound==noises.end()) {
                noises[noise_]=c;
            }
            else {
                (itFound->second).newNoise(stringToTime(time_));
            };
            c=noises[noise_];
            return c.getNewNoiseStatistics();
        };

        void Noises::printStatistics(std::ostream & ostr) const {
            ostr<<"----"<<std::endl;
            if (!noises.empty()) {
                for (auto & curr:noises) {
                    ostr<<curr.first<<": "<<curr.second.getFinalStatistics()<<std::endl;
                };
            }
            else {
                ostr<<"No noises."<<std::endl;
            }
                //todo
        };
// };



// #endif