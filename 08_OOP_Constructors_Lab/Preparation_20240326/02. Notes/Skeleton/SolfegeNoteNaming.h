#ifndef SOLFEGE_H
#define SOLFEGE_H

#include <string>
#include "NoteName.h"
class SolfegeNoteNaming {

public:

NoteName operator()(const std::string & noteText) const;

};





#endif