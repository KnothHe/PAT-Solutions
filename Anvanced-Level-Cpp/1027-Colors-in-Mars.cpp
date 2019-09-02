#include <iostream>
#include <string>
using namespace std;
const string DIGITS = "0123456789ABC";
int R, G, B;
int main() {
    cin >> R >> G >> B;
    cout << "#" << DIGITS[R/13] << DIGITS[R%13] <<
        DIGITS[G/13] << DIGITS[G%13] <<
        DIGITS[B/13] << DIGITS[B%13];
    return 0;
}

