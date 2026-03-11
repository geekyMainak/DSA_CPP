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

double solve(double a, double b, char op) {
    switch (op) {
        case '^': return pow(a, b);
        case '*': return a * b;
        case '/': return a / b;
        case '+': return a + b;
        case '-': return a - b;
    }
    return 0;
}

void compute(stack<double>& values, stack<char>& ops) {
    double b = values.top(); values.pop();
    double a = values.top(); values.pop();
    char op = ops.top(); ops.pop();
    values.push(solve(a, b, op));
}

double evaluate(const string& expr) {
    stack<double> values;
    stack<char> ops;
    int n = expr.length();
    
    for (int i = 0; i < n; ) {
        if (isspace(expr[i])) {
            i++;
        }
        else if (expr[i] == '(') {
            ops.push(expr[i]);
            i++;
        }
        else if (expr[i] == ')') {
            while (!ops.empty() && ops.top() != '(') {
                compute(values, ops);
            }
            ops.pop(); // remove '('
            i++;
        }
        else if (isdigit(expr[i]) || expr[i] == '.' || 
                 (expr[i] == '-' && (i == 0 || expr[i - 1] == '(' || priority(expr[i - 1])))) {
            // Read number or unary minus
            int sign = 1;
            if (expr[i] == '-') {
                sign = -1;
                i++;
            }
            double num = 0;
            bool hasDecimal = false;
            double frac = 0.1;
            while (i < n && (isdigit(expr[i]) || expr[i] == '.')) {
                if (expr[i] == '.') {
                    hasDecimal = true;
                    i++;
                }
                else if (!hasDecimal) {
                    num = num * 10 + (expr[i++] - '0');
                }
                else {
                    num = num + (expr[i++] - '0') * frac;
                    frac *= 0.1;
                }
            }
            values.push(num * sign);
        }
        else {
            while (!ops.empty() && 
                   ((priority(expr[i]) < priority(ops.top())) ||
                    (priority(expr[i]) == priority(ops.top()) && expr[i] != '^')) &&
                   ops.top() != '(') {
                compute(values, ops);
            }
            ops.push(expr[i]);
            i++;
        }
    }

    while (!ops.empty()) {
        compute(values, ops);
    }

    return values.top();
}

int main() {
    string expr = "-3.5 + (2.1 * 4) - 5^2 / (3 + 2)";
    cout << "Result: " << evaluate(expr) << endl;
    
    return 0;
}
