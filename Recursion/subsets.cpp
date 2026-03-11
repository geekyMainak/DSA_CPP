// SUBSET
#include <iostream>
#include <string>

using namespace std;

// METHOD 1
void subset(string original, string ans) {
    // base case
    if(original.length() == 0) {
        cout <<"[" << ans <<"]" <<" ";
        return;
    }

    char k = original[0];
    subset(original.substr(1), ans);
    subset(original.substr(1), ans + k);

}

// METHOD 2
void subsetAlternate(string str, string s, int idx) {
    // base case
    if(idx == str.length()) {
        cout <<"[" << s <<"]" <<" ";
        return;
    }

    char k = str[idx];
    subsetAlternate(str, s, idx + 1);
    subsetAlternate(str, s + k, idx + 1);

}

int main() {
    string str = "abc";
    subset(str, "");
    cout << endl;
    subsetAlternate(str,"", 0);
    return 0;
}
