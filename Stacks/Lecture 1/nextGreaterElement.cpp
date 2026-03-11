#include <iostream>
#include <string>
#include <vector>
#include <stack>

using namespace std;

vector<int> nextGreaterElementOptimised(vector<int> v) {
    /* Time Complexity -> O(n) — each element is pushed and popped at most once
        Space Complexity -> O(n) — for result and stack */
    int n = v.size();
    vector<int> result(n, -1); 
    stack<int> st;

    for (int i = 0; i < n; i++) {
        // while stack not empty and current char is greater than top of stack
        while (!st.empty() && v[i] > v[st.top()]) {
            result[st.top()] = v[i];  // found NGE
            st.pop();
        }
        st.push(i);  // store index of current char
    }

    return result;
}

vector<int> nextGreaterElementOptimisedII(vector<int> v) {
    /* Time Complexity -> O(n) — each element is pushed and popped at most once
        Space Complexity -> O(n) — for result and stack */
    int n = v.size();
    vector<int> result(n, -1); 
    stack<int> st;
    st.push(v[n-1]);

    for (int i = n - 2; i >= 0; i--) {
        while (!st.empty() && v[i] >= st.top())     st.pop();  //pop all elements which are less than v[i] 
        result[i] = (st.empty()) ? -1 : st.top();              // mark the ans in result vector
        st.push(v[i]);      // push the recent element
    }

    return result;
}

vector<char> nextGreaterElement(string s) {
    int n = s.size();
    vector<char> result(n, '-'); 

    for(int i = 0; i < n; i++) {
        for(int j = i + 1; j < n; j++) {
            if(s[j] > s[i]) {
                result[i] = s[j];
                break;  
            }
        }
    }

    return result;
}

int main() {
    string s = "31254623";
    vector<char> v = nextGreaterElement(s);

    for(auto c : v) {
        cout << c << " ";
    }

    cout << endl;
    vector<int> q = {3,1,2,5,4,6,2,3};
    vector<int> res = nextGreaterElementOptimised(q);
    for(auto c : res) {
        cout << c << " ";
    }

    cout << endl;
    vector<int> resII = nextGreaterElementOptimisedII(q);
    for(auto c : resII) {
        cout << c << " ";
    }

    return 0;
}
