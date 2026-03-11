// POWER FUNCTION T.C.-> O(log n)
#include <iostream>

using namespace std;

int pow(int x, int n) {
    // base case
    if(n == 0)  return 1;
    int ans = pow(x, n/2);
    if(n % 2 == 0)     return ans * ans;
    else    return ans * ans * x;
}

int main() {
    cout << "Enter any number:- ";
    int x,n;
    cin >> x;
    cin >> n;
    int k = pow(x,n);
    cout << k;
    return 0;
}
