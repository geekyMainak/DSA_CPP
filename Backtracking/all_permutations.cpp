#include <bits/stdc++.h>
using namespace std;

void permutation(string str, string ans) {
    if(str == "") {
        cout << ans << "\n";
        return;
    }  

    for(int i = 0; i < str.size(); i++) {
        char ch = str[i];

        string left = str.substr(0, i);
        string right = str.substr(i+1);
        string ros = left + right;

        permutation(ros, ans + ch);
    }
}

int main () {
    string a;
    cin >> a;

    cout << "All permutations are :\n";
    permutation(a, "");

    return 0;
}