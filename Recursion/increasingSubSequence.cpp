// SUBSEQUENCE  STRING
#include <iostream>
#include <string>
#include <vector>

using namespace std;

// METHOD 1
void subsequence(string original, string ans, vector<string> &v) {
    // base case
    if(original.length() == 0) {
        v.push_back(ans);
        return;
    }

    char k = original[0];
    subsequence(original.substr(1), ans, v);
    subsequence(original.substr(1), ans + k, v);

}

int main() {
    string str = "abcde";
    vector<string> v;
    subsequence(str, "", v);
    cout << endl;
    for(string ele : v) {
        if(ele.length() == 3 )  cout <<"[" << ele <<"]" <<" ";
    }
    return 0;
}