#ifndef RESOURCE_H
#define RESOURCE_H

#include "ResourceType.h"

using namespace std;

namespace SoftUni{

class Resource {

    int id;
    ResourceType rt;
    string url;

    public:

    friend istream & operator >> (istream & first, Resource & r);

    friend ostream & operator << (ostream & first, const Resource & r);

    ResourceType getType() const {
        return rt;
    }

    bool operator < (const Resource & other) const {
        return this->id < other.id;
    }

};

istream & operator >> (istream & first,ResourceType & rt) {
    string buff;
    first>>buff;

    if (buff=="Presentation") {
        rt=ResourceType::PRESENTATION;
    }
    else if (buff=="Demo") {
        rt=ResourceType::DEMO;
    }
    else {
        rt=ResourceType::VIDEO;
    }
    return first;
}


istream & operator >> (istream & first, Resource & r) {
        first>>r.id>>r.rt>>r.url;

        return first;
    };

ostream & operator << (ostream & first, const Resource & r) {
    first<<r.id<<' '<<r.rt<<' '<<r.url;
    return first;
};



}
#endif // !RESOURCE_H 
