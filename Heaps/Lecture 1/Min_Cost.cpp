// Minimum Cost to Connect All Ropes
#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main() {
    vector<int> v;
    v.push_back(2);
    v.push_back(7);
    v.push_back(4);
    v.push_back(1);
    v.push_back(8);

    priority_queue<int, vector<int>, greater<int>> pq(v.begin(), v.end());   // MIN HEAP  and Heapify ( O(n) )

    int minCost = 0;
    while(pq.size() != 1) {
        int low_1 = pq.top();
        pq.pop();

        int low_2 = pq.top();
        pq.pop();
        
        int x = low_1 + low_2;
        pq.push(x);
        minCost += x;
    }

    cout << minCost;

    return 0;
}