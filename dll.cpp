#include "dll.hpp"
#include <iostream>
#include <fstream>
#include <sstream>

using namespace std;

DoublyLinkedList::DoublyLinkedList()
{
    head = NULL;
    tail = NULL;
}

Node* DoublyLinkedList::getHead()
{
    return head;
}

Node* DoublyLinkedList::getTail()
{
    return tail;
}

void DoublyLinkedList::insertNode(Node* prev, int key)
{
    if(head == NULL)
    {
        head = new Node;
        head->key = key;
        head->next = NULL;
        head->prev = NULL;
        tail = head;
    }
    else if(prev == NULL)
    {
        Node* newNode = new Node;
        newNode->key = key;
        newNode->next = head;
        head = newNode;
        newNode->prev = NULL;
    }
    else
    {
        Node* newNode = new Node;
        newNode->key = key;
        Node* post = prev->next;
        if(post == NULL)
        {
            newNode->next = NULL;
            prev->next = newNode;
            newNode->prev = prev;
            tail = newNode;
        }
        else
        {
            newNode->next = post;
            post->prev = newNode;
            prev->next = newNode;
            newNode->prev = prev;
        }
    }
          
}

Node* DoublyLinkedList::searchList(int key)
{
    Node* temp = head;
    while((temp != NULL)&&(temp->key != key))
    {
        temp = temp->next;
    }
    return temp;
}

void DoublyLinkedList::printList()
{
    Node* temp = head;
    while(temp != NULL)
    {
        cout<< temp->key <<"->";
        temp = temp->next;
    }
    cout << endl;
}