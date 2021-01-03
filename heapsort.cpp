#include <iostream>
#include <sstream>
#include <fstream>
#include "heapsort.hpp"
using namespace std;

MinHeap::MinHeap()
{
    heap = new int[10000];
    numElements = 0;
    capacity = 10000;
}

int MinHeap::peek()
{
    return heap[0];
}

void MinHeap::push(int key)
{
    heap[numElements] = key;
    if(numElements != 1)
    {
        int curr = numElements;
        int parent = ((numElements-1)/2);
        bool valid = false;
        while((curr != 0)&&(!valid))
        {
            valid = true;
            if(heap[curr] < heap[parent])
            {
                int temp = heap[curr];
                heap[curr] = heap[parent];
                heap[parent] = temp;
                curr = parent;
                parent = ((curr-1)/2);
                valid = false;
            }
        }
    }
    numElements++;
}

void MinHeap::pop()
{
    heap[0] = heap[numElements-1];
    numElements--;
    int curr = 0;
    int leftChild = 1;
    int rightChild = 2;
    bool valid = false;
    while(!valid)
    {
        valid = true;
        //if both children dont exist
        if((leftChild >= numElements)&&(rightChild >= numElements))
        {
            valid = true;
        }
        //If only left child exists;
        else if((leftChild < numElements)&&(rightChild >= numElements))
        {
            if(heap[curr] > heap[leftChild])
            {
                valid = false;
                int temp;
                temp = heap[curr];
                heap[curr] = heap[leftChild];
                heap[leftChild] = temp;
                curr = leftChild;   
            }
            else
            {
                valid = true;
            }
        }
        //parent is less than both children
        else if((heap[curr] <= heap[leftChild])&&(heap[curr] <= heap[rightChild]))
        {
            valid = true;
        }
        //If left child smallest
        else if((heap[leftChild] < heap[curr])&&(heap[leftChild] <= heap[rightChild]))
        {
            valid = false;
            int temp;
            temp = heap[curr];
            heap[curr] = heap[leftChild];
            heap[leftChild] = temp;
            curr = leftChild;
        }
        //if right child is smallest
        else if((heap[rightChild] < heap[curr])&&(heap[rightChild] < heap[leftChild]))
        {
            valid = false;
            int temp;
            temp = heap[curr];
            heap[curr] = heap[rightChild];
            heap[rightChild] = temp;
            curr = rightChild;
        }
        leftChild = (2*curr)+1;
        rightChild = (curr*2)+2;
    }
}

int MinHeap::search(int key)
{
    int i = 0;
    while(heap[i] != key)
    {
        i++;
    }
    return i;
}

void MinHeap::printHeap()
{
    for(int i=0; i<numElements; i++)
    {
        cout << heap[i] << endl;
    }
}

int* MinHeap::heapSort()
{
    int* retArr = new int[numElements];
    int i = 0;
    while(numElements != 0)
    {
        retArr[i] = peek();
        pop();
        i++;    
    }
    return retArr;
}

int MinHeap::getNum()
{
    return numElements;
}

void MinHeap::setNum(int num)
{
    numElements = num;
}