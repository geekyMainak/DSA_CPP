#include <iostream>

using namespace std;

int nthFibonacci(int n) {
    // base case
    if(n == 1 || n==2)  return 1;
    return nthFibonacci(n - 1) + nthFibonacci(n - 2);
}

int main() {
    cout << "Enter any number:- ";
    int n;
    cin >> n;
    int k = nthFibonacci(n);
    cout << k;
    return 0;
}