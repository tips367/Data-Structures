/* A trie (pronounced as "try") or prefix tree is a tree data structure used to efficiently store and retrieve keys in a dataset of strings. 
There are various applications of this data structure, such as autocomplete and spellchecker.

Implement the Trie class:

-Trie() Initializes the trie object.
-void insert(String word) Inserts the string word into the trie.
-boolean search(String word) Returns true if the string word is in the trie (i.e., was inserted before), and false otherwise.
-boolean startsWith(String prefix) Returns true if there is a previously inserted string word that has the prefix prefix, and false otherwise.

Example 1:

Input
["Trie", "insert", "search", "search", "startsWith", "insert", "search"]
[[], ["apple"], ["apple"], ["app"], ["app"], ["app"], ["app"]]
Output
[null, null, true, false, true, null, true]

Explanation
Trie trie = new Trie();
trie.insert("apple");
trie.search("apple");   // return True
trie.search("app");     // return False
trie.startsWith("app"); // return True
trie.insert("app");
trie.search("app");     // return True

*/

#include <iostream>

using namespace std;

class TrieNode
{
public:
    bool isEnd;
    TrieNode* child[26];
};

class Trie {
private:
    TrieNode* root;

    TrieNode* getNode()
    {
        TrieNode* newNode = new TrieNode();
        newNode->isEnd = false;
        for (int i = 0; i < 26; i++)
            newNode->child[i] = nullptr;
        return newNode;
    }

    TrieNode* find(string& key)
    {
        TrieNode* p = root;
        int n = size(key);
        for (int i = 0; i < n && p != nullptr; ++i)
            p = p->child[key[i] - 'a'];
        return p;
    }

    void clear(TrieNode* root)
    {
        for (int i = 0; i < 26; i++)
        {
            if (root->child[i] != nullptr)
                clear(root->child[i]);
        }
        delete root;
    }
public:
    Trie() : root(getNode()) {}

    ~Trie() 
    {
        clear(root);
    }

    void insert(string word)
    {
        int index = 0;
        TrieNode* curr = root;
        for (char c : word)
        {
            index = c - 'a';
            if (curr->child[index] == nullptr)
                curr->child[index] = getNode();
            curr = curr->child[index];
        }
        curr->isEnd = true;
    }

    bool search(string word)
    {
        TrieNode* p = find(word);
        return p != nullptr && p->isEnd;
    }

    bool startsWith(string prefix)
    {
        return find(prefix) != nullptr;
    }
};

int main()
{
    Trie trie;
    trie.insert("apple");
    cout << std::boolalpha <<trie.search("apple") << endl;
    cout << trie.search("app") << endl;
    cout << trie.startsWith("app") << endl;
    trie.insert("app");
    cout << trie.search("app") << endl;

    return 0;
}

