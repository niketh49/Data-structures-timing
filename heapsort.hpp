#include <iostream>
#include <sstream>
#include <fstream>
using namespace std;

class  MinHeap
{
    private:
        int* heap;
        int numElements;
        int capacity;
    public:
        MinHeap();
        void push(int key);
        void pop();
        int peek();
        int search(int key);
        void printHeap();
        int* heapSort();
        int getNum();
        void setNum(int num);
};
