// INFIX EVALUATION
#include <iostream>
#include <cmath>
#include <string>
#include <stack>

using namespace std;

int priority(char ch) {
    if(ch == '^')     return 3;
    if(ch == '/'  || ch == '*')     return 2;
    if(ch == '+'  || ch == '-')     return 1;
    return 0; // fallback for non-operator chars
}

int solve(int val1, int val2, char ch) {
    if(ch == '^') return (pow(val1, val2));
    else if(ch == '*')   return val1 * val2;
    else if(ch == '/')   return val1 / val2;
    else if(ch == '+')   return val1 + val2;
    else    return val1 - val2;
}

int main () {
    string s = "1+2*5^2-9/3";
    // we need two stacks one for operators and  another for operands
    stack<int> val;
    stack<char> op;
    for(int i = 0; i < s.size(); i++) {
        // Step 1:-> Check if s[i] is value or opearator
        if (isdigit(s[i])) {   // s[i] is value 
            int num = 0;
            while (i < s.size() && isdigit(s[i])) {
                num = num * 10 + (s[i] - '0');
                i++;
            }
            val.push(num);
            i--; // adjust outer loop
        }   
        else {      // s[i] is operator
                while (!op.empty() && ((priority(s[i]) < priority(op.top())) || (priority(s[i]) == priority(op.top()) && s[i] != '^'))) {
                        char ch = op.top();
                        op.pop();

                        int val2 = val.top();
                        val.pop();

                        int val1 = val.top();
                        val.pop();
                        
                        val.push(solve(val1, val2, ch));
                }
                op.push(s[i]);
        }
    }

    while(!op.empty()) {
        char ch = op.top();
        op.pop();
        int val2 = val.top();
        val.pop();

        int val1 = val.top();
        val.pop();
                        
        val.push(solve(val1, val2, ch));
    }
    
    cout << val.top() << endl;

    return 0;
}