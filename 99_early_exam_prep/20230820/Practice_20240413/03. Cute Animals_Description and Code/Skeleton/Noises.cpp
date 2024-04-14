#include "Noises.h"
#include <sstream>

std::string Noises::registerNoise(const std::string & time_, const std::string & noise_) {
    size_t time = stringToTime(time_);
    if (noises.find(noise_) == noises.end()) {
        noises[noise_] = Noise(time);
    } else {
        noises[noise_].newNoise(time);
    }
    return noise_ + ": " + noises[noise_].getNewNoiseStatistics();
}

void Noises::printStatistics(std::ostream & ostr) const {
    if (!noises.empty()) {
    for (const auto & [noise, noiseObj] : noises) {
        ostr << noise << ": " << noiseObj.getFinalStatistics() << std::endl;
    }
    }
    else {
        ostr<<"No noises."<<std::endl;
    }
}
