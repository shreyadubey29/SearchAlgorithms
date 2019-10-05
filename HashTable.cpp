#include "HashTable.h"
#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#include <fstream>
#include <stdlib.h>
using namespace std;

long long int comparison=0;
long long int assignment=0;

HashTable::HashTable()
{
    for(int i=0;i<hashTableSize;i++)
    {
        hashTable[i]=new WordPair;
        hashTable[i]->word="null";
        hashTable[i]->counter=0;
        hashTable[i]->next=nullptr;
    }
}

//Function to insert a value in a hash table

void HashTable::insertValue(string word, int counter)
{
    int index=hashKey(word);
    if(hashTable[index]->word=="null")
    {
        assignment++;                       // Assignment in the concordance
        hashTable[index]->word=word;
        hashTable[index]->counter=counter;
    }
    else
    {
        assignment++;                       // Assignment in the concordance
        WordPair* ptr = hashTable[index];
        WordPair* newOne = new WordPair;
        newOne->word=word;
        newOne->counter=counter;
        newOne->next=nullptr;
        while(ptr->next!=nullptr)
        {
            ptr=ptr->next;
        }
        ptr->next=newOne;
    }
}

//Functions to count the items in one bucket

int HashTable::countOfItems(int index)
{
    int flag=0;
    if(hashTable[index]->word=="null")
    {
        return flag;
    }
    else
    {
        flag++;
        WordPair* ptr =hashTable[index];
        while(ptr->next!=nullptr)
        {
            flag++;
            ptr=ptr->next;
        }
    }
    return flag;
}

//Function to search the hash table

bool HashTable::findValue(string word)
{
    int index=hashKey(word);
    comparison++;                       //Comparison in concordance
    if(hashTable[index]->word==word)
    {
        return true;
    }
    else if(hashTable[index]->word!=word&&hashTable[index]->word!="null")
    {
         WordPair* ptr = hashTable[index];
            while(ptr!=nullptr)
            {
                comparison++;           //Comparison in concordance
                if(ptr->word==word)
                {
                    return true;
                }
                ptr=ptr->next;
            }
    }

    return false;
}

//Function to create the key

int HashTable::hashKey(string word)
{
    int key=0;
    int wordSize = word.length();
    for(int i=0;i<wordSize;i++)
    {
        key=key+((int)word[i]*(i+1));
    }
    return key%hashTableSize;
}

//Function to print the output

void HashTable::printTable()
{
    vector <WordPair> output;
    for(int k=0;k<hashTableSize;k++)
    {
        WordPair* ptr = hashTable[k];
        if(ptr->word!="null")
        {
            while(ptr!=nullptr)
            {
                WordPair obj;
                obj.word=ptr->word;
                obj.counter=ptr->counter;
                output.push_back(obj);
                ptr=ptr->next;
            }
        }
    }
    sort(output.begin(),output.end());
    cout<<"Alphabetic"<<endl<<"Number of unique words = "<<numberOfTotalItems()<<endl;
    for(int i=0;i<10;i++)
    {
        cout<<"\""<<output[i].word<<"\""<<" : "<<output[i].counter<<endl;
    }
    cout<<"...\n"<<endl;
    for(int i=(output.size()-10);i<output.size();i++)
    {
        cout<<"\""<<output[i].word<<"\""<<" : "<<output[i].counter<<endl;
    }
    cout<<"Number of total comparisons :"<<comparison<<"    Number of total assignments :"<<assignment<<endl;
}

//Function to increase the counter

void HashTable::increaseCounter(string word)
{
    int index=hashKey(word);

    if(hashTable[index]->word==word)
    {
       hashTable[index]->counter++;
    }
    else
    {
         WordPair* ptr = hashTable[index];
            while(ptr!=nullptr)
            {
                if(ptr->word==word)
                {
                    ptr->counter++;
                }
                ptr=ptr->next;
            }
    }
}

// Function to find total number of items in the hash table

int HashTable::numberOfTotalItems()
{
    int number=0;
    for(int j=0;j<hashTableSize;j++)
    {
        number=number+countOfItems(j);
    }
    return number;
}

