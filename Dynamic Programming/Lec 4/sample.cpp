#include <cstdlib>
#include <iostream>
using namespace std;

int main() {
    int result = system("start image.png");  // open PNG file 

    if (result != 0)    cout << "Failed to open image.\n";
    else    cout << "PNG image opened successfully!\n";

    

    return 0;
}
