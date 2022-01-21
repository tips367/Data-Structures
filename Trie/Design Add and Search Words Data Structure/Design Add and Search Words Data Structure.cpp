/* Design a data structure that supports adding new words and finding if a string matches any previously added string.

Implement the WordDictionary class:

-WordDictionary() Initializes the object.
-void addWord(word) Adds word to the data structure, it can be matched later.
-bool search(word) Returns true if there is any string in the data structure that matches word or false otherwise. 
word may contain dots '.' where dots can be matched with any letter.

Example:

Input
["WordDictionary","addWord","addWord","addWord","search","search","search","search"]
[[],["bad"],["dad"],["mad"],["pad"],["bad"],[".ad"],["b.."]]
Output
[null,null,null,null,false,true,true,true]

Explanation
WordDictionary wordDictionary = new WordDictionary();
wordDictionary.addWord("bad");
wordDictionary.addWord("dad");
wordDictionary.addWord("mad");
wordDictionary.search("pad"); // return False
wordDictionary.search("bad"); // return True
wordDictionary.search(".ad"); // return True
wordDictionary.search("b.."); // return True
*/

#include <iostream>
#include <unordered_map>

using namespace std;

// Method 1. Using Map
/*
class WordDictionary 
{
public:
    WordDictionary() {}

    void addWord(string word) {
        words[word.size()].push_back(word);
    }

    bool search(string word) {
        for (auto s : words[word.size()]) if (isEqual(s, word)) return true;
        return false;
    }

private:
    unordered_map<int, vector<string>>words;

    bool isEqual(string a, string b) {
        for (int i = 0; i < a.size(); i++) {
            if (b[i] == '.') continue;
            if (a[i] != b[i]) return false;
        }
        return true;
    }
}; */

// Method 2: Using Trie
class TrieNode
{
public:
    int wordEnd;
    TrieNode* child[26];
};

class Trie
{
public:
    TrieNode* root;
    Trie() : root(getNode()) {}

    void insert(string& s)
    {
        int index = 0;
        TrieNode* curr = root;
        for (char c : s)
        {
            index = c - 'a';
            if (curr->child[index] == nullptr)
                curr->child[index] = getNode();
            curr = curr->child[index];
        }
        curr->wordEnd += 1;
    }

    bool search(string& s, TrieNode* parent, int pos, int n)
    {
        if (s[pos] == '.')
        {
            bool res = false;
            TrieNode* curr = parent;
            for (int i = 0; i < 26; ++i)
            {
                if (pos == n - 1 && parent->child[i])
                {
                    curr = parent->child[i];
                    res |= curr->wordEnd > 0 ? true : false;
                }
                else if (parent->child[i] && search(s, parent->child[i], pos + 1, n))
                    return true;
            }
            return res;
        }
        else if (parent->child[s[pos] - 'a'])
        {
            if (pos == n - 1)
            {
                parent = parent->child[s[pos] - 'a'];
                return parent->wordEnd > 0 ? true : false;
            }
            return search(s, parent->child[s[pos] - 'a'], pos + 1, n);
        }
        return false;
    }

private:
    TrieNode* getNode()
    {
        TrieNode* newNode = new TrieNode();
        newNode->wordEnd = 0;
        for (int i = 0; i < 26; i++)
            newNode->child[i] = nullptr;
        return newNode;
    }
};

class WordDictionary {
public:
    Trie* trie;
    WordDictionary() 
    {
        trie = new Trie();
    }

    void addWord(string word) 
    {
        trie->insert(word);
    }

    bool search(string word) 
    {
        return trie->search(word, trie->root, 0, size(word));
    }
};

int main()
{
    WordDictionary wordDict;
    wordDict.addWord("bad");
    wordDict.addWord("dad");
    wordDict.addWord("mad");
    cout << std::boolalpha << wordDict.search("pad") << endl;
    cout << wordDict.search("bad") << endl;
    cout << wordDict.search(".ad") << endl;
    cout << wordDict.search("b..") << endl;

    return 0;
}

