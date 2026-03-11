
#include <iostream>
#include <stack>

using namespace std;

stack<int> pushAtAnyIndex(stack<int> &st, int val, int idx) {
    stack<int> temp;
    int n = st.size();

    if(idx > st.size() - 1 || idx < 0) {
        cout << "Invalid Index";
        return st;
    }

    // push at top
    if(idx == st.size() - 1) {
        st.push(val);
        return st;
    }

    //push at any index except top
    for(int i = 0; i < n - idx; i++) {
        temp.push(st.top());
        st.pop();
    }
    st.push(val);
    while(!temp.empty()) {
        st.push(temp.top());
        temp.pop();
    }

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
    cout << "Given List:\n";
    display(st);

    cout << "After insertion: \n";
    pushAtAnyIndex(st, 7, 4);    
    display(st);

    return 0;
}