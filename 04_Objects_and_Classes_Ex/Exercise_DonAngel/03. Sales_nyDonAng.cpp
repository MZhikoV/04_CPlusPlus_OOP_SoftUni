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
    Sale () : price(0),quantity(0) {};
    Sale (istream & istr) {
        istr>>town>>product>>price>>quantity;
    }

    double getPrice() {return price;};
    double getQuantity() {return quantity;};
    double getTotal() {return price*quantity;};
    const string & getTown() {return town;};
};

class Sales {
    public:
    typedef vector<Sale> SalesData;
    
    private:
    SalesData sales;

    public:
    Sales(istream & istr);

    SalesData & getSales(void) {return sales;};
};

Sales::Sales(istream & istr) {
    int salesNum;
    istr>>salesNum;

    sales.reserve(salesNum);

    while (salesNum--){
        sales.push_back(Sale(istr));
    }
}

class ReportPerCity {
    map<string,double> grossSales; //sales per city

    public:
    ReportPerCity(Sales & s);

    void print (ostream & ostr);
};

ReportPerCity::ReportPerCity(Sales & s) {
    
    Sales::SalesData data=s.getSales();

    for (Sale & sale : data) {
        grossSales[sale.getTown()]+=sale.getPrice()*sale.getQuantity();
    }
};

void ReportPerCity::print (ostream & ostr) {

    ostr<<fixed<<setprecision(2);
    for( auto curCity:grossSales) {
        ostr<<curCity.first<<" -> "<<curCity.second<<endl;

    }
};

int main() {
    
    Sales s(cin);

    ReportPerCity r(s);

    r.print(cout);

    system("pause");
    return 0;
}
