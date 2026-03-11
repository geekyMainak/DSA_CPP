    string s = "31254623";
    vector<char> v = nextGreaterElement(s);

    for(auto c : v) {
        cout << c << " ";
    }

    cout << endl;
    vector<int> q = {3,1,2,5,4,6,2,3};
    vector<int> res = nextGreaterElementOptimised(q);
    for(auto c : res) {
        cout << c << " ";
    }

    cout << endl;
    vector<int> resII = nextGreaterElementOptimisedII(q);
    for(auto c : resII) {
        cout << c << " ";
    }