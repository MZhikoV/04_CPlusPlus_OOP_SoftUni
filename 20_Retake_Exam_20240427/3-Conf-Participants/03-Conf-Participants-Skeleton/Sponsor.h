#ifndef Sponsor_h
#define Sponsor_h

#include "Participant.h"


class Sponsor: public Participant {
//todo

public:

    static Participant::Vector all;

    Sponsor(std::istream & istr) : Participant(istr) {istr>>company, all.push_back(this);};

    virtual Type getType() const override=0;
    virtual std::string print() const=0;

    virtual~Sponsor()=default;

protected:

        std::string company;

};


/*
class Organizer : public Participant {

    public:

        static Participant::Vector all;

        Organizer(std::istream & istr) : Participant(istr) {
            all.push_back(this);
        }

};
*/


//todo

/*
class GoldEmployee : public Sponsor {
*/

#endif