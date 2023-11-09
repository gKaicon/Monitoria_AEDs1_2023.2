#include "func.cpp"
#include <iostream>

using namespace std;

int main() {
    double a = 10.0, b = 5.0;
    double sum = add(a, b);
    double difference = subtract(a, b);
    double product = multiply(a, b);
    double quotient = divide(a, b);

    cout << "Sum: " << sum << endl;
    cout << "Difference: " << difference << endl;
    cout << "Product: " << product << endl;
    cout << "Quotient: " << quotient << endl;

    return 0;
}
