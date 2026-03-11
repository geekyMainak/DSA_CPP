#include <bits/stdc++.h>
using namespace std;

vector<int> sieveofEratosthenes (int n) {
    vector<int> ans;
    vector<bool> prime(n+1, true);
    prime[0] = prime[1] = false;

    for(int i = 2; i*i <= n; i++) {
        if(prime[i]) {
            for(int j = i*i; j <= n; j+=i) {
                prime[j] = false;
            }
        }
    }
    for(int i = 0; i <= n; i++) 
        if(prime[i])    ans.push_back(i);

    return ans;
}

int main () {
    int n;
    cin >> n;
    bool flag = false;

    vector<int> primes = sieveofEratosthenes(n);
    int i = 0, j = primes.size() - 1;
    while(i < j) {
        int sum = primes[i] + primes[j];
        if(sum == n) {
            flag = true;
            break;
        }
        if(sum < n)     i++;
        else            j--;
    }

    if(flag)    cout << primes[i] << " " << primes[j] << endl;
    else        cout << -1 << endl;

    return 0;
}