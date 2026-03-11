#include <bits/stdc++.h>
using namespace std;

class Node {
public:
    char data;
    int endCount;        // number of words ending here
    int prefixCount;     // number of words passing through
    unordered_map<char, Node*> children;

    Node(char data) {
        this->data = data;
        endCount = 0;
        prefixCount = 0;
    }
};

class Trie {
public:
    Node* root;

    Trie() {
        root = new Node('\0');   // dummy root
    }

    // Insert a word
    void insert(const string &word) {
        Node* curr = root;

        for (char ch : word) {
            if (!curr->children.count(ch)) {
                curr->children[ch] = new Node(ch);
            }
            curr = curr->children[ch];
            curr->prefixCount++;
        }
        curr->endCount++;
    }

    // Count exact word
    int countWordsEqualTo(const string &word) {
        Node* curr = root;

        for (char ch : word) {
            if (!curr->children.count(ch))
                return 0;
            curr = curr->children[ch];
        }
        return curr->endCount;
    }

    // Count words starting with prefix
    int countWordsStartingWith(const string &prefix) {
        Node* curr = root;

        for (char ch : prefix) {
            if (!curr->children.count(ch))
                return 0;
            curr = curr->children[ch];
        }
        return curr->prefixCount;
    }

    // Erase one occurrence of a word
    void erase(const string &word) {
        Node* curr = root;

        for (char ch : word) {
            Node* next = curr->children[ch];
            next->prefixCount--;
            curr = next;
        }
        curr->endCount--;
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    Trie trie;

    // Insert words
    trie.insert("apple");
    trie.insert("apple");
    trie.insert("app");
    trie.insert("bat");

    // Tests
    cout << "countWordsEqualTo(\"apple\") = "
         << trie.countWordsEqualTo("apple") << "\n";     // 2

    cout << "countWordsStartingWith(\"app\") = "
         << trie.countWordsStartingWith("app") << "\n";  // 3

    trie.erase("apple");

    cout << "countWordsEqualTo(\"apple\") = "
         << trie.countWordsEqualTo("apple") << "\n";     // 1

    cout << "countWordsStartingWith(\"app\") = "
         << trie.countWordsStartingWith("app") << "\n";  // 2

    trie.erase("apple");

    cout << "countWordsEqualTo(\"apple\") = "
         << trie.countWordsEqualTo("apple") << "\n";     // 0

    cout << "countWordsStartingWith(\"app\") = "
         << trie.countWordsStartingWith("app") << "\n";  // 1

    return 0;
}
