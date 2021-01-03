#include <iostream>
#include <sstream>
#include <fstream>
#include <chrono>
#include <stdlib.h>
#include <ctime>
#include <cstdlib>
#include "dll.hpp"

using namespace std;
using namespace std::chrono;

int main()
{
    DoublyLinkedList n;
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
    float search[100];
    int numHundreds = 0;
    for(numHundreds; numHundreds < 100; numHundreds++)
    {
        //Insert 100
        auto start = steady_clock::now();
        for(int j = (numHundreds*100); j < ((numHundreds+1)*100); j++)
        {
            Node* node = n.getTail();
            n.insertNode(node, testData[j]);
        }
        auto end = steady_clock::now();

        insert[numHundreds] = ((duration_cast<nanoseconds>(end-start).count())/100);

        //creating 100 random numbers
        int searchArray[100];
        for(int k = 0; k<100; k++)
        {
            srand(time(0));
            searchArray[k] = (rand() % (numHundreds+1)*100); 
        }

        //searching 100
        auto start2 = steady_clock::now();
        for(int k = 0; k <100; k++)
        {
            n.searchList(testData[searchArray[k]]);
        }
        auto end2 = steady_clock::now();

        search[numHundreds] = ((duration_cast<nanoseconds>(end2-start2).count())/100);
    }

    string outname;
    outname = "dll.csv";
    ofstream outfile;
    outfile.open(outname);

    outfile<< "Insert" << endl;
    for(int i = 0; i<100; i++)
    {
        outfile<< insert[i] << endl;
    }

    outfile<< endl;
    outfile<< "Search" << endl;
    for(int i = 0; i<100; i++)
    {
        outfile<< search[i] << endl;
    }
    outfile.close();
}