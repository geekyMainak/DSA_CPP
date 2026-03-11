#include <iostream>
#include <stack>
#include <cmath>
#include <string>
#include <cctype>
#include <sstream>

using namespace std;

int priority(char op) {
    if (op == '^') return 3;
    if (op == '*' || op == '/') return 2;
    if (op == '+' || op == '-') return 1;
    return 0;
}

string infixToPostfix(const string& expr) {
    stack<char> ops;
    stringstream postfix;
    for (int i = 0; i < expr.size(); ) {
        if (isspace(expr[i])) {
            i++;
        }
        else if (isdigit(expr[i]) || expr[i] == '.') {
            while (i < expr.size() && (isdigit(expr[i]) || expr[i] == '.')) {
                postfix << expr[i++];
            }
            postfix << ' ';
        }
        else if (expr[i] == '(') {
            ops.push(expr[i++]);
        }
        else if (expr[i] == ')') {
            while (!ops.empty() && ops.top() != '(') {
                postfix << ops.top() << ' ';
                ops.pop();
            }
            ops.pop(); i++; // pop '('
        }
        else {
            while (!ops.empty() && priority(expr[i]) <= priority(ops.top()) && ops.top() != '(') {
                postfix << ops.top() << ' ';
                ops.pop();
            }
            ops.push(expr[i++]);
        }
    }

    while (!ops.empty()) {
        postfix << ops.top() << ' ';
        ops.pop();
    }

    return postfix.str();
}

int main() {
    string expr = "3.5 + (2*4)-5^2";
    cout << "Postfix: " << infixToPostfix(expr) << endl;
    //cout << "Prefix: " << infixToPrefix(expr) << endl;
}
