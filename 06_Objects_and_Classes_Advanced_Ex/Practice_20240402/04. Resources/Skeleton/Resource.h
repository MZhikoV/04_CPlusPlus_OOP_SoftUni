#ifndef RESOURCE_H
#define RESOURCE_H

#include "ResourceType.h"

#include <iostream>
#include <sstream>
#include <string>

namespace SoftUni {

class Resource {
    int id;
    ResourceType rt;
    std::string url;

    public:
        Resource()=default;

        ResourceType getType() const {
            return rt;
        };

        bool operator < (const Resource & other) const {
            return (this->id)<(other.id);
        };

        friend std::istream & operator >>(std::istream & istr, Resource & r);
        friend std::ostream & operator <<(std::ostream & ostr, const Resource & r);
};
        //friend
        std::istream & operator >>(std::istream & istr, ResourceType & rt) {
            std::string buffer;
            istr>>buffer;
            if (buffer=="Demo") {
                rt=ResourceType::DEMO;
            }
            else if (buffer=="Video") {
                rt=ResourceType::VIDEO;
            }
            else {
                rt=ResourceType::PRESENTATION;
            };
            return istr;
        };

        //friend
         std::istream & operator >>(std::istream & istr, Resource & r) {
            istr>>r.id>>r.rt>>r.url;
            return istr;
        };

        //friend
        std::ostream & operator <<(std::ostream & ostr,const Resource & r) {
            ostr<<r.id<<' '<<r.rt<<' '<<r.url;
            return ostr;
        };
};

#endif