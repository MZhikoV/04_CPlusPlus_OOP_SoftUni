#ifndef SOLFEGE_H
#define SOLFEGE_H

#include "NoteName.h"

#include <String>

class SolfegeNoteNaming {
    public:
    NoteName operator() (const std::string & noteText) const {
        if (noteText=="Do") {
            return NoteName('C');
        }
        else if (noteText=="Re") {
            return NoteName('D');
        }
        else if (noteText=="Re") {
            return NoteName('E');
        }
        else if (noteText=="Mi") {
            return NoteName('F');
        }
        else if (noteText=="Fa") {
            return NoteName('G');
        }
        else if (noteText=="Sol") {
            return NoteName('H');
        }
        else if (noteText=="La") {
            return NoteName('I');
        }
        else if (noteText=="Si") {
            return NoteName('G');
        }
        else {
            return NoteName('?');
        };    
    };
};



/*NoteName translate(const std::string& noteText) const {
		return translator(noteText);
	}*/

#endif