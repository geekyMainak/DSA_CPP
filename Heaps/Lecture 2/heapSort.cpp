#include <iostream>
#include <vector>
#include <queue>

using namespace std;

void heapSort(vector<int> &v) {
    priority_queue<int, vector<int>, greater<int>> pq;    // MIN HEAP
    for(auto ele : v)   pq.push(ele);

    for(int i = 0; i < v.size(); i++) {
        v[i] = pq.top();
        pq.pop();
    }
}

int main () {
    vector<int> v;
    v.push_back(5);
    v.push_back(2);
    v.push_back(6);
    v.push_back(4);
    v.push_back(1);
    v.push_back(3);

    for(auto ele : v)   cout << ele << " ";

    heapSort(v);

    cout << endl;
    for(auto ele : v)   cout << ele << " ";

    return 0;
}