// RECURSIVE REVERSE STACK
#include <iostream>
#include <stack>

using namespace std;

void pushAtBottomRecursive(stack<int> &st, int val) {   
    if(st.size() == 0) {
        st.push(val);
        return;
    }
    int x = st.top();
    st.pop();
    pushAtBottomRecursive(st, val);
    st.push(x);
}

void reverseStackRecursive(stack<int> &st) {
    // base case
    if(st.size() == 0)  return;

    int val = st.top();
    st.pop();
    reverseStackRecursive(st);
    pushAtBottomRecursive(st, val);
}

void display(stack<int> st) {
    while(!st.empty()) {
        cout << st.top() << "\n";
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
    cout << "List:\n";
    display(st);

    cout << "Reverse Stack:\n";
    reverseStackRecursive(st);
    display(st);

    return 0;
}