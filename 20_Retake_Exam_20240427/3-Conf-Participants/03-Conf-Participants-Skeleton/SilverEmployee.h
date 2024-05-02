#ifndef SilverEmployee_h
#define SilverEmployee_h

#include "Sponsor.h"

class SilverEmployee : public Sponsor {

public:
    SilverEmployee(std::istream & istr) : Sponsor(istr) {
            istr >> accountId;
        }

    virtual Type getType() const override { return Type(Participant::Type::SilverEmployee); }

    virtual std::string print() const override {
            std::ostringstream ostr;

            ostr << "Silver: " << Participant::print() << " | " << company << " | " << accountId;

            return ostr.str();
        }


 protected:

        std::string accountId;


};




/*


class GoldEmployee : public Sponsor {

    public:
        GoldEmployee(std::istream & istr) : Sponsor(istr) {
            istr >> tShirtSize;
        }

        virtual Type getType() const override { return Type(Participant::Type::GoldEmployee); }

        virtual std::string print() const override {
            std::ostringstream ostr;

            ostr << "Gold: " << Participant::print() << " | " << company << " | " << tShirtSize;

            return ostr.str();
        }

    protected:

        std::string tShirtSize;

};
*/
//todo


#endif