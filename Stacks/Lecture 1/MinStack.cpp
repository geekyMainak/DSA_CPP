// MIN STACK 
#include <iostream>
#include <stack>
#include <climits>

using namespace std;

// class MinStack {
// public:
//     stack<int> st;
//     stack<int> helper;

//     MinStack() {}

//     void push(int val) {
//         st.push(val);
//         if (helper.empty() || val < helper.top())
//             helper.push(val);
//         else
//             helper.push(helper.top());
//     }

//     void pop() {
//         st.pop();
//         helper.pop();
//     }

//     int top() {
//         return st.top();
//     }

//     int getMin() {  // T.C. -> O(1) and  S.C. -> O(n)
//         return helper.top();
//     }
// };

class MinStack {
public:
    stack<long long> st;
    long long min = LLONG_MAX;
    MinStack() { // constructor
        
    }
    
    void push(int val) {   // O(1)
        long long x = val;
        if(st.empty()) {
            st.push (x);
            min = x;
        }
        else if(val >= min)   st.push(x);
        else {  // val < min
            st.push(2*x - min);
            min = x;
        }

    }
    
    void pop() {   // O(1)
        if(st.top() < min)      min = 2*min - st.top();
        st.pop();
    }
    
    int top() {   // O(1)
        if(st.top() < min)    return min;
        else    return st.top();
    }
    
    int getMin() {  // T.C. -> O(1) and  S.C. -> O(1)
        return min;
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */

int main() {
    MinStack* obj = new MinStack();

    obj->push(5);
    cout << "Pushed 5, Min: " << obj->getMin() << endl;

    obj->push(3);
    cout << "Pushed 3, Min: " << obj->getMin() << endl;

    obj->push(7);
    cout << "Pushed 7, Min: " << obj->getMin() << endl;

    obj->push(2);
    cout << "Pushed 2, Min: " << obj->getMin() << endl;

    obj->pop();
    cout << "Popped, Min: " << obj->getMin() << endl;

    cout << "Top: " << obj->top() << endl;
    cout << "Current Min: " << obj->getMin() << endl;

    delete obj;
    return 0;
}
