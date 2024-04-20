#ifndef dog_h
#define dog_h

#include "animal.h"

#include <iostream>
#include <sstream>

class Dog : public Animal {

    unsigned catsPerHour; 
    unsigned activeHours;

    public:

        Dog(std::istream & istr) : catsPerHour(0), activeHours(0) {
            istr >> catsPerHour >> activeHours;
        };

         virtual unsigned getResult(unsigned weeks) const {
            return 7*(catsPerHour*activeHours) * weeks;
        };

        virtual std::string getDescription() const { return "Dog"; };

        virtual std::string getInfo() const {
            std::ostringstream ostr;
            ostr << '<' << catsPerHour << ", " << activeHours << ">";

            return ostr.str();
        }

};



#endif


/*
class Cat : public Animal {

    unsigned micePerDay; 
    unsigned activeDays;

    public:

        Cat(std::istream & istr) : micePerDay(0), activeDays(0) {
            istr >> micePerDay >> activeDays;
        }

        virtual unsigned getResult(unsigned weeks) const {
            return micePerDay * activeDays * weeks;
        };

        virtual std::string getDescription() const { return "Cat"; }
        
        virtual std::string getInfo() const {
            std::ostringstream ostr;
            ostr << '<' << micePerDay << ", " << activeDays << ">";

            return ostr.str();
        }

};

*/