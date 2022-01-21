/* Forward DNS look up is getting IP address for a given domain name typed in the web browser.

The cache should do the following operations :

1. Add a mapping from URL to IP address
2. Find IP address for a given URL. 
*/

#include <iostream>

#include <iostream>
#include <vector>

// There are atmost 27 different chars in a valid URL assuming URL consists [a-z] and (.)
#define CHARS 27

using namespace std;

int getIndex(char c)
{
    return (c == '.') ? 26 : (c - 'a');
}

class TrieNode
{
public:
    bool isEnd;
    string IPAddr;
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
        newNode->IPAddr = "";
        for (int i = 0; i < CHARS; i++)
            newNode->child[i] = nullptr;
        return newNode;
    }

public:
    Trie() : root(getNode()) {}

    void insert(string& url, string& ipAddress)
    {
        TrieNode* curr = root;
        for (char c : url)
        {
            if (!curr->containsKey(c))
                curr->put(c, getNode());
            curr = curr->getNext(c);
        }
        curr->isEnd = true;
        curr->IPAddr = ipAddress;
    }

    string searchDNSCache(string& url)
    {
        TrieNode* curr = root;
        for (char c : url)
        {
            if (!curr->containsKey(c))
                return "";
            curr = curr->getNext(c);
        }

        // If we find the last node for a given ip address, print the URL
        if (curr != nullptr && curr->isEnd)
            return curr->IPAddr;
        return "";
    }
};

int main()
{
    vector<pair<string, string>> urlIP = { {"www.samsung.com", "107.108.11.123"},
                                           {"www.samsung.net", "107.109.123.255"},
                                           {"www.google.in", "74.125.200.106"} };

    Trie trie;
    for (auto& it : urlIP)
        trie.insert(it.first, it.second);

    string urlToSearch = "www.samsung.net";
    string resolvedIP = trie.searchDNSCache(urlToSearch);

    if (resolvedIP == "")
        cout << "Forward DNS look up not resolved in cache" << endl;
    else
        cout << "Forward DNS look up resolved in cache\n" << urlToSearch << "-->" << resolvedIP << endl;

    return 0;
}
