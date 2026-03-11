// REVERSE STACK
#include <iostream>
#include <stack>

using namespace std;

void display(stack<int> st) {
    cout << "List: ";
    while(!st.empty()) {
        cout << st.top() << " ";
        st.pop();
    }
    cout << endl;
}

int main() {
    stack<int> st;
    cout << "Enter the number of elements: ";
    int n;
    cin >> n;
    cout << "Enter the elements: ";
    for(int i = 0; i < n; i++) {
        int temp;
        cin >> temp;
        st.push(temp);     // 1 2 3 4 5
    }
    display(st);

    // REVERSE STACK
    stack<int> temp1;
    stack<int> temp2;

    while(!st.empty()) {
        temp1.push(st.top());
        st.pop();
    }

    while(!temp1.empty()) {
        temp2.push(temp1.top());
        temp1.pop();
    }

    while(!temp2.empty()) {
        st.push(temp2.top());     // 5 4 3 2 1 
        temp2.pop();
    }
    display(st);

    return 0;
}