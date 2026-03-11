#include <iostream>
#include <vector>

using namespace std;

int main() {
    vector<int> nums = {1,2,3,4,2,8};
    for(int i = 1; i < nums.size(); i++) {
        nums[i]  += nums[i - 1];
    }

    int idx = -1;
    for(int i = 1; i < nums.size(); i++) {
        if(2 * nums[i] == nums[nums.size() - 1]){
                idx = i;
                break;
        }
    }
    if(idx == -1)   cout  << "Cannot be partitioned into equal sum of elements";
    else    cout << "Can be partitioned into equal sum of elements after index " << idx;

    return 0;
}