#ifndef SolfegeNoteNaming_hh
#define SolfegeNoteNaming_hh

#include <string>


class SolfegeNoteNaming {

    public:
    char operator() (const std::string & note ) const {
        if (note=="Do") {
            return 'C';
        }
        else if (note=="Re") {
            return 'D';
        }
        else if (note=="Mi") {
            return 'E';
        }
        else if (note=="Fa") {
            return 'F';
        }
        else if (note=="Sol") {
            return 'G';
        }
        else if (note=="La") {
            return 'A';
        }
        else if (note=="Si") {
            return 'B';
        }
        else {
            return '?';
        };
    };
};


#endif