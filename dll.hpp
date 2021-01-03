#include <string.h>
#include <math.h>
#include <iostream>
#include <fstream>
#include <sstream>

using namespace std;

struct Node
{
    int key;
    Node* next;
    Node* prev;
};

class DoublyLinkedList
{
    private:
        Node* head;
        Node* tail;
    public:
        DoublyLinkedList();
        Node* getHead();
        Node* getTail();
        void insertNode(Node* prev, int key);
        Node* searchList(int key);
        void printList();
};