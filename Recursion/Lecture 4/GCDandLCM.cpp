// GCD USING EUCLID'S DIVISION ALGORITHM AND LCM
#include <iostream>

using namespace std;

int gcd(int a, int b) {
    // base case
    if(a == 0)  return b;
    
    return gcd(b % a, a);
}

int main() {
    int a = 24;
    int b = 60;
    cout << gcd(a,b) <<endl;
    cout << (a * b) / gcd(a,b);
    return 0;
}