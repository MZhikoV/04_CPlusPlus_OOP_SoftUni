#ifndef PackCommand_hh
#define PackCommand_hh

#include "Command.h"


class PackCommand : public Command {

    public:

        PackCommand(Processor & proc) : Command(proc) {};

        virtual void read(std::istream & istr) override {
           Command::read(istr); // read the main Command (virtual inheritance!)
        };

        virtual std::string getName(void) const override { return "pack"; }

        virtual std::string execute(void) const override {

                return successMessage();
        };
};



#endif