// Program to implement double hashing

#include <iostream>

// Hash table size
#define TABLE_SIZE 13

// Used in second hash function.
#define PRIME 7

class DoubleHash 
{
    int* hashTable;
    int curr_size;

public:
    DoubleHash()
    {
        hashTable = new int[TABLE_SIZE];
        curr_size = 0;
        for (int i = 0; i < TABLE_SIZE; i++)
            hashTable[i] = -1;
    }

    // function to check if hash table is full
    bool isFull()
    {
        // if hash size reaches maximum size
        return (curr_size == TABLE_SIZE);
    }

    // function to calculate first hash
    int hash1(int key)
    {
        return (key % TABLE_SIZE);
    }

    // function to calculate second hash
    int hash2(int key)
    {
        return (PRIME - (key % PRIME));
    }

    // function to insert key into hash table
    void insertIntoHashTable(int key)
    {
        // if hash table is full
        if (isFull())
            return;

        // get index from first hash
        int index = hash1(key);

        // if collision occurs
        if (hashTable[index] != -1) 
        {
            // get index2 from second hash
            int index2 = hash2(key);
            int i = 1;
            while (1) 
            {
                // get newIndex
                int newIndex = (index + i * index2) % TABLE_SIZE;

                // if no collision occurs, store the key
                if (hashTable[newIndex] == -1) 
                {
                    hashTable[newIndex] = key;
                    break;
                }
                i++;
            }
        }
        // if no collision occurs
        else
            hashTable[index] = key;
        curr_size++;
    }

    // function to search key in hash table
    void search(int key)
    {
        int index1 = hash1(key);
        int index2 = hash2(key);
        int i = 0;
        while (hashTable[(index1 + i * index2) % TABLE_SIZE] != key) 
        {
            if (hashTable[(index1 + i * index2) % TABLE_SIZE] == -1) 
            {
                std::cout << key << " does not exist" << std::endl;
                return;
            }
            i++;
        }
        std::cout << key << " found" << std::endl;
    }

    // function to display the hash table
    void displayHashTable()
    {
        std::cout << "Hash Table :" << std::endl;
        for (int i = 0; i < TABLE_SIZE; i++) 
        {
            if (hashTable[i] != -1)
                std::cout << i << " --> " << hashTable[i] << std::endl;
            else
                std::cout << i << std::endl;
        }
    }
};

// Driver's code
int main()
{
    int a[] = { 19, 27, 36, 10, 64 };
    int n = sizeof(a) / sizeof(a[0]);

    // inserting keys into hash table
    DoubleHash h;
    for (int i = 0; i < n; i++) 
    {
        h.insertIntoHashTable(a[i]);
    }

    // searching some keys
    h.search(36); // This key is present in hash table
    h.search(100); // This key does not exist in hash table

    // display the hash Table
    h.displayHashTable();
    return 0;
}