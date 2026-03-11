#include <bits/stdc++.h>
using namespace std;

class Node {
public:
    char data;
    bool terminal;
    unordered_map<char, Node*> children;

    Node(char data) {
        this->data = data;
        this->terminal = false;
    }

    void makeTerminal() {
        terminal = true;
    }

    bool isTerminal() {
        return terminal;
    }
};

class Trie {
public:
    Node* root;

    Trie() {
        root = new Node('\0');   // dummy root
    }

    void insert(const string &word) {
        Node* curr = root;

        for (char ch : word) {
            if (!curr->children.count(ch)) {
                curr->children[ch] = new Node(ch);
            }
            curr = curr->children[ch];
        }
        curr->makeTerminal();
    }

    bool search(const string &word) {
        Node* curr = root;

        for (char ch : word) {
            if (!curr->children.count(ch))
                return false;
            curr = curr->children[ch];
        }
        return curr->isTerminal();
    }

    bool startsWith(const string &prefix) {
        Node* curr = root;

        for (char ch : prefix) {
            if (!curr->children.count(ch))
                return false;
            curr = curr->children[ch];
        }
        return true;
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    Trie trie;

    // Insert words
    trie.insert("apple");
    trie.insert("app");
    trie.insert("bat");
    trie.insert("ball");

    // Search tests
    cout << "search(\"apple\") = " << trie.search("apple") << "\n";
    cout << "search(\"app\")   = " << trie.search("app") << "\n";
    cout << "search(\"ap\")    = " << trie.search("ap") << "\n";
    cout << "search(\"bat\")   = " << trie.search("bat") << "\n";
    cout << "search(\"ball\")  = " << trie.search("ball") << "\n";
    cout << "search(\"cat\")   = " << trie.search("cat") << "\n";

    cout << "\n";

    // Prefix tests
    cout << "startsWith(\"ap\")   = " << trie.startsWith("ap") << "\n";
    cout << "startsWith(\"app\")  = " << trie.startsWith("app") << "\n";
    cout << "startsWith(\"ba\")   = " << trie.startsWith("ba") << "\n";
    cout << "startsWith(\"bal\")  = " << trie.startsWith("bal") << "\n";
    cout << "startsWith(\"cat\")  = " << trie.startsWith("cat") << "\n";

    return 0;
}
