#include "SewCommand.h"


#include "Processor.h"

std::string SewCommand::execute(void) const {
    std::list<std::string> invalidIds;
    unsigned totalMaterial = 0;
    unsigned totalTime = 0;

    
    for (const auto &id : elements) {
        if (!existsData(id)) {
            return abortMessage(id);
        } else {
           // totalMaterial += getData(id).mat;
            totalMaterial=0;
            //totalTime += getData(id).time;
            totalTime = getData(id).time+getTime();

            eraseData(id);
        }
    };
 
    if (existsData(getId())) {
        return abortMessage(getId());
    } 
    else {
        Processor::TimeAndMaterial tm(totalTime, totalMaterial);
        insertData(tm);

    };

    return "";
};