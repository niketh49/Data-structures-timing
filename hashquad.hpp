#include <iostream>
#include <fstream>
#include <sstream>

using namespace std;

struct Node
{
    int key;
    int value;
    Node* next;

    Node() {key = 0; value = 0; next = 0;}
    Node(int k, int v) {key = k; value = v; next = 0;}
    ~Node() {}
};

class HashTable
{
    private:
        Node** table;
        int tableSize;
    public:
        HashTable();
        HashTable(int s);
        unsigned int hashFunction(int k);
        void insertItem(int value);
        Node* searchItem(int value);
        void printHashTable(); 
};