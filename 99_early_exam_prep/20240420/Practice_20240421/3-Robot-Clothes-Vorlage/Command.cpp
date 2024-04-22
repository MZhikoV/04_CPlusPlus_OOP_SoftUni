
#include "Command.h"

#include <string>
#include <sstream>
#include <iostream>


        std::string Command::abortMessage(const std::string & invalidId) const {
            std::string currCommand=getName();

            std::string listID="";     //string of used ID's
            int usedMat=0;          //total material used
            int totalT=0;           //total time spent for operations

            bool isFirst=true;

            for (auto currSt:proc.storage) {
                if (isFirst) {
                    isFirst=false;
                }
                else {
                    listID+=", ";
                };
                listID+=currSt.first;
                usedMat+=currSt.second.mat;
                totalT+=currSt.second.time;

               // eraseData(currSt.first);
            };



            return      "Aborting on "+ currCommand +" due to invalid ID \""+ invalidId +"\". Lost pieces "
                        + listID +", lost material "+ std::to_string(usedMat) +", wasted time "+ std::to_string(totalT) +".";
        };

        std::string Command::successMessage() const {
            //todo

            std::string listID="";     //string of used ID's
            int usedMat=0;          //total material used
            int totalT=0;           //total time spent for operations

            bool isFirst=true;

            for (auto currSt:proc.storage) {
                
                if (currSt.first!=getId()) {
                
                if (isFirst) {
                    isFirst=false;
                }
                else {
                    listID+=", ";
                };
                listID+=currSt.first;
                usedMat+=currSt.second.mat;
                totalT+=currSt.second.time;
                };

              //  eraseData(currSt.first);
            };

            return      "Packing and shipping new order: \"" + listID + "\". Production material: " 
                        + std::to_string(usedMat) + ", production time: " + std::to_string(totalT) + ".";
        };