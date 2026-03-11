#include <iostream>

using namespace std;

class Stack {
public:
    int arr[5];
    int idx;

    Stack() {
        idx = -1;
    }

    void push(int val) {
        if(idx == 5 - 1) {
            cout << "Stack overflow\n";
            return;
        }
        else {
            arr[++idx] = val;
        }
    }

    void pop() {
        if(idx == -1) {
            cout <<"Stack underflow\n";
            return;
        }
        else {
            idx--;
        }
    }

    int size() {
        return idx + 1;
    }

    int top() {
        if(idx == -1) {
            cout <<"Stack underflow\n";
            return 0;
        }
        return arr[idx];
    }
};

int main() {
    Stack st;
    st.push(10);
    st.push(20);
    st.push(30);
    st.push(40);

    cout << "Size: ";
    cout << st.size() << endl;
    st.pop();
    st.pop();
    cout << "Size: ";
    cout << st.size() << endl;
    cout << "Top: ";
    cout << st.top();

    return 0;
}