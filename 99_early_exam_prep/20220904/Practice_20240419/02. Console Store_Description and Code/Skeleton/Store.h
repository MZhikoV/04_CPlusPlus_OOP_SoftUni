#ifndef store_h
#define store_h

#include <vector>
#include <iostream>
#include <map>

struct OOPS{

int price;
int quality;
int gen;
int entry;

public:
    OOPS(int price, int quality, int generation, int entryP) : price(price), quality(quality), gen(gen), entry(entryP) {};
};


struct XBOXX{

int price;
int quality;
int entry;

public:
    XBOXX(int & price,int & quality, int & entryX) : price(price), quality(quality), entry(entryX) {};
};


class Store {

std::vector<OOPS> pss;
std::vector<XBOXX> xbx;
int entryP=0;
int entryX=0;

public:

    void addPs(int price, int quality, int generation) {
        
        OOPS ps(price,quality,generation,entryP);
        pss.push_back(ps);
        entryP++;

        std::cout<<"Adding: PS with generation "<<generation <<", price: "<<price<<", quality: "<<quality<<std::endl;
    };

    void addXbox(int price, int quality) {

        XBOXX xs (price,quality,entryX);
        xbx.push_back(xs);
        entryX++;

        std::cout<<"Adding: Xbox with price: "<<price<<", quality: "<<quality<<std::endl;

    };

    void remove(ConsoleType consoleType) {

        if (consoleType==ConsoleType::PS) {
            
            if (!pss.empty()) {

            for (size_t i=0;i<pss.size();i++) {
                if((pss[i].entry)==(entryX-1))


            std::cout<<"Removing: PS with generation "<<pss[i].gen <<",price: "<<pss[i].price<<", quality: "<<pss[i].quality<<std::endl;

            pss.erase(pss.begin()+i);
            entryP--;
            };
            };
            
        }
        else if (consoleType==ConsoleType::XBOX) {

            if (!xbx.empty()) {

            
            for (size_t i=0;i<xbx.size();i++) {
                if((xbx[i].entry)==(entryX-1))
            

            std::cout<<"Removing: Xbox with price: "<<xbx[i].price<<", quality: "<<xbx[i].quality<<std::endl;

            xbx.erase(xbx.begin()+i);
            entryX--;
            };
            };
        }








        // if (consoleType==ConsoleType::PS) {
            
        //     if (!pss.empty()) {
        //     std::cout<<"Removing: PS with generation "<<pss.back().gen <<",price: "<<pss.back().price<<", quality: "<<pss.back().quality<<std::endl;

        //     pss.pop_back();
        //     };
            
        // }
        // else if (consoleType==ConsoleType::XBOX) {
        //     if (!xbx.empty()) {
        //     std::cout<<"Removing: Xbox with price: "<<xbx.back().price<<", quality: "<<xbx.back().quality<<std::endl;

        //     xbx.pop_back();
        //     };
        // }
    };

    void sortByPrice(ConsoleType consoleType) {

         if (consoleType==ConsoleType::PS) {
            
            std::cout<<"Sorting all PS by price"<<std::endl;

            std::map<int,std::vector<OOPS>, std::greater<int>> pricePS;

            if (!pss.empty()) {
                // std::cout<<"Sorting all PS by price"<<std::endl;
            for (auto & curr:pss) {
                pricePS[curr.price].push_back(curr);
            };

            auto it=pricePS.begin();

            pss.clear();

            for (;it!=pricePS.end();it++) {
                for (auto curr : it->second) {
                    pss.push_back(curr);
                };
            };
            };
            
            
        }
        else if (consoleType==ConsoleType::XBOX) {

            std::cout<<"Sorting all Xbox by price"<<std::endl;
            
            std::map<int,std::vector<XBOXX>, std::greater<int>> priceXB;

            if (!xbx.empty()) {
                // std::cout<<"Sorting all Xbox by price"<<std::endl;
            for (auto & curr:xbx) {
                priceXB[curr.price].push_back(curr);
            };

            auto it=priceXB.begin();

            xbx.clear();

            for (;it!=priceXB.end();it++) {
                for (auto curr : it->second) {
                    xbx.push_back(curr);
                };
            };
            };  
        };
    };

    void sortByQuality(ConsoleType consoleType) {

        if (consoleType==ConsoleType::PS) {
            
            std::cout<<"Sorting all PS by quality"<<std::endl;

            std::map<int,std::vector<OOPS>, std::greater<int>> qualPS;

            if (!pss.empty()) {
                // std::cout<<"Sorting all PS by quality"<<std::endl;
            for (auto & curr:pss) {
                qualPS[curr.quality].push_back(curr);
            };

            auto it=qualPS.begin();

            pss.clear();

            for (;it!=qualPS.end();it++) {
                for (auto curr : it->second) {
                    pss.push_back(curr);
                };
            };
            };
        }
        else if (consoleType==ConsoleType::XBOX) {

            std::cout<<"Sorting all Xbox by quality"<<std::endl;
            
            std::map<int,std::vector<XBOXX>, std::greater<int>> qualXB;

            if (!xbx.empty()) {
                // std::cout<<"Sorting all Xbox by quality"<<std::endl;
            for (auto & curr:xbx) {
                qualXB[curr.quality].push_back(curr);
            };

            auto it=qualXB.begin();

            xbx.clear();

            for (;it!=qualXB.end();it++) {
                for (auto curr : it->second) {
                    xbx.push_back(curr);
                };
            }; 
            }; 
        };
    };

    void print(ConsoleType consoleType) {

        
         if (consoleType==ConsoleType::PS) {

            std::cout<<"Printing all PS data"<<std::endl;
            
            if (!pss.empty()) {
                // std::cout<<"Printing all PS data"<<std::endl;
            for (auto & curr:pss) {

                std::cout<<"PS with generation "<<curr.gen <<",price: "<<curr.price<<", quality: "<<curr.quality<<std::endl;
            };
            };
        }
        else if (consoleType==ConsoleType::XBOX) {

            std::cout<<"Printing all Xbox data"<<std::endl;
            
            if (!xbx.empty()) {
                // std::cout<<"Printing all Xbox data"<<std::endl;
            for (auto & curr:xbx) {

                std::cout<<"Xbox with price: "<<curr.price<<", quality: "<<curr.quality<<std::endl;
            };
            };
        };
    };
};




#endif