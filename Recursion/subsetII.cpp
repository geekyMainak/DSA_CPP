// SUBSET II (ELEMENTS OF THE SET ARE REPEATED)
#include <iostream>
#include <string>
#include <vector>

using namespace std;

// METHOD 1
void storeSubset(string original, string ans, vector<string> &v, bool flag) {
    // base case
    if(original.length() == 0) {
        v.push_back(ans);
        return;
    }

    char ch = original[0];
    if(original.length() == 1) {
        if(flag == true)    storeSubset(original.substr(1), ans + ch, v, true);
        storeSubset(original.substr(1), ans , v, true);
        return;
    }
    
    char dh = original[1];
        if(ch == dh) {
            if(flag == true)    storeSubset(original.substr(1), ans + ch, v, true);
            storeSubset(original.substr(1), ans, v, false);
        }
        else {
                if(flag == true)    storeSubset(original.substr(1), ans + ch, v, true);
                storeSubset(original.substr(1), ans , v, true);
        }

}

int main() {
    string str = "aab";
    vector<string> v;
    storeSubset(str, "", v, true);
    cout << endl;
    for(string ele : v) {
        cout <<"[" << ele <<"]" <<" ";
    }
    return 0;
}
