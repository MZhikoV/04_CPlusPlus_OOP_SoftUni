#ifndef solution_h
#define solution_h

#include <string>
#include <sstream>
#include <iostream>

#include "storage.h"


// returns `true` if the `storage` contains all `contents`
        // **Please remember:** 
        //   In the custom classes, every operator can do whatever functionality is needed, as far as 
        //   it can get its operands from correct operator syntax. In our case, it’s perfectly OK to use  
        //   the operator `<=` to verify if given contents exist in the storage.
bool Storage::operator <= (Store & contents) {
    auto it=contents.begin();
            for (;it!=contents.end();it++) {

                auto itFind=storage.find((*it).first);
                if (itFind!=end() && storage[itFind->first]<it->second) {
                    return false;
                }
                else if (itFind==end()) {
                    return false;
                };
                // if (storage[(*it).first]<(*it).second) {
                //     return false;
                // };
            };
            return true;
};

// removes `contents` from the storage
Storage & Storage::operator >> (Store & contents){
            auto it=contents.begin();
            for (;it!=contents.end();it++) {
                storage[(*it).first]-=(*it).second;

                if (storage[(*it).first]==0) {
                    storage.erase((*it).first);
                }
            };

            // auto it2=  begin();
            // for (;it2!= end();) {
            //     if ((*it2).second==0) {
            //         storage.erase(it2);
            //     }
            //     else {
            //         it2++;
            //     };
            // }

            return *this;
        };


std::ostream& operator <<(std::ostream & out, Storage & s) {
    auto it=s.begin();
        out<<"Storage: ";
        bool isFirst=true;
    for (;it!=s.end();it++) {
        if(isFirst) {
            isFirst=false;
        }
        else {
            out<<", ";
        };


        out<<(*it).first<<": "<<(*it).second;
    };

    return out;
};



/*
class Storage {

    public:
        typedef std::map<std::string, unsigned> Store; 

    private:
        Store storage;

    public:

        Store::iterator begin() { return storage.begin(); }
        Store::iterator end() { return storage.end(); }

        // returns `true` if the `storage` contains all `contents`
        // **Please remember:** 
        //   In the custom classes, every operator can do whatever functionality is needed, as far as 
        //   it can get its operands from correct operator syntax. In our case, it’s perfectly OK to use  
        //   the operator `<=` to verify if given contents exist in the storage.
        bool operator <= (Store & contents);

        // removes `contents` from the storage
        Storage & operator >> (Store & contents);

        // adds the `element` to the storage
        Storage & operator << (const std::string & element) {
            storage[element]++;
            return *this;
        }
};
*/







#endif