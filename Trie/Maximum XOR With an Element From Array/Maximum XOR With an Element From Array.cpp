/*  You are given an array nums consisting of non-negative integers. You are also given a queries array, where queries[i] = [xi, mi].

The answer to the ith query is the maximum bitwise XOR value of xi and any element of nums that does not exceed mi. In other words, 
the answer is max(nums[j] XOR xi) for all j such that nums[j] <= mi. If all elements in nums are larger than mi, then the answer is -1.

Return an integer array answer where answer.length == queries.length and answer[i] is the answer to the ith query.

Example 1:

Input: nums = [0,1,2,3,4], queries = [[3,1],[1,3],[5,6]]
Output: [3,3,7]
Explanation:
1) 0 and 1 are the only two integers not greater than 1. 0 XOR 3 = 3 and 1 XOR 3 = 2. The larger of the two is 3.
2) 1 XOR 2 = 3.
3) 5 XOR 2 = 7.

Example 2:

Input: nums = [5,2,4,6,6,3], queries = [[12,4],[8,1],[6,3]]
Output: [15,-1,5]
*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// Method 1. Brute force
/*
vector<int> maximizeXor(vector<int>& nums, vector<vector<int>>& queries)
{
    vector<int> result(size(queries));
    int index = 0;
    for (auto& query : queries)
    {
        int x = query[0];
        int m = query[1];

        int maxXor = -1;
        for (int num : nums)
        {
            if (num <= m)
                maxXor = max(maxXor, num ^ x);
        }

        result[index++] = maxXor;
    }
    return result;

} */

// Method 2: Using Trie
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
    Trie() : root(getNode()) {

    }

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

vector<int> maximizeXor(vector<int>& nums, vector<vector<int>>& queries)
{
    int querySize = size(queries);
    vector<int> result(querySize);
    sort(nums.begin(), nums.end());

    vector<pair<int, pair<int, int>>> offlineQueries(querySize);
    for (int i = 0; i < querySize; ++i)
        offlineQueries[i] = { queries[i][1], {queries[i][0], i} };
    sort(offlineQueries.begin(), offlineQueries.end());

    Trie trie;
    int i = 0;
    int n = size(nums);
    for (auto& oq : offlineQueries)
    {
        int mi = oq.first;
        int xi = oq.second.first;
        int queryIndex = oq.second.second;

        while (i < n && nums[i] <= mi)
            trie.insert(nums[i++]);
        if (i != 0)
            result[queryIndex] = trie.getMax(xi);
        else
            result[queryIndex] = -1;
    }

    return result;
}

int main()
{
    vector<int> nums = { 0, 1, 2, 3, 4 };
    vector<vector<int>> queries = { {3, 1},{1, 3},{5, 6} };
    vector<int> results = maximizeXor(nums, queries);

    for (int result : results)
        cout << result << endl;

    return 0;
}

