#ifndef HASHTABLE_H
#define HASHTABLE_H
#include <string>
#include <vector>
using namespace std;

class HashTable
{
    public:
        HashTable();
        void insertValue (string word, int counter);
        bool findValue(string word);
        int hashKey(string key);
        int countOfItems(int index);
        void printTable();
        void increaseCounter(string word);
        int numberOfTotalItems();


    private:
        static const int hashTableSize=100; // hash table size
        struct WordPair                         // structure with the word and counter
{
    string word;
    int counter=0;
    WordPair* next;
    bool operator < (const WordPair& str) const
    {
        return (word < str.word);
    }
};
        WordPair* hashTable[hashTableSize];    //array for the hash table

};

#endif // HASHTABLE_H
