// PRINT FACTORIAL OF FIRST 25 NATURAL NUMBER WITH MODULO 10e9 + 7
#include <iostream>
#include <vector>

using namespace std;

vector<long long int> factorial(int n) {
    vector <long long int> fact(n + 1, 1);
    int c = 1000000007;
    for(int i = 2; i < n + 1; i++) {
        fact[i] = ((i % c) * (fact[i - 1] % c)) % c;
    }
    return fact;
}

int main() {
    vector<long long int> res = factorial(25);
    int j = 0;
    for(long long int i : res) {
        cout << j++ << "! = " << i <<endl;
    }
    return 0;
}










