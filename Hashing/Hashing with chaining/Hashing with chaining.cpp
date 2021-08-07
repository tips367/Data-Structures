// Hashing with chaining

#include <iostream>
#include <list>

class Hash
{
public:
    Hash(int V); 

    // inserts a key into hash table
    void insertItem(int x);

    // deletes a key from hash table
    void deleteItem(int key);

    // hash function to map values to key
    int hashFunction(int x) 
    {
        return (x % BUCKET);
    }
    void displayHash();

private:
    int BUCKET;            // No. of buckets
    std::list<int>* table; // Pointer to an array containing buckets
};

Hash::Hash(int b)
{
    this->BUCKET = b;
    table = new std::list<int>[BUCKET];
}

void Hash::insertItem(int key)
{
    int index = hashFunction(key);
    table[index].push_back(key);
}

void Hash::deleteItem(int key)
{
    // get the hash index of key
    int index = hashFunction(key);

    // find the key in (index)th list
    std::list<int> ::iterator i;
	for (i = table[index].begin(); i != table[index].end(); i++) 
    {
		if (*i == key)
			break;
	}

    // if key is found in hash table, remove it
    if (i != table[index].end())
        table[index].erase(i);
}

// function to display hash table
void Hash::displayHash() 
{
    std::cout << "\n\nHash table: \n";
    for (int i = 0; i < BUCKET; i++) {
        std::cout << i;
        for (auto x : table[i])
            std::cout << " --> " << x;
        std::cout << std::endl;
    }
}

int main()
{
    // array that contains keys to be mapped
    int a[] = { 15, 11, 27, 8, 12 };
    int n = sizeof(a) / sizeof(a[0]);

    Hash h(7);   // 7 is count of buckets in hash table

    for (int i = 0; i < n; i++)
        h.insertItem(a[i]);

    // display the Hash table
    h.displayHash();

    // delete 12 from hash table
    h.deleteItem(12);

    // display the Hash table
    h.displayHash();

    return 0;
}
