#include <bits/stdc++.h>
using namespace std;

vector<int> segTree, lazy;

void buildTree(int arr[], int i, int low, int high) {
    if (low == high) {
        segTree[i] = arr[low];
        return;
    }
    int mid = (low + high) / 2;
    buildTree(arr, 2*i+1, low, mid);
    buildTree(arr, 2*i+2, mid+1, high);
    segTree[i] = segTree[2*i+1] + segTree[2*i+2];
}

void push(int i, int low, int high) {
    if (lazy[i] != 0) {
        segTree[i] += (high - low + 1) * lazy[i];
        if (low != high) {
            lazy[2*i+1] += lazy[i];
            lazy[2*i+2] += lazy[i];
        }
        lazy[i] = 0;
    }
}

void update(int i, int low, int high, int left, int right, int val) {
    push(i, low, high);

    if (right < low || left > high) return;

    if (left <= low && high <= right) {
        lazy[i] += val;
        push(i, low, high);
        return;
    }

    int mid = (low + high) / 2;
    update(2*i+1, low, mid, left, right, val);
    update(2*i+2, mid+1, high, left, right, val);

    segTree[i] = segTree[2*i+1] + segTree[2*i+2];
}

int getSum(int i, int low, int high, int left, int right) {
    push(i, low, high);

    if (right < low || left > high) return 0;

    if (left <= low && high <= right)
        return segTree[i];

    int mid = (low + high) / 2;
    return getSum(2*i+1, low, mid, left, right) + getSum(2*i+2, mid+1, high, left, right);
}

int main() {
    int arr[] = {1, 2, 3, 4, 5};
    int n = 5;

    segTree.assign(4*n, 0);
    lazy.assign(4*n, 0);

    buildTree(arr, 0, 0, n-1);

    cout << "Initial sum [1,3]: " << getSum(0, 0, n-1, 1, 3) << endl;

    update(0, 0, n-1, 1, 3, 10);

    cout << "After update (+10), sum [1,3]: " << getSum(0, 0, n-1, 1, 3) << endl;

    cout << "Sum [0,4]: " << getSum(0, 0, n-1, 0, 4) << endl;
         
    return 0;
}