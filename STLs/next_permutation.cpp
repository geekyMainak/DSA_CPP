// #include <bits/stdc++.h>
// using namespace std;

// int main() {
//     vector<int> a = {1, 2, 3};
//     // Generate all permutations in lexicographic order:
//     sort(a.begin(), a.end());            // ensure starting from the smallest
//     do {
//         for (int x : a) cout << x << ' ';
//         cout << '\n';
//     } while (next_permutation(a.begin(), a.end()));
// }



#include <bits/stdc++.h>
using namespace std;

int main() {
    vector<int> a = {3, 2, 1};

    // Sort in descending order (treats 3 > 2 > 1 as "smallest")
    sort(a.begin(), a.end(), greater<int>());

    cout << "Permutations in descending lexicographic order:\n";
    do {
        for (int x : a) cout << x << " ";
        cout << "\n";
    } while (next_permutation(a.begin(), a.end(), greater<int>()));
}
