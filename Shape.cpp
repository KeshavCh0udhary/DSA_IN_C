#include <iostream>
#include <string>

using namespace std;

// Base class Shape
class Shape {
protected:
    string name;

public:
    void setName(const string& shapeName) {
        name =    shapeName;
    }

    string getName() const {
        return name;
    }

    virtual double area() const = 0; // Pure virtual function
};

// Derived class Rectangle
class Rectangle : public Shape {
private:
    double length,   width;

public:
    Rectangle(double l, double w) : length(l), width(w) {
        setName("Rectangle");
    }

    double area() const override {
        return length * width;
    }
};

// Derived class Square
class Square : public Shape {
private:
    double side;

public:
    Square(double s) : side(s) {
        setName("Square");
    }

    double area() const override {
        return side * side;
    }
};

int main() {
    Rectangle rect(5, 3);
    Square sq(4);

    cout << "Area of " << rect.getName() << ": " << rect.area() << endl;
    cout << "Area of " << sq.getName() << ": " << sq.area() << endl;

    return 0;
}
