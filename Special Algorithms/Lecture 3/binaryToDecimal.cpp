// BINARY TO DECIMAL and VICE VERSA (USING LEFT SHIFT AND RIGHT SHIFT OPERATOR)
#include <iostream>
#include <string>

using namespace std;

int binaryToDecimal(string &binary) {
    int n = binary.size();
    int result = 0;

    for(int i = 0; i < n ; i++) {
        char ch = binary[i] - '0';
        result += ch << (n - i -1);
    }
    return result;
}

string decimalToBinary(int n) {
    string result = "";

    while(n > 0) {
        char ch = (n % 2) + '0';
        result = ch + result;
        n = n >> 1;  // we can also use this n /= 2;
    }
    return result;
}

int main() {
    string str = "00100000";
    cout << binaryToDecimal(str) << endl;
    cout << decimalToBinary(19) << endl;
    return 0;
}