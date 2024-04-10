#include <iostream>
#include <string>
#include <sstream>

#include"BigInt.h"

using namespace std;

istream & operator >> (istream & istr, BigInt & number) {
    string curr;
    istr>>curr;
    number=BigInt(curr);
    return istr;
};

bool isDivisible45(const BigInt & num ) {
     std::string digits=num.getDigits();

    char lastDigit=digits.back();

    if(lastDigit!='0' && lastDigit!='5'){
        return false; //it doesn't divide to 5
    };

    unsigned long sum=0;
    for (char c:digits) {
        sum+=c-'0';
    }

    return (sum%9==0);

};



int main(void) {

BigInt startS,endS;

cin>>startS>>endS;

for (BigInt curr=startS;curr<endS;curr+=1) {
    if (isDivisible45(curr)) {
        cout<<curr<<endl;
    };
};


//system ("pause");
return 0;
}