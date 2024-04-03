#ifndef RESOURCEEEE_H
#define RESOURCEEEE_H

#include "ResourceType.h"
#include <string>
#include <sstream>



namespace SoftUni {

class Resource {

    int id;
    ResourceType rt;
    std::string url;

    public:
    Resource () {};
    //Resource(int inpId, ResourceType inpType, std::string inpUrl): id(inpId), rt(inpType), url(inpUrl) {};

    ResourceType getType() const {
        return rt;
    };

    int getID() const {
        return id;
    };

    std::string getUrl() {
        return url;
    };

friend std::istream& operator>> (std::istream & istr, Resource& a);

};

//friend
std::istream& operator>> (std::istream & istr, Resource& a) {
    std::string buffer;
    getline(istr,buffer);
    std::istringstream inp(buffer);
    inp>>(a.id);
    std::string typeR;
    inp>>(typeR);
    inp>>(a.url);
};

std::ostream& operator<< (std::ostream & out, Resource& a ) {
    return out<<a.getID()<<' '<<a.getType()<<' '<<a.getUrl();
};


};

// Place your code here

#endif // !RESOURCE_H 
