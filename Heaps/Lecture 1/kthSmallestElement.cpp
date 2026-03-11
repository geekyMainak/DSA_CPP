// kth Smallest Element
#include <iostream>
#include <queue>

using namespace std;

int main() {
    // Brute Force
    // priority_queue<int> pq;   // MAX HEAP
    // int arr [] = {5,2,7,8,3,9,1,0,4,6};     // 0 1 2 3 4 5 6 7 8 9 
    // int n = sizeof(arr) / sizeof(arr[0]);
    // int k = 4;

    // for(auto x : arr)   pq.push(x);

    // for(int i = 0; i < n-k; i++)    pq.pop();

    // cout << "Kth Smallest Element: " << pq.top() << endl;


    // Optimal 
    int k = 4;
    priority_queue<int> pq;   // MAX HEAP
    int arr [] = {5,2,7,8,3,9,1,0,4,6};     // 0 1 2 3 4 5 6 7 8 9 
    int n = sizeof(arr) / sizeof(arr[0]);

    for(int i = 0; i < n; i++) {
        pq.push(arr[i]);
        if(pq.size() > k)    pq.pop();  
    }

    cout << "Kth Smallest Element: " << pq.top() << endl;

    return 0;
}