#include <iostream>

using namespace std;

class Complex {
private:
    double real, imag;

public:
    Complex(double r = 0.0, double i = 0.0) : real(r), imag(i) {}

    friend Complex operator-(const Complex& c); // Unary negation operator

    void display() const {
        cout << real << (imag >= 0 ? "+" : "") << imag << "i" << endl;
    }
};

// Unary negation operator implementation
Complex operator-(const Complex& c) {
    return Complex(-c.real, -c.imag);
}

int main() {
    Complex c1(13, 12);
   // Complex c2(3, 2);
    Complex c2 = - c1;  // Using the unary negation operator

    cout << "Original complex number : ";
    c1.display();

    cout << "Negated complex number: ";
    c2.display();

    return 0;
}
