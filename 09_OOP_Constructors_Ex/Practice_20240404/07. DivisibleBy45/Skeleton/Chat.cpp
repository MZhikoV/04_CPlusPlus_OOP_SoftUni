#include <iostream>
#include "BigInt.h"

bool isDivisibleBy45(const BigInt& num) {
    // Check if the number is divisible by 45
    // A number is divisible by 45 if it is divisible by both 5 and 9
    return num % 5 == 0 && num % 9 == 0;
}

int main() {
    BigInt S, E;
    std::cin >> S >> E;

    BigInt current = S;

    while (current < E) {
        if (isDivisibleBy45(current)) {
            std::cout << current << std::endl;
        }
        current += 1;
    }

    return 0;
}