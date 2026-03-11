// MAZE PATH PROBLEM WHEN RIGHT SIDE AND DOWN SIDE ARE ALLOWED ONLY
#include <iostream>

using namespace std;

int mazePath(int sr, int sc, int er, int ec) {
    // base case
    if(sr > er || sc > ec)      return 0;
    if(sr == er && sc == ec)      return 1;

    int rightWays = mazePath(sr, sc + 1, er, ec);
    int downWays = mazePath(sr + 1, sc, er, ec);

    return rightWays + downWays;
}

void printPath(int sr, int sc, int er, int ec, string s) {
    // base case
    if(sr > er || sc > ec)      return;
    if(sr == er && sc == ec) {
        cout << s <<endl;
        return;
    }

    printPath(sr, sc + 1, er, ec, s + 'R'); //rightMovement
    printPath(sr + 1, sc, er, ec, s + 'D'); //downMovement
}

int main() {
    int k = mazePath(1,1,4,5);
    cout << k <<endl;
    printPath(1,1,4,5,"");
    return 0;
}
