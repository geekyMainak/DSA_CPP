// REMOVAL OF CHARACTER
#include <iostream>
#include <string>

using namespace std;

// METHOD 1
void removeCharacter(string str, char ch, string s) {
    // base case
    if(str.length() == 0) {
        cout << s;
        return;
    }

    char k = str[0];
    if(k == ch)   removeCharacter(str.substr(1), ch, s);
    else    removeCharacter(str.substr(1), ch, s + k);

}

// METHOD 2
void removeCharacterAlternate(string str, char ch, string s, int idx) {
    // base case
    if(idx == str.length()) {
        cout << s;
        return;
    }

    char k = str[idx];
    if(k == ch)   removeCharacterAlternate(str, ch, s, idx + 1);
    else    removeCharacterAlternate(str, ch, s + k, idx + 1);

}

int main() {
    string str = "mainak modak";
    removeCharacter(str, 'a', "");
    cout << endl;
    removeCharacterAlternate(str, 'k', "", 0);
    return 0;
}
