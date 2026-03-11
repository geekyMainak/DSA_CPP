// SUBARRAYS
#include <iostream>
#include <string>

using namespace std;

bool isPalindrome(string s, int i, int j) {
    // base case
    if(i > j)   return true;

    if(s[i] != s[j])    return false;
    return isPalindrome(s, i+1, j-1);
}

int main() {
    string s = "mopm";
    if(isPalindrome(s,0,s.length() - 1))    cout << "YES";
    else    cout << "NO";
    return 0;
}