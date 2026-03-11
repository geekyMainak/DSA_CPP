// GENERATE BINARY STRINGS OF LENGTH K AND WHERE NO CONSECUTIVE 1'S ARE THERE
#include <iostream>
#include <vector>
#include <string>

using namespace std;

void generateBinaryStrings(string ans,vector<string> &v, int k) {
    // base case 
    if(k == 0) {
        v.push_back(ans);
        return;
    }

    generateBinaryStrings(ans + '0', v, k - 1);
    if(ans.empty() || ans.back() != '1')      generateBinaryStrings(ans + '1', v, k - 1);

}

int main() {
    vector<string> v;
    int k = 3;
    generateBinaryStrings("",v,k);

    for(string s : v) {
        cout << s << endl;
    }

    return 0;
}