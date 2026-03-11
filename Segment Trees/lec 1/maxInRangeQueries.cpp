#include <bits/stdc++.h>
using namespace std;

vector<int> st;
void buildTree(int arr[], int i, int low, int high) {
    if(low == high) {
        st[i] = arr[low];
        return;
    }

    int mid = low + (high - low) / 2;
    buildTree(arr, 2*i + 1, low, mid);      //left subtree
    buildTree(arr, 2*i + 2, mid+1, high);  // right subtree

    st[i] = max(st[2*i + 1], st[2*i + 2]);  // backtrack
}

int getMax(int i, int low, int high, int &l, int &r) {
    // case 1
    if(l > high || r < low) {
        return INT_MIN;
    }

    // case 2
    if(low >= l && high <= r) {
        return st[i];
    }

    int mid = low + (high - low) / 2;
    int leftMax = getMax(2*i + 1, low, mid, l, r);
    int rightMax = getMax(2*i + 2, mid+1, high, l, r);

    return max(leftMax, rightMax);
}

int main () {
    int arr[] = {1, 4, 2, 8, 6, 4, 9, 3};
    int n = sizeof(arr)/ sizeof(int);

    st.resize(4*n);

    buildTree(arr, 0, 0, n-1);

    int l, r;
    cin >> l >> r;

    cout << getMax(0, 0, n-1, l, r) << '\n'; 
    return 0;
}