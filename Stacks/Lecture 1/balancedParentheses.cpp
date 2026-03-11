#include <iostream>
#include <stack>
#include <string>
using namespace std;

class Solution {
public:
    bool isMatching(char open, char close) {
        if (open == '(' && close == ')') return true;
        if (open == '[' && close == ']') return true;
        if (open == '{' && close == '}') return true;
        return false;
    }

    bool isValid(string s) {
        stack<char> st;

        for (int i = 0; i < s.size(); i++) {
            if (s[i] == '(' || s[i] == '{' || s[i] == '[') {
                st.push(s[i]);
            } else {
                if (st.empty()) return false;

                if (isMatching(st.top(), s[i])) {
                    st.pop();
                } else {
                    return false;
                }
            }
        }

        return st.empty(); 
    }
};

int main() {
    Solution sol;
    string s = "{[(]}";
    cout << (sol.isValid(s) ? "Valid" : "Invalid") << endl;
    return 0;
}

