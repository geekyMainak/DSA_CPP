// Removing Even Place Elements (0th based indexing)
#include <iostream>
#include <queue>
#include <stack>

using namespace std;

void remove(queue<int> &q) {
    queue<int> q1;
    while(!q.empty()) {
        q.pop();
        if(q.empty())   break;
        q1.push(q.front());
        if(!q.empty())  q.pop();
    }
    while(!q1.empty()) {
        q.push(q1.front());
        q1.pop();
    }

    // BY SIR
    // int n = q.size();
    // for(int i = 0; i < n; i++) {
    //     if(i % 2 == 0)  q.pop();
    //     else {
    //         int x = q.front();
    //         q.pop();
    //         q.push(x);
    //     }
    // }
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

    remove(q);
    
    display(q);

    return 0;
}