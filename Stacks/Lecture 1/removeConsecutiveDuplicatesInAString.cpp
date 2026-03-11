// Remove Consecutive Duplicates In A String
#include <iostream>
#include <string>
#include <stack>

using namespace std;

string removeConsecutiveDuplicatesInAString(string s) {
    string result = "";    // here I treat empty string as a stack

    for(int i = 0; i < s.size(); i++) {
        if(!result.empty() && result.back() == s[i])    continue;
        else    result.push_back(s[i]);
    }
    return result;
}

int main() {
    string s = "aaabbbccdefgghiiiiiiijklll";
    string ans = removeConsecutiveDuplicatesInAString(s);
    cout << ans;

    return 0;
}