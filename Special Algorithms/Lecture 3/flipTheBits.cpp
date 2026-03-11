// FLIP THE BITS OF A NUMBER WHEN IT IS CONVERTED TO BINARY NUMBER
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
    int n = 22;   // 10110  -> 01001

    cout << ((2 * smaller(n) - 1) ^ n) << endl;   // 8 + 1 = 9

    cout << ((max_powerOf_2(n) - 1) ^ n) << endl; // 9

    return 0;
}