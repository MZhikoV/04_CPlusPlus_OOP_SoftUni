#ifndef IronCommand_hh
#define IronCommand_hh


#include "TimedCommand.h"
#include "Command.h"

class IronCommand : public TimedCommand {

    public:

        IronCommand(Processor & proc) : Command(proc), TimedCommand(proc) {}

        virtual std::string getName(void) const override { return "iron"; }

        virtual void read(std::istream & istr) override {
            Command::read(istr); // read the main Command (virtual inheritance!)
            TimedCommand::read(istr); // read the TimedCommand
        }

        virtual std::string execute(void) const override {

            // check if this ID already exists in the storage
            if (!existsData(getId())) {
                // if yes - abort with that error
                return abortMessage(getId());
            }
            else {
            // we can create new element now:
            unsigned prevTime=getData(getId()).time;
            unsigned prevMat=getData(getId()).mat;

            //remove the previous ID data from storage
            eraseData(getId());

            //insert the new data for the ID
            Processor::TimeAndMaterial tm(getTime()+prevTime, prevMat);
            insertData(tm); // insert the new element in the storage
            };

            return "";
        }



};



#endif