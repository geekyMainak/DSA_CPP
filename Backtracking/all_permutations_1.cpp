#include <bits/stdc++.h>
using namespace std;

// permutation(str , i)   -->   generate all the permutations of str of length i
void permutation(string &str, int i) {
    if(i == str.size()-1) {
        cout << str << "\n";
        return;
    }

    for(int idx = i; idx < str.size(); idx++) {
        swap(str[idx], str[i]);
        permutation(str, i+1);
        swap(str[idx], str[i]);
    }
}

int main () {
    string a;
    cin >> a;

    cout << "All permutations are :\n";
    permutation(a, 0);

    return 0;
}