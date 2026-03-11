#include <bits/stdc++.h>
using namespace std;   

int main () {
    int n;
    cin >> n;

    // Sieve of Eratosthenes
    vector<bool> prime(n+1, true);
    prime[0] = prime[1] = false;

    for(int i = 2; i*i <= n; i++) {
        if(prime[i]) {
            for(int j = i*i; j <= n; j += i) {
                prime[j] = false;
            }
        }
    }

    cout << "Prime numbers up to " << n << " are: ";
    for(int i = 0; i <= n; i++) {
        if(prime[i])   cout << i << " ";
    }
    cout << endl;

    return 0;
}