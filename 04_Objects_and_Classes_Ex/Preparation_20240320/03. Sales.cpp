#include <iostream>
#include <string>
#include <sstream>
#include <map>
#include <set>
#include <vector>
#include <algorithm>
#include <iomanip>
#include <stack>

using namespace std;

class Sales {

    private:

    map<string, double> salesM;
    string town;
    string product;
    double price;
    double quantity;

    public:

    Sales() : price(0),quantity(0) {};

    

    void setInput(string & input);

    string getResults();

};

    string Sales::getResults() {
        ostringstream outp;
        for (map<string,double>::iterator it1=salesM.begin(); it1!=salesM.end();it1++) {
            outp<<fixed<<setprecision(2);
            outp<<it1->first<<" -> "<<it1->second<<endl;
        };
        return outp.str();
    }


    void Sales::setInput(string & input)  {
            istringstream istr(input);
            istr>>town>>product>>price>>quantity;
            salesM[town]+=this->price * this->quantity;
        };


int main() {

    int num;
    cin>>num;
    cin.ignore();

    Sales prod;

    while (num--) {
        string buffer;
        getline(cin,buffer);

        prod.setInput(buffer);
    }

    cout<<fixed<<setprecision(2);
    cout<<prod.getResults()<<endl;
    
    
    system("pause");
    return 0;
}
