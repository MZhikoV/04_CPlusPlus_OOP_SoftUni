#ifndef RESOURCE_H
#define RESOURCE_H

#include "ResourceType.h"

#include <string>
#include <iostream>
#include <sstream>

namespace SoftUni {



class Resource {

    int id;
    //std::string rtype;
    ResourceType rt;
    std::string url;

public:

    Resource()=default;

    ResourceType getType() const {
        return rt;
    };

    friend std::istream& operator>>(std::istream & istr, Resource & r);

    friend std::ostream& operator<<(std::ostream & ostr, const Resource & r);

    bool operator<(const Resource & other) const {
        return this->id<other.id;
    };


};

    //friend
    std::istream& operator>>(std::istream & istr, ResourceType & rt){
        std::string rtype;
        istr>>rtype;

        if (rtype=="Demo") {
            rt=ResourceType::DEMO;
        }
        else if (rtype=="Video") {
            rt=ResourceType::VIDEO;
        }
        else {
            rt=ResourceType::PRESENTATION;
        };

        return istr;
    };

    std::istream& operator>>(std::istream & istr, Resource & r){
        return istr>>r.id>>r.rt>>r.url;
    };

    //friend
    std::ostream& operator<<(std::ostream & ostr, const Resource & r){
        ostr<<r.id<<' '<<r.rt<<' '<<r.url;
        return ostr;
    };

   


};


#endif // !RESOURCE_H 
