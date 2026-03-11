// Reorder Queue (Interleave 1st and 2nd Part)
#include <iostream>
#include <vector>
#include <stack>
#include <queue>

using namespace std;

void display(queue<int> q) {
    while(!q.empty()) {
        cout << q.front() <<" ";
        q.pop();
    }
    cout << endl;
}

int main() {
    int n = 8;
    queue<int> q;
    for(int i = 1; i <= n; i++)     q.push(i);
    display(q);

    stack<int> st;
    for(int i = 1; i <= n/2; i++) {
        st.push(q.front());   
        q.pop();
    }   
    for(int i = 1; i <= n/2; i++)  {
        q.push(st.top());     
        st.pop();
    }   
    for(int i = 1; i <= n/2; i++)  {
        st.push(q.front());   
        q.pop();
    }   
    for(int i = 1; i <= n/2; i++) {
        q.push(st.top());   st.pop();
        q.push(q.front());  q.pop();
    } 
    for(int i = 1; i <= n; i++) {
        st.push(q.front());   
        q.pop();
    }    
    for(int i = 1; i <= n; i++){
        q.push(st.top());     
        st.pop();
    }     
    display(q);

    return 0;
}