// MAZE PATH PROBLEM WHEN RIGHT SIDE AND DOWN SIDE ARE ALLOWED ONLY
#include <iostream>

using namespace std;

void printPathTowerOfHanoi( int n, char source, char helper, char destination) {
    // base case
    if(n == 0)  return;

    printPathTowerOfHanoi(n - 1, source, destination, helper);
    cout << source <<" --> " << destination << endl; 
    printPathTowerOfHanoi(n - 1, helper, source, destination);
}

int main() {
    printPathTowerOfHanoi(3, 'A', 'B', 'C');
    return 0;
}
