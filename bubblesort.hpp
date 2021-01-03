#include <iostream>
#include <sstream>
#include <fstream>

using namespace std;

class BubbleSort
{
    private:
        int data[10000];
        int numElements;        
    public:
        BubbleSort();
        int getElements();
        void setElements(int num);
        void insertElements(int id);
        bool searchElements(int id);
        void printElements();
        void sort();
};