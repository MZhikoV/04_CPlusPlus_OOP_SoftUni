#ifndef IRONCOMMAND_H
#define IRONCOMMAND_H

#include "TimedCommand.h"

class IronCommand : public TimedCommand {
public:
    IronCommand(Processor &proc) : Command(proc), TimedCommand(proc) {}

    virtual std::string getName(void) const override { return "iron"; }

    virtual void read(std::istream &istr) override {
        Command::read(istr);
        TimedCommand::read(istr);
    };

    virtual std::string execute(void) const override {
        if (!existsData(getId())) {
            return abortMessage(getId());
        } 
        else {
            Processor::TimeAndMaterial tm(getTime(), getData(getId()).mat);
            insertData(tm);
        }
        return "";
    };
};

#endif
