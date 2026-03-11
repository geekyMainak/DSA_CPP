// STAIR PATH PROBLEM WHEN 1 STEP OR 2 STEPS ARE ALLOWED
#include <iostream>

using namespace std;

int stairPath(int n) {
    // base case
    if(n == 1)  return 1;
    else if(n == 2) return 2;

    return stairPath(n - 1) + stairPath(n - 2); 
}

int main() {
    cout << "Enter any number:- ";
    int n;
    cin >> n;
    int k = stairPath(n);
    cout << k;
    return 0;
}
