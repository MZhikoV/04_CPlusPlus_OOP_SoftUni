#include "Command.h"
#include "Processor.h"

std::string Command::abortMessage(const std::string &invalidId) const {
    std::string lostPcs;
    unsigned lostMat = 0;
    unsigned wastedTime = 0;

    for (const auto &pair : proc.storage) {
        if (pair.first != getId()) {
            lostPcs += pair.first + ", ";
            lostMat += pair.second.mat;
            wastedTime += pair.second.time;
        };
    };

    return "Aborting on " + getName() + " due to invalid ID \"" + invalidId 
            + "\". Lost pieces " + lostPcs + "lost material " + std::to_string(lostMat) 
            + ", wasted time " + std::to_string(wastedTime) + ".";
};

std::string Command::successMessage() const {
    std::string procPcs;
    unsigned usedMat = 0;
    unsigned totalTime = 0;

    for (const auto &pair : proc.storage) {
        procPcs += pair.first + ", ";
        // if (procPcs.empty()) {
        // procPcs = pair.first;
        // }
        usedMat += pair.second.mat;
        totalTime += pair.second.time;
    };

    if (!procPcs.empty()) {
        procPcs.pop_back(); 
        procPcs.pop_back(); 
    };

std::string lastID;

    if (proc.commands.size() >= 2) {
        auto it = proc.commands.end();
        --it; // move to the last command
        --it; // move to the second to last command
        lastID= (*it)->getId();

    }



    // if (!proc.commands.empty()) {
    //     lastID= (proc.commands.end()-2)->getId();
    // }

    return "Packing and shipping new order: \"" + lastID + "\". Production material: " 
            + std::to_string(usedMat) + ", production time: " + std::to_string(totalTime) + ".";
};


        // std::string Command::abortMessage(const std::string & invalidId) const {
        //     //todo

        //     return "Aborting on "<<getName()<<" due to invalid ID \""<<invalidId<<"\". Lost pieces "
        //     <<{comma-separated list of alphabetical sorted all IDs that are currently in processing}<<", lost material "
        //     <<getMaterial() <<", wasted time "<<getTime()<<".";
        //     //Aborting on {command name} due to invalid ID "{the invalid ID}". Lost pieces {comma-separated list of alphabetical sorted all IDs that are currently in processing}, lost material {the total quantity of all used material}, wasted time {the total amount of all time, used so far}.


        //     
        // };
        // std::string Command::successMessage() const {
        //     //todo


        //     return "Packing and shipping new order: \""<<{comma-separated list of alphabetical sorted all IDs that are currently in processing}
        //     <<"\". Production material: "<<{the total quantity of all used material}<<", production time: "<<
        //     {the total amount of all time, used so far, without the time of the errored operation}<<".";
        //     //Packing and shipping new order: "{comma-separated list of alphabetical sorted all IDs that are currently in processing}". Production material: {the total quantity of all used material}, production time: {the total amount of all time, used so far, without the time of the errored operation}.


        //     
        // };


