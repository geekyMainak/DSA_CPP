#include <iostream>
#include <vector>
#include <string>

using namespace std;

int kthSymbolInGrammar(int n, int k, int flip) {
    // base case
    if(n == 0)     return flip % 2;

    if(k % 2 == 0)      return  kthSymbolInGrammar(n - 1,  k / 2, flip + 1);
    else    return  kthSymbolInGrammar(n - 1,  (k + 1) / 2, flip + 0);

}

int main() {
    int n = 6;
    int k = 7;
    int ans = kthSymbolInGrammar(n - 1, k, 0);
    cout << ans;
    return 0;
}