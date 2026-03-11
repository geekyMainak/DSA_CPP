// EXPONENT OF 2 SMALLER AND GREATER THAN A NUMBER (BRIAN KERNIGHAN ALGORITHM)
#include <iostream>

using namespace std;

int min_powerOf_2(int n) {
    n = n | (n >> 1);
    n = n | (n >> 2);
    n = n | (n >> 4);
    n = n | (n >> 8);
    n = n | (n >> 16);

    return (n+1) >> 1;
}

int max_powerOf_2(int n) {
    n = n | (n >> 1);
    n = n | (n >> 2);
    n = n | (n >> 4);
    n = n | (n >> 8);
    n = n | (n >> 16);

    return n+1;
}

int smaller(int n) {
    int prev;
    while(n) {
        prev = n;
        n &= (n - 1);
    }
    return prev;
}

int main() {
    int n = 260;
    cout << smaller(n) << endl;
    cout << 2 * smaller(n) << endl;
    cout << min_powerOf_2(n) << endl;
    cout << max_powerOf_2(n) << endl;

    return 0;
}