#include <iostream>
#include <vector>

using namespace std;

class Stack {
public:
    vector<int> v;
    
    void push(int val) {
        v.push_back(val);
    }

    void pop() {
        if(v.size() == 0) {
            cout <<"Stack underflow\n";
            return;
        }
        else {
            v.pop_back();
        }
    }

    int size() {
        return v.size();
    }

    int top() {
        if(v.size() == 0) {
            cout <<"Stack underflow\n";
            return 0;
        }
        return v.back();
    }
};

int main() {
    Stack st;
    st.push(10);
    st.push(20);
    st.push(30);
    st.push(40);
    st.push(50);

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