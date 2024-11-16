#include <iostream>
#include <string>
#include <sstream>
#include <map>
#include <vector>
#include <iomanip>

class Sale {
    std::string town;
    std::string prod;
    double price;
    double quantity;

    public:
    Sale(std::string town, std::string prod, double price, double quantity) : 
        town(town), prod(prod), price(price), quantity(quantity) {};

    std::string getTown() {
        return town;
    };

    double getTotal() {
        return price*quantity;
    }
};

int main() {

    std::vector<Sale> sales;
    std::map<std::string,double> towns;

    int n;
    std::string tmp;
    std::getline(std::cin,tmp);
    n=stoi(tmp);

    while (n--) {
        std::string inp;
        std::getline(std::cin,inp);
        std::istringstream istr(inp);
        std::string inpTown, inpProd;
        double inpPrice, inpQuan;
        istr>>inpTown>>inpProd>>inpPrice>>inpQuan;
        Sale sale(inpTown,inpProd,inpPrice,inpQuan);
        sales.push_back(sale);
    };

    for (auto curr:sales) {
        towns[curr.getTown()]+=curr.getTotal();
    };

    for (auto currT:towns) {
        std::cout<<currT.first<<" -> "<<std::fixed<<std::setprecision(2)<<currT.second<<std::endl;
    };
    


    system("pause");
    return 0;
}