// STOCK SPAN
#include <iostream>
#include <vector>
#include <stack>

using namespace std;

vector<int> stockSpan(vector<int> v) {
    int n = v.size();
    stack<int> st;    // store the index of the previous greater element
    vector<int> result(n, 1);
    st.push(0);

    for(int i = 1; i < n; i++) {
        while(!st.empty() && v[i] >= v[st.top()])   st.pop();
        result[i] = (st.empty()) ? i + 1 : i - st.top();
        st.push(i);
    }
    return result;
}

int main() {
    vector<int> v = {100, 80, 60 ,101, 60, 75, 85};
    vector<int> ans = stockSpan(v);
    for(auto i : ans) {
        cout << i << " ";
    }

    return 0;
}