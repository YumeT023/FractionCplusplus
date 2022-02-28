#include <iostream>
#include <Zfraction.h>
#include <vector>

using namespace std;

int main()
{
    Zfraction x(2,3); // 0.375
    Zfraction y(5,3); // 0.75

    cout << "some test below : " << endl;

    cout << x << " + " << y << " = " << x + y << endl;// 7/3
    cout << x << " * " << y << " = " << x * y << endl;// 10/9
    // true : 1, false : 0
    cout << "1: true     0:false" << endl;
    cout << x << " > " << y << " = " << (x > y) << endl;// false : 0
    cout << x << " < " << y << " = " << (x < y) << endl;// true : 1
}
