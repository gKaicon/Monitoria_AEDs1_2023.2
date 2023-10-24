#include "header.h"
#include <iostream>

int main() {
    double a = 10.0, b = 5.0;
    double sum = add(a, b);
    double difference = subtract(a, b);
    double product = multiply(a, b);
    double quotient = divide(a, b);

    std::cout << "Sum: " << sum << std::endl;
    std::cout << "Difference: " << difference << std::endl;
    std::cout << "Product: " << product << std::endl;
    std::cout << "Quotient: " << quotient << std::endl;

    return 0;
}
