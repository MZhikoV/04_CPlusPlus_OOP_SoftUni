#include <iostream>
#include <string>

#include "BigInt.h"

std::istream & operator>>(std::istream & istr, BigInt & number) {
    std::string s;
    istr>>s;
    number=BigInt(s);
    return istr;
};

bool divisibleBy45(const BigInt & number) {
    std::string digits=number.getDigits();

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

int main() {

    BigInt first,second;
    std::cin>>first>>second;


    for (BigInt curr=first; curr<second; curr+=1) {
        if (divisibleBy45(curr)){
            std::cout<<curr<<std::endl;
        };
    };



  //  system("pause");

    return 0;
}