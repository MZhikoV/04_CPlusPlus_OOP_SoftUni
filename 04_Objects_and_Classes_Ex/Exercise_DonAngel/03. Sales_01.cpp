#include <iostream>
#include <string>
#include <sstream>
#include <map>
#include <set>
#include <vector>
#include <algorithm>
#include <queue>
#include <stack>
#include <iomanip>

using namespace std;

class Sale {
    string town;
    string product;
    double price;
    double quantity;

    public:
    Sale() : price(0),quantity(0) {};
    Sale (istream & istr);

    double getPrice() {return price; };
    double getQuantity() {return quantity;};
    double getTotal() {return price*quantity;};
    string getName() {return town;};

};

    Sale::Sale (istream & istr)  {
        istr>>town>>product>>price>>quantity;
    };


class Sales {
    public:
        typedef vector<Sale> saleVT;
    
    private:
        saleVT allSales;

    public:
        Sales (istream & istr);

    saleVT & getSales(void) {
        return allSales;
    };

};
Sales::Sales (istream & istr) {
    int salesNum;
    istr>>salesNum;

    while (salesNum--) {
        allSales.push_back(Sale(istr));
    }
}

class reportProd {
    map<string,double> report;

    public:

    reportProd(Sales & s);

    string printReport();
};

reportProd:: reportProd(Sales & s) {
    for (auto saleEl:s.getSales()){     //same as Sales::saleVT data=s.getSales(); for (Sales & saleEl :data)
        report[saleEl.getName()]+=saleEl.getTotal();
    }
};

string reportProd::printReport() {
    ostringstream ostr;
    for (auto reprtEl:report) {
        ostr<<reprtEl.first<<" -> "<<fixed<<setprecision(2)<<reprtEl.second<<endl;
    };
    return ostr.str();
}


int main() {

    Sales sale1(cin);

    reportProd report1(sale1);

    cout<<report1.printReport();
    
    
    system("pause");
    return 0;
}
