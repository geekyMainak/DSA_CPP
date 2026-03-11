#include <iostream>

using namespace std;

int sum1ToN_alternate(int n) {
    // base case
    if(n == 0)  return 0;
    return n + sum1ToN_alternate(n - 1);
}

int sum1ToN(int i, int n) {
    // base case
    if(n == 0)  return 0;
    return i + sum1ToN(i + 1, n - 1);
}

int main() {
    cout<<"Enter any number\t";
    int n;
    cin>>n;
    cout<<sum1ToN(1, n)<<endl;
    cout<<sum1ToN_alternate(n);
return 0;
}

