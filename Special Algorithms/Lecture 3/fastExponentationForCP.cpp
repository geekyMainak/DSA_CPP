// FAST EXPONENTATION FOR COMPETITIVE PROGRAMMING    T.C. -> O(log exp)  and   S.C. -> O(1)
#include <iostream>
using namespace std;

const int MOD = 1e9 + 7;

long long fastPowMod(long long base, long long exp, long long mod = MOD) {
    long long res = 1;
    base %= mod;  // Important: reduce base under mod first

    while (exp > 0) {
        if (exp & 1) {
            res = (res * base) % mod;
        }
        base = (base * base) % mod;
        exp >>= 1;
    }
    return res;
}

int main() {
    long long base, exponent;
    cout << "Enter base: ";
    cin >> base;
    cout << "Enter exponent: ";
    cin >> exponent;

    cout << base << "^" << exponent << " mod " << MOD << " = "
         << fastPowMod(base, exponent) << endl;

    return 0;
}
