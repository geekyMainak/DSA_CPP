// COUNT NUMBER OF FLIPS TO CONVERT A NUMBER TO A ANOTHER NUMBER  ( 5(101)  -->  2(010)  no. flips = 3)
#include <iostream>

using namespace std;

int max_powerOf2(int n) {
    n |= (n >> 1);
    n |= (n >> 2);
    n |= (n >> 4);
    n |= (n >> 8);
    n |= (n >> 16);

    return n;
}

int main() {
    int n = 39;   // 100111
    cout << (max_powerOf2(n) ^ n)<< endl;   // 011000

    return 0;
}
