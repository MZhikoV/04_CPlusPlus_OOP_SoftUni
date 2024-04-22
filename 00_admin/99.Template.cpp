#include <iostream>

class MyClass {
private:
    int value;

public:
    MyClass(int v) : value(v) {}

    // Getter for the private member
    int getValue() const {
        return value;
    }
};

// Overloading the << operator outside of the class without declaring it as a friend
std::ostream& operator<<(std::ostream& os, const MyClass& obj) {
    os << "MyClass(" << obj.getValue() << ")";  // This will result in a compilation error
    return os;
}

int main() {
    MyClass obj(42);
    std::cout << obj << std::endl;  // This will cause a compilation error
    system("pause");
    return 0;
}
