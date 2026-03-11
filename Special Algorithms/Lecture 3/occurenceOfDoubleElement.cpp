// Given an array where every elements occurs single except two elements. Find those elements ?
#include <iostream>
using namespace std;

void findTwoUnique(int arr[], int n) {
    int xor_all = 0;

    // Step 1: XOR all elements → gets x ^ y
    for (int i = 0; i < n; i++) {
        xor_all ^= arr[i];
    }

    // Step 2: Find rightmost set bit in xor_all
    int diff_bit = xor_all & -xor_all;

    int x = 0, y = 0;

    // Step 3: Divide elements into two groups and XOR separately
    for (int i = 0; i < n; i++) {
        if (arr[i] & diff_bit)
            x ^= arr[i]; // bit is set
        else
            y ^= arr[i]; // bit is not set
    }

    // Output two unique elements
    cout << "The two unique elements are: " << x << " and " << y << endl;
}

void findTwoUnique_Alternate(int arr[], int n) {
    int res = 0;
    for(int i = 0; i < n; i++) {
        res ^= arr[i];
    }

    int temp = res, pos = 0;
    while(true) {
        if((temp & 1) == 1) break;
        temp = temp >> 1;
        pos++;
    }
    int first_unique = 0;
    for(int i = 0; i < n; i++) {
        int num = arr[i];
        if((num >> pos) & 1)    first_unique ^= num;
    }
    cout << "The unique numbers are " << first_unique << " and " << (res ^ first_unique) <<endl;
}

int main() {
    int arr[] = {2, 3, 5, 4, 5, 3, 4, 8};
    int n = sizeof(arr) / sizeof(arr[0]);
    findTwoUnique(arr, n);   // 2 and 8
    findTwoUnique_Alternate(arr, n);   // 2 and 8

    return 0;
}
