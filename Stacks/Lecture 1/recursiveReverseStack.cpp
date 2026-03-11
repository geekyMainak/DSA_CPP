// RECURSIVE REVERSE STACK
// REVERSE STACK
#include <iostream>
#include <stack>

using namespace std;

// REVERSE STACK USING RECURSION
void reverseStackRecursive(stack<int> &st) {   
    if(st.size() == 0)    return;
    int x = st.top();
    st.pop();
    reverseStackRecursive(st);
    st.push(x);
}

void display(stack<int> st) {
    while(!st.empty()) {
        cout << st.top() << "\n";
        st.pop();
    }
    cout << endl;
}

void displayRecursive(stack<int> &st) {
    if(st.size() == 0)    return;
    cout << st.top() <<"\n";
    int x = st.top();
    st.pop();
    displayRecursive(st);
    st.push(x);
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
    cout << "List:\n";
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
    cout << "List:\n";
    display(st);
    cout << "List:\n";
    reverseStackRecursive(st);
    displayRecursive(st);

    return 0;
}