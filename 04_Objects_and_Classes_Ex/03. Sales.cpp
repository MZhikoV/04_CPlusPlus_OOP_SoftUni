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

typedef map<string,double> mmap;
class Sale {

    private:
    string town;
    string product;
    double price;
    double quantity;
    double totalPrice;
    mmap citySales;

    public:

    void setParameters(string & inpStr) {
        istringstream input(inpStr);
        string inp;
        while (input>>inp) {
            this->town=inp;
            input>>this->product>>this->price>>this->quantity;
            this->totalPrice=price*quantity;
            citySales[town]+=totalPrice;
        }
    }

    string getResult();

};

    string Sale::getResult(){
        ostringstream ostr;
        for (auto el:citySales) {
            ostr<<el.first<<" -> "<<fixed<<setprecision(2)<<el.second<<endl;
        }
        return ostr.str();
    }

int main() {

    int num;
    cin>>num;
    cin.ignore();

    Sale sales;

    while (num>0) {
        string input;
        getline(cin,input);
        sales.setParameters(input);
        num--;
    }

    cout.setf(ios::fixed);
    cout.precision(2);
    cout<<sales.getResult()<<endl;
    
    
    system("pause");
    return 0;
}
