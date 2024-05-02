#include <iostream>
using namespace std;
#include <vector>


template <typename T> struct Cont{
    Cont(): value() {};
    T value;
};

int main() {


Cont<int> obj;

cout<<obj.value<<endl;


   
//    class A{
//     int size;
//     vector<int> B;

//     public:
//     A()=default;
//     ~A() {B.clear();}

//    };



    system("pause");
    return 0;
}
