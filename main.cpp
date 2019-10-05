#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <string>
#include <bits/stdc++.h>
#include <algorithm>
#include "hashtable.h"
using namespace std;

void printOutput(HashTable H);
int getKey(string word);


int main()
{
    int n=0;
    string * inputArray=new string[1200000];
    ifstream inputFile;
    inputFile.open("C:/Users/khare/Desktop/FAll2018/Courses/Algorithms/Assignment/Assignment_2/wordlist.txt");// Address of the data file from which input is taken
    string inputWord;
    while(!inputFile.eof())
    {
        char str[100];
        inputFile.getline(str,100);
        inputArray[n]=str;
        if(inputArray[n].empty())
        {
            continue;
        }
        if(!isalpha(inputArray[n].at(0)))
        {
            continue;
        }
        string s = inputArray[n];
        transform(s.begin(), s.end(), s.begin(), ::tolower);    // converting to lowercase
        inputArray[n]=s;
        n++;
    }
    inputFile.close();
    HashTable H;
    for(int i=0;i<n;i++)
    {
        if(H.findValue(inputArray[i]))
        {
            H.increaseCounter(inputArray[i]);
        }
        else
        {
            H.insertValue(inputArray[i],1);
        }
    }
    H.printTable();
    return 0;
}


