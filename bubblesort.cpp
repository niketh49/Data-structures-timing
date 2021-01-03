#include <iostream>
#include <sstream>
#include <fstream>
#include "bubblesort.hpp"

BubbleSort::BubbleSort()
{
    numElements = 0;
}

int BubbleSort::getElements()
{
    return numElements;
}

void BubbleSort::setElements(int num)
{
    numElements = num;
}

void BubbleSort::insertElements(int id)
{
    data[numElements] = id;
    numElements++;
}

bool BubbleSort::searchElements(int id)
{
    for(int i=0; i<numElements; i++)
    {
        if(data[i] == id)
        {
            return true;
        }
    }
    return false;
}

void BubbleSort::printElements()
{
    for(int i=0; i<numElements; i++)
    {
        cout << data[i] << endl;
    }
}

void BubbleSort::sort()
{
    bool sorted = false;
    int highest = numElements;
    while(!sorted)
    {
        sorted = true;
        for(int i=0; i<highest-1; i++)
        {
            if(data[i] > data[i+1])
            {
                int temp = data[i];
                data[i] = data[i+1];
                data[i+1] = temp;
                sorted = false;
            }
        }
        highest--;
    }
}