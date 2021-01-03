#include <iostream>
#include <sstream>
#include <fstream>
#include <chrono>
#include <stdlib.h>
#include <ctime>
#include <cstdlib>
#include "heapsort.hpp"

using namespace std;
using namespace std::chrono;

int main()
{
    MinHeap n;
    string filename;
    filename = "dataSetA.csv";
    ifstream file;
    file.open(filename);
    int testData[10000];
    string line;
    int i = 0;

    while(getline(file, line, ',')) 
    {
        int data = stoi(line);
        testData[i] = data;
        i++;
    }

    file.close();

    float insert[100];
    float sort[100];
    int numHundreds = 0;

    for(numHundreds; numHundreds<100; numHundreds++)
    {
        auto start = steady_clock::now();
        for(int j=0; j<((numHundreds+1)*100); j++)
        {
            n.push(testData[j]);
        }
        auto end = steady_clock::now();

        insert[numHundreds] = duration_cast<microseconds>(end-start).count();

        auto start2 = steady_clock::now();
        n.heapSort();
        auto end2 = steady_clock::now();

        sort[numHundreds] = duration_cast<microseconds>(end2-start2).count();

        n.setNum(0);
    }

    string outname;
    outname = "heapsort.csv";
    ofstream outfile;
    outfile.open(outname);

    outfile<< "Insert" << endl;
    for(int i = 0; i<100; i++)
    {
        outfile<< insert[i] << endl;
    }

    outfile<< endl;
    outfile<< "Sort" << endl;
    for(int i = 0; i<100; i++)
    {
        outfile<< sort[i] << endl;
    }
    outfile.close();
}
