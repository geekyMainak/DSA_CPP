#include <bits/stdc++.h>
using namespace std;

template <class T>
class vec {
public:
    T *arr;
    int size;

    vec(int m) {
        size = m;
        arr = new T[size];
    }

    T dotProduct(vec &v) {
        T d = 0;
        for(int i = 0; i < size; i++)   d += this->arr[i] * v.arr[i];

        return d;
    }
    
};

int main () {
    vec<int> v1(3);
    v1.arr[0] = 1;
    v1.arr[1] = 2;
    v1.arr[2] = 3;

    vec<int> v2(3);
    v2.arr[0] = 1;
    v2.arr[1] = 2;
    v2.arr[2] = 3;

    cout << v1.dotProduct(v2) << endl;

    vec<float> v3(3);
    v3.arr[0] = 1.1;
    v3.arr[1] = 2.1;
    v3.arr[2] = 3.1;

    vec<float> v4(3);
    v4.arr[0] = 1.1;
    v4.arr[1] = 2.3;
    v4.arr[2] = 3.2;

    cout << v3.dotProduct(v4) << endl;

    return 0;
}