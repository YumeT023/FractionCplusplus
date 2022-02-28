#ifndef ZFRACTION_H
#define ZFRACTION_H

#include <iostream>
class Zfraction
{
    public:
        // dtor
        ~Zfraction();
        // ctor
        Zfraction();
        Zfraction(int numerator);
        Zfraction(int numerator, int denominator);
        bool isEqual(Zfraction const& x) const;
        bool isLess(Zfraction const& x) const;
        void display(std::ostream &stream) const;
        void simplify();
        Zfraction& operator+=(Zfraction const& x);
        Zfraction& operator-=(Zfraction const& x);
        Zfraction& operator*=(Zfraction const& x);
        Zfraction& operator/=(Zfraction const& x);

    private:
        int num, den;
};
// pgcd for simplifying
int pgcd(int x, int y);
// comparison
bool operator==(Zfraction const& x, Zfraction const& y);
bool operator!=(Zfraction const& x, Zfraction const& y);
bool operator>(Zfraction const& x, Zfraction const& y);
bool operator<(Zfraction const& x, Zfraction const& y);
bool operator>=(Zfraction const& x, Zfraction const& y);
bool operator<=(Zfraction const& x, Zfraction const& y);
// calculating
Zfraction operator+(Zfraction const& x, Zfraction const& y);
Zfraction operator-(Zfraction const& x, Zfraction const& y);
Zfraction operator*(Zfraction const& x, Zfraction const& y);
Zfraction operator/(Zfraction const& x, Zfraction const& y);
std::ostream& operator<<(std::ostream& stream, Zfraction const& x);


#endif // ZFRACTION_H
