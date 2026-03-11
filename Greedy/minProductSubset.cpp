// Find the minimum product of the subset
#include <iostream>
#include <climits>
#include <vector>
#include <algorithm>

using namespace std;

int minProduct(vector<int> v) {
    int minEle = *min_element(begin(v), end(v));
    
    // Case 1: Array has no Negative number
    if(minEle >= 0) {
        // Subcase a: No Zeros and all are positive -> Min positive number
        // Subcase b: Atleast one zero and remaining are positive -> 0
        return minEle;
    } else {
    // Case 2: Array has Negative number
        int countNeg = 0;
        int prodAll = 1;
        int maxNeg = INT_MIN;
        for(auto num : v) {
            if(num < 0) {
                countNeg++;

                maxNeg = max(num, maxNeg);
            }    
            if(num)     prodAll *= num;
        } 
        // Subcase a: Odd number of -ve => Product of all numbers
        if(countNeg % 2)    return prodAll;
        // Subcase a: Even number of -ve => Product of all numbers / Maximum Negative number
        else    return  (prodAll / maxNeg);        

    }
    return 0;    
}

int main () {
    vector<int> v = {0, -1, 2, 3};
    cout << minProduct(v) << endl;
    return 0;
}