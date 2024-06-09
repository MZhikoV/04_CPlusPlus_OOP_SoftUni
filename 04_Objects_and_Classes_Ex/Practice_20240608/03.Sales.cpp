#include <iostream>
#include <string>
#include <map>
#include <sstream>
#include <iomanip>

using namespace std;

class Sale {
    string town;
    string product;
    double price;
    double quantity;
    map<string,double> totalSales;

public:
    Sale() : price(0), quantity(0) {};
    void setInfo(string input) {
        istringstream istr(input);
        istr>>town>>product>>price>>quantity;
        totalSales[town]+=(price*quantity);
    }

    void print() const {
        for (auto el:totalSales) {
            cout<<fixed<<setprecision(2)<<el.first<<" -> "<<el.second<<endl;
        };
    };
};

int main() {

    Sale elemets;

    int products;
    cin>>products;
    cin.ignore();

    string input;

    while (products--) {
        getline(cin,input);
        elemets.setInfo(input);
    };

    elemets.print();

    system("pause");
    return 0;
}