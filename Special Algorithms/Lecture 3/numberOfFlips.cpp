// COUNT NUMBER OF FLIPS TO CONVERT A NUMBER TO A ANOTHER NUMBER  ( 5(0101)  -->  11(1011)  no. flips = 3)
#include <iostream>

using namespace std;

int countSetBits(int n) {
    int count = 0;
    while(n) {
        n &= (n - 1);
        count++;
    }
    return count;
}

int main() {
    int x = 23; // 010111
    int y = 32; // 100000
    cout << countSetBits(x^y)<< endl;    // 5

    return 0;
}
