#include <iostream>
#include <string>
#include <sstream>
#include <map>
#include <set>
#include <vector>
#include <algorithm>
#include <queue>
#include <stack>

using namespace std;

int f(void) {
    static int A=2;
    return A++;
};


int main() {
    
    int x;
    x=9/2;
    cout<<x;

    int a=sizeof(int);
    cout<<a<<endl;
    
    unsigned a1,a2,b1;
    a1=0xAAAAAAAA;
    b1=0x55555555;
    a2=a1&b1;
    cout<<a2<<endl;

    // uint16_t* d1=(void *)0x10001234;
    // d1+=4;
    // cout<<d1<<endl;


    struct A{
        char A[101];
    };

    struct A *g=NULL;
    printf("%d",sizeof(x)>1000);

    cout<<endl;

    // unsigned int f(unsigned int h) {
    //     h&="(1<<12);
    //     return h;
    // };


    printf("%x", 32);
    cout<<endl;

    printf("%x", -1);
    cout<<endl;

    int aaa,bbb,ccc;
    aaa=f();
    bbb=f();
    ccc=f();
    printf("%d %d %d",aaa,bbb,ccc);
    cout<<endl;

    int lele=2^5;
    cout<<lele<<endl;


    system("pause");
    return 0;
}
