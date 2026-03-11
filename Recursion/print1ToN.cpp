#include <iostream>

using namespace std;

void print1ToN_alternate(int n) {
    // base case
    if(n == 0)  return ;
    print1ToN_alternate(n - 1);
    cout << n << endl;
}

void print1ToN(int i, int n) {
    // base case
    if(n == 0)  return ;
    cout << i << endl;
    print1ToN(i + 1, n - 1);
}

int main() {
    cout<<"Enter any number\t";
    int n;
    cin>>n;
    print1ToN(1, n);
    print1ToN_alternate(n);
return 0;
}

