/* Given an integer array nums, return the maximum result of nums[i] XOR nums[j], where 0 <= i <= j < n.

Example 1:

Input: nums = [3,10,5,25,2,8]
Output: 28
Explanation: The maximum result is 5 XOR 25 = 28.

Example 2:

Input: nums = [14,70,53,83,49,91,36,80,92,51,66,70]
Output: 127
*/

#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

// Method 1: Brute force...Time complexity: O(n^2)
/*
int findMaximumXOR(vector<int>& nums)
{
    int n = size(nums);
    int maxXor = 0;
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            maxXor = max(maxXor, nums[i] ^ nums[j]);
        }
    }
    return maxXor;
} */

// Method 2: Using bit manipulation and set...Time complexity: O(n)
/*
int findMaximumXOR(vector<int>& nums)
{
    int maxXor = 0;
    int mask = 0;

    for (int i = 31; i >= 0; --i)
    {
        unordered_set<int> s;
        mask |= (1 << i);
        for (int num : nums)
            s.insert(num & mask);

        int candidate = maxXor | (1 << i);
        for (int prefix : s)
        {
            if (s.count(prefix ^ candidate))
            {
                maxXor = candidate;
                break;
            }
        }
    }

    return maxXor;
} */

// Method 3: Using Trie..Time complexity: O(n)
class TrieNode
{
public:
    TrieNode* child[2];
    bool containsKey(int bit)
    {
        return child[bit] != nullptr;
    }

    TrieNode* getNext(int bit)
    {
        return child[bit];
    }

    void put(int bit, TrieNode* node)
    {
        child[bit] = node;
    }
};

class Trie {
private:
    TrieNode* root;

    TrieNode* getNode()
    {
        TrieNode* newNode = new TrieNode();
        newNode->child[0] = nullptr;
        newNode->child[1] = nullptr;
        return newNode;
    }

    void clear(TrieNode* root)
    {
        if (root->child[0] != nullptr)
            clear(root->child[0]);
        if (root->child[1] != nullptr)
            clear(root->child[1]);
        delete root;
    }
public:
    Trie() : root(getNode()) {}

    ~Trie() 
    {
        clear(root);
    }

    void insert(int num)
    {
        TrieNode* curr = root;
        for (int i = 31; i >= 0; i--)
        {
            int bit = (num >> i) & 1;
            if (!curr->containsKey(bit))
                curr->put(bit, getNode());
            curr = curr->getNext(bit);
        }
    }

    int getMax(int num)
    {
        TrieNode* curr = root;
        int maxNum = 0;
        for (int i = 31; i >= 0; i--)
        {
            int bit = (num >> i) & 1;
            if (curr->containsKey(1 - bit))
            {
                maxNum = maxNum | (1 << i);
                curr = curr->getNext(1 - bit);
            }
            else
                curr = curr->getNext(bit);
        }
        return maxNum;
    }

};

int findMaximumXOR(vector<int>& nums)
{
    Trie trie;
    int maxXor = 0;
    for (int num : nums)
    {
        trie.insert(num);
        maxXor = max(maxXor, trie.getMax(num));
    }

    return maxXor;
}

int main()
{
    vector<int> nums = { 14,70,53,83,49,91,36,80,92,51,66,70 };
    std::cout << findMaximumXOR(nums);

    return 0;
}

