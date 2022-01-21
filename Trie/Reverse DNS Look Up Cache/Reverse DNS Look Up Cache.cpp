/* Reverse DNS look up is using an internet IP address to find a domain name. For example, if you type 74.125.200.106 in browser, 
it automatically redirects to google.in. */

#include <iostream>

#include <iostream>
#include <vector>

// There are atmost 11 different chars in a valid IP address
#define CHARS 11

using namespace std;

int getIndex(char c) 
{ 
    return (c == '.') ? 10 : (c - '0'); 
}

class TrieNode
{
public:
    bool isEnd;
    string URL;
    TrieNode* child[CHARS];
    bool containsKey(char ch)
    {
        return child[getIndex(ch)] != nullptr;
    }

    TrieNode* getNext(char ch)
    {
        return child[getIndex(ch)];
    }

    void put(char ch, TrieNode* node)
    {
        child[getIndex(ch)] = node;
    }
};

class Trie {
private:
    TrieNode* root;

    TrieNode* getNode()
    {
        TrieNode* newNode = new TrieNode();
        newNode->isEnd = false;
        newNode->URL = "";
        for (int i = 0; i < CHARS; i++)
            newNode->child[i] = nullptr;
        return newNode;
    }

public:
    Trie() : root(getNode()) {}

    void insert(string& ipAddress, string& url)
    {
        TrieNode* curr = root;
        for (char c : ipAddress)
        {
            if (!curr->containsKey(c))
                curr->put(c, getNode());
            curr = curr->getNext(c);
        }
        curr->isEnd = true;
        curr->URL = url;
    }

    string searchDNSCache(string& ipAddress)
    {
        TrieNode* curr = root;
        for (char c : ipAddress)
        {
            if (!curr->containsKey(c))
                return "";
            curr = curr->getNext(c);
        }

        // If we find the last node for a given ip address, print the URL
        if (curr != nullptr && curr->isEnd)
            return curr->URL;
        return "";
    }

};

int main()
{
    vector<pair<string, string>> ipUrl = { {"107.108.11.123", "www.samsung.com"}, 
                                           {"107.109.123.255", "www.samsung.net"}, 
                                           {"74.125.200.106", "www.google.in"} };

    Trie trie;
    for (auto& it : ipUrl)
        trie.insert(it.first, it.second);

    string ipToSearch = "74.125.200.106";
    string resolvedUrl = trie.searchDNSCache(ipToSearch);

    if (resolvedUrl == "")
        cout << "Reverse DNS look up not resolved in cache" << endl;
    else
        cout << "Reverse DNS look up resolved in cache\n" << ipToSearch << "-->" << resolvedUrl << endl;

    return 0;
}
