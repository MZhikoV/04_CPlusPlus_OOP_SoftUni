#include "SewCommand.h"
#include "Processor.h"

std::string SewCommand::execute(void) const {
    std::list<std::string> invalidIds;
    unsigned totalMaterial = 0;
    unsigned totalTime = 0;

    // Check if all elements exist in the storage
    for (const auto &id : elements) {
        if (!existsData(id)) {
            return abortMessage(id);
        } else {
            totalMaterial += getData(id).mat;
            totalTime += getData(id).time;
        }
    }

    // Create the new piece
    if (existsData(getId())) {
        return abortMessage(getId());
    } else {
       Processor::TimeAndMaterial tm(totalTime, totalMaterial);
        insertData(tm);
    }

    return "";
}
