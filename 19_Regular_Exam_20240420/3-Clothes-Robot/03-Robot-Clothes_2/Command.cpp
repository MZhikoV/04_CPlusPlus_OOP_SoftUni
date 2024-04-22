#include "Command.h"
#include "Processor.h"

std::string Command::abortMessage(const std::string &invalidId) const {
    std::string lostPieces;
    unsigned lostMaterial = 0;
    unsigned wastedTime = 0;

    for (const auto &pair : proc.storage) {
        if (pair.first != getId()) {
            lostPieces += pair.first + ", ";
            lostMaterial += pair.second.mat;
            wastedTime += pair.second.time;
        }
    }

    if (!lostPieces.empty()) {
        lostPieces.pop_back();  // Remove the trailing comma
        lostPieces.pop_back();  // Remove the trailing space
    }

    return "Aborting on " + getName() + " due to invalid ID \"" + invalidId + "\". Lost pieces " + lostPieces + ", lost material " + std::to_string(lostMaterial) + ", wasted time " + std::to_string(wastedTime) + ".";
}

std::string Command::successMessage() const {
    std::string processingPieces;
    unsigned usedMaterial = 0;
    unsigned totalTime = 0;

    for (const auto &pair : proc.storage) {
        processingPieces += pair.first + ", ";
        usedMaterial += pair.second.mat;
        totalTime += pair.second.time;
    }

    if (!processingPieces.empty()) {
        processingPieces.pop_back();  // Remove the trailing comma
        processingPieces.pop_back();  // Remove the trailing space
    }

    return "Packing and shipping new order: \"" + processingPieces + "\". Production material: " + std::to_string(usedMaterial) + ", production time: " + std::to_string(totalTime) + ".";
}
