#include "SewCommand.h"

        std::string SewCommand::execute(void) const{
            int prevMaterials=0;
            int prevTime=0;


            //check if the pieces ID are existing
            for (const auto  & curr:elements) {

                if (!existsData(curr)) {
                // if not existing - abort with that error
                return abortMessage(curr);
                } 
                else {
                    prevMaterials+=getData(curr).mat;
                    prevTime+=getData(curr).time;
                }

                eraseData(curr);//clears the ID of the sewed pcs

            };

         // check if this ID already exists in the storage
            if (existsData(getId())) {
                // if yes - abort with that error
                return abortMessage(getId());
            }
            else {

             // we can create new element now:
            Processor::TimeAndMaterial tm(getTime()+prevTime, prevMaterials);
            insertData(tm); // insert the new element in the storage
            }


            return "";
        };