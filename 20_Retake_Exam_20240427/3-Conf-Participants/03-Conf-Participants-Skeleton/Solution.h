#ifndef Solution_h
#define Solution_h

#include "Organizer.h"
#include "Participant.h"
#include "OrganizerEmployee.h"
#include "OrganizerManager.h"
#include "Visitor.h"
#include "AdultVisitor.h"
#include "MinorVisitor.h"
#include "Sponsor.h"
#include "SilverEmployee.h"
#include "GoldEmployee.h"


std::ostream& operator<<(std::ostream& out, const Organizer::Vector & all) {
    if (all.empty()) {
        out<<"- none"<<std::endl;
    }
    else {
    for (auto & curr: all) {
        out<<"- "<<curr->print()<<std::endl;

        // if(curr->getType().value==Participant::Type::OrganizerEmployee) {
        //     out<<OrganizerEmployee::print();

        //     curr.
        // }
    };
    };


    return out;
};

// std::ostream& operator<<(std::ostream& out, const Visitor::Vector & all) {

//     for (auto & curr: all) {
//         out<<"- "<<curr->print()<<std::endl;

//         // if(curr->getType().value==Participant::Type::OrganizerEmployee) {
//         //     out<<OrganizerEmployee::print();

//         //     curr.
//         // }
//     }


//     return out;
// };

// std::ostream& operator<<(std::ostream& out, const Sponsor::Vector & all) {

//     for (auto & curr: all) {
//         out<<"- "<<curr->print()<<std::endl;

//         // if(curr->getType().value==Participant::Type::OrganizerEmployee) {
//         //     out<<OrganizerEmployee::print();

//         //     curr.
//         // }
//     }


//     return out;
// }

//todo


#endif