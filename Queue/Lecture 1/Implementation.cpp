#include <iostream>
#include <queue>
#include <stack>

using namespace std;

void reverseQueue(queue<int> &q) {
    stack<int> st;
    while(!q.empty()) {
        st.push(q.front());
        q.pop();
    }
    while(!st.empty()) {
        q.push(st.top());
        st.pop();
    }
}

void display(queue<int> q) {
    while(!q.empty()) {
        cout << q.front() <<" ";
        q.pop();
    }
    cout << endl;
}

int main() {
    queue<int> q;
    q.push(10);
    q.push(20);
    q.push(30);
    q.push(40);
    q.push(50);
    q.push(60);
    q.push(70);
    
    display(q);

    reverseQueue(q);
    
    display(q);

    return 0;
}