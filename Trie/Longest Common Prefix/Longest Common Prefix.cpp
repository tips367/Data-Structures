/* Write a function to find the longest common prefix string amongst an array of strings.

If there is no common prefix, return an empty string "".

Example 1:

Input: strs = ["flower","flow","flight"]
Output: "fl"
Example 2:

Input: strs = ["dog","racecar","car"]
Output: ""
Explanation: There is no common prefix among the input strings.
*/

#include <iostream>
#include <vector>

using namespace std;

class TrieNode
{
public:
    bool isEnd;
    TrieNode* child[26];
    bool containsKey(char ch)
    {
        return child[ch - 'a'] != nullptr;
    }

    TrieNode* getNext(char ch)
    {
        return child[ch - 'a'];
    }

    void put(char ch, TrieNode* node)
    {
        child[ch - 'a'] = node;
    }
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

    int countChildren(TrieNode* node, int& index)
    {
        int count = 0;
        for (int i = 0; i < 26; i++)
        {
            if (node->child[i] != nullptr)
            {
                count++;
                index = i;
            }
        }
        return count;
    }

public:
    Trie() : root(getNode()) {}

    void insert(string& word)
    {
        TrieNode* curr = root;
        for (char c : word)
        {
            if (!curr->containsKey(c))
                curr->put(c, getNode());
            curr = curr->getNext(c);
        }
        curr->isEnd = true;
    }

    string walkTrie()
    {
        TrieNode* curr = root;
        int index;
        string prefix;

        while (countChildren(curr, index) == 1 && curr->isEnd == false)
        {
            curr = curr->child[index];
            prefix.push_back('a' + index);
        }
        return prefix;
    }

};

string longestCommonPrefix(vector<string>& strs)
{
    Trie trie;
    for (auto str : strs)
    {
        trie.insert(str);
    }

    return trie.walkTrie();
}

int main()
{
    vector<string> strs = { "flower","flow","flight" };
    std::cout << longestCommonPrefix(strs);

    return 0;
}

