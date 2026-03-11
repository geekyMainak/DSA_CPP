#include <iostream>
#include <vector>
#include <stack>

using namespace std;

vector<int> prevGreaterElement(vector<int> v){
    int n = v.size();
    vector<int> result(n);
    stack<int> st;
    st.push(v[0]);
    result[0] = -1;
    
    for(int i = 1; i < n; i++) {
        while(!st.empty() && st.top() <= v[i])    st.pop();
        result[i] = (st.empty()) ? -1 : st.top();
        st.push(v[i]);
    }
    return result;
}

int main() {
    vector<int> q = {3,1,2,5,4,6,2,3};
    vector<int> res = prevGreaterElement(q);
    for(auto c : res) {
        cout << c << " ";
    }

    return 0;
}