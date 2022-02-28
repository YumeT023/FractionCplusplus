#include <iostream>
#include <vector>
#include "Zfraction.h"

// desctructor
Zfraction::~Zfraction() { }
// constructor
Zfraction::Zfraction(int numerator, int denominator) :num(numerator), den(denominator) { simplify(); }
Zfraction::Zfraction(int numerator) :num(numerator), den(1) { }
Zfraction::Zfraction() :num(0), den(1) { }


// methods
bool Zfraction::isEqual(Zfraction const& x) const {
    return (num == x.num && den == x.den);
}
bool Zfraction::isLess(Zfraction const& x) const {
    return (num * x.den) < (den * x.num);
}

bool operator==(Zfraction const& x, Zfraction const& y){
    return x.isEqual(y);
}

bool operator!=(Zfraction const& x, Zfraction const& y) {
    return !(x == y);
}

bool operator<(Zfraction const& x, Zfraction const& y) {
    return x.isLess(y);
}

bool operator>(Zfraction const& x, Zfraction const& y) {
    return y < x;
}

bool operator<=(Zfraction const& x, Zfraction const& y) {
    // if y is less or equal than x => that means x is less
    return !(x > y);
}

bool operator>=(Zfraction const& x, Zfraction const& y) {
    return !(y > x);
}

void Zfraction::display(std::ostream& stream) const {
    stream << num << "/" << den;
}
std::ostream& operator<<(std::ostream& stream, Zfraction const& x) {
    x.display(stream);
    return stream;
}

void Zfraction::simplify() {
    int a(num), b(den);
    num /= pgcd(a, b);
    den /= pgcd(a, b);
}


// normal operator
Zfraction operator+(Zfraction const& x, Zfraction const& y) {
    Zfraction z(x);
    z += y;
    return z;
}
Zfraction operator-(Zfraction const& x, Zfraction const& y) {
    Zfraction z(x);
    z -= y;
    return z;
}
Zfraction operator*(Zfraction const& x, Zfraction const& y) {
    Zfraction z(x);
    z *= y;
    return z;
}
Zfraction operator/(Zfraction const& x, Zfraction const& y) {
    Zfraction z(x);
    z /= y;
    return z;
}

// shortcut operator
Zfraction& Zfraction::operator+=(Zfraction const& x) {
    num = (num * x.den) + (den * x.num);
    den *= x.den;
    simplify();
    return *this;
}
Zfraction& Zfraction::operator-=(Zfraction const& x) {
    num = (num * x.den) - (den * x.num);
    den *= x.den;
    simplify();
    return *this;
}
Zfraction& Zfraction::operator*=(Zfraction const& x) {
    num *= x.num;
    den *= x.den;
    simplify();
    return *this;
}
Zfraction& Zfraction::operator/=(Zfraction const& x) {
    num *= x.den;
    den *= x.num;
    simplify();
    return *this;
}


int pgcd(int x, int y) {
    if (x == y)
        return x;
    if (x > y)
        return pgcd(x - y, x);
    if (x < y)
        return pgcd(x, y - x);
}
