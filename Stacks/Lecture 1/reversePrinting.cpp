// Reverse Printing
#include <iostream>
#include <stack>

using namespace std;

int main() {
    stack<int> st;
    cout << "Enter the number of elements: ";
    int n;
    cin >> n;
    cout << "Given List: ";
    for(int i = 0; i < n; i++) {
        int temp;
        cin >> temp;
        st.push(temp);
    }

    cout << "Reverse List: ";
    while(!st.empty()) {
        cout << st.top() << " ";
        st.pop();
    }

    return 0;
}