#include<iostream>
#include<math.h>
#include<string>
#include<fstream>
#include<sstream>
#include "hashquad.hpp"

using namespace std;

HashTable::HashTable()
{
    tableSize = 40009;
    table = new Node*[40009];
    for (int i = 0; i < tableSize; i++) table[i] = NULL;
}

HashTable::HashTable(int s) 
{
    tableSize = s;
    table = new Node* [s];
    for (int i = 0; i < tableSize; i++) table[i] = NULL;
}

unsigned int HashTable::hashFunction(int k)
{
    return (k % tableSize);
}


void HashTable::insertItem(int value)
{
    int index = hashFunction(value);
    int tempindex;
    Node* in = new Node;
    in->key = index;
    int i = 0;
    while(index < tableSize)
    {
        tempindex = index + pow(i, 2);
        tempindex = tempindex % tableSize;
        if(table[tempindex] == NULL)
        {
            in->value = value;
            table[tempindex] = in;
            break;
        }
        i++;
    }
}

Node* HashTable::searchItem(int value)
{
    int index = hashFunction(value);
    int tempindex;
    int i = 0;
    while(index < tableSize)
    {
        tempindex = index + pow(i, 2);
        tempindex = tempindex % tableSize;
        if(table[tempindex]->value == value)
        {
            return table[tempindex];
        }
        i++;
    }
}


void HashTable::printHashTable()
{
    for(int i=0; i < tableSize; i++)
    {
        if(table[i] == NULL)
        {
            cout << i << " --" << endl;
        }
        else
        {
            cout << i << " -- " << table[i]->value << endl;
        }  
    }
}