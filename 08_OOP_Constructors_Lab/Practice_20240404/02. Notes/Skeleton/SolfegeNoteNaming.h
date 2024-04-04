#ifndef SOLFEGEE_H
#define SOLFEGEE_H

#include "NoteName.h"

class SolfegeNoteNaming {
public:
    NoteName operator () (const std::string& noteText) const {
        if (noteText=="Do") {
            return NoteName('C');
        }
        else if (noteText=="Re") {
            return NoteName('D');
        }
        else if (noteText=="Mi") {
            return NoteName('E');
        }
        else if (noteText=="Fa") {
            return NoteName('F');
        }
        else if (noteText=="Sol") {
            return NoteName('G');
        }
        else if (noteText=="La") {
            return NoteName('A');
        }
        else if (noteText=="Si") {
            return NoteName('B');
        }
        else  {
            return NoteName('?');
        };
    };
};




#endif