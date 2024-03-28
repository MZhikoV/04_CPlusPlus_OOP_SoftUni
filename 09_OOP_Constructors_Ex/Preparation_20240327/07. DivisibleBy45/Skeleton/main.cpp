#include <iostream>
#include <string>


#include "BigInt.h"

using namespace std;

istream & operator >> (istream & istr, BigInt & rightH) {
    string s;
    istr>>s;
    rightH=BigInt(s);
    return istr;
};

bool isDivisibleby45(const BigInt & num) {
    string digits=num.getDigits();

    char lastDigit=digits.back();

    if(lastDigit!='5' && lastDigit!='0') {
        return false; //the number is not divided by 5
    };

    unsigned long sum=0;

    for (char c:digits) {
        sum+=c-'0';
    };
    
    return (sum%9==0);
};

int main() {

    BigInt s,e;
    cin>>s>>e;

    for(BigInt curr=s; curr<e; curr+=1) {
        if (isDivisibleby45(curr)){
        cout<<curr<<endl;
        };
    };



 //   system ("pause");
    return 0;
}