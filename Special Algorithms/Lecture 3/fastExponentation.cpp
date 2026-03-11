// FAST EXPONENTATION T.C. -> O(log exp)  and   S.C. -> O(1)
#include <iostream>

using namespace std;

// Fast exponentiation function
long long fastPow(long long base, long long exp) {
    long long res = 1;
    while (exp > 0) {
        if (exp & 1) res *= base;   // If the current bit is set, multiply result
        base *= base;               // Square the base
        exp >>= 1;                  // Move to the next bit
    }
    return res;
}

int main() {
    long long base, exponent;
    cout << "Enter base: ";
    cin >> base;
    cout << "Enter exponent: ";
    cin >> exponent;

    long long result = fastPow(base, exponent);
    cout << base << "^" << exponent << " = " << result << endl;

    return 0;
}
