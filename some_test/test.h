//copy constructor

class SomeRandom {
    int method1;
    int method2;
    public:
        SomeRandom (const SomeRandom& other) : method1(other.method1), method2(other.method2) {};

    //copy assignment
        SomeRandom& operator=(const SomeRandom& other) {
            this->method1=other.method1;
            this->method2=other.method2;
            return *this;
        } 
};