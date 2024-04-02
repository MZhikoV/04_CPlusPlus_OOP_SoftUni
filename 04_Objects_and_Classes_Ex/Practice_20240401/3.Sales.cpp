#include <iostream>
#include <string>
#include <sstream>
#include <map>
#include <iomanip>


using namespace std;

int main() {

class Sale {
    string town;
    string product;
    double price;
    double quantity;

    public:
    Sale(string inp) {
        istringstream istr(inp);
        istr>>town>>product>>price>>quantity;
    };

    string getTown() {
        return town;
    };

    string getProduct() {
        return product;
    };

    double getPrice() {
        return price;
    };

    double getQuantity() {
        return quantity;
    };

};

map<string, double> towns;


int num;
cin>>num;
cin.ignore();
string input;
while (num--) {
    getline(cin,input);
    Sale a(input);

    towns[a.getTown()]+=(a.getQuantity()*a.getPrice());

};

bool isFirst=true;
for (auto prod:towns) {
    cout<<prod.first<<" -> "<<fixed<<setprecision(2)<<prod.second<<endl;
    // if (isFirst) {
    //     isFirst=false;
    // }
    // else {

    // }
};


system("pause");
return 0;
};