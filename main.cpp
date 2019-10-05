#include <iostream>
#include <string>
#include <sstream>
#include <bits/stdc++.h>
#include <algorithm>

using namespace std;

long long int comparison=0;
long long int assignment=0;

struct WordPair             //Structure for the word and its counter
{
    string word;
    int counter=0;
};

int binarySearch(vector<WordPair> &output, string word1);
void printOutput(vector<WordPair> &output);

int main()
{
     int n=0;
    string * inputArray=new string[1200000];
    int nLine=0;
    int location;
    ifstream inputFile;
    inputFile.open("C:/Users/khare/Desktop/FAll2018/Courses/Algorithms/Assignment/Assignment_2/wordlist.txt");// Address of the data file from which input is taken
    char a,b,c;
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
        a=inputArray[n].at(0);
        if(isalpha(a))
        {
            inputArray[n]=s;
        }
        else
        {
          b=inputArray[n].at(1);
          if(isalpha(b))
          {
             inputWord=inputArray[n].substr(2);
             inputArray[n]=inputWord;
          }
          else
          {
              c=inputArray[n].at(2);
              if(isalpha(c))
              {
                  inputWord=inputArray[n].substr(3);
                  inputArray[n]=inputWord;
              }
              else
              {
                  n++;
                  continue;
              }
          }
        }
        n++;
    }
    inputFile.close();
    vector<WordPair> output;
    WordPair newOne;
    WordPair temp;
    for(int i=0;i<n;i++)
    {
        {
            int j;
            location=binarySearch(output,inputArray[i]);
            if(location==(-1))
            {
                assignment++;                   //Assignment in concordance
                newOne.word=inputArray[i];
                newOne.counter=1;
                output.push_back(newOne);
            }
            else if(location<(-1))
            {
                for(j=0;j<output.size();j++)
                {
                    comparison++;                                   //Comparison in concordance
                    if((inputArray[i].compare(output[j].word)<0))
                    {
                        break;
                    }
                }
                assignment++;                   //Assignment in concordance
                newOne.word=inputArray[i];
                newOne.counter=1;
                output.push_back(temp);
                for(int l=(output.size()-1);l>=j;l--)
                {
                    assignment++;               //Assignment in concordance
                    output[l]=output[l-1];
                }
                assignment++;
                output[j]=newOne;               //Assignment in concordance
            }
            else
            {
                output[location].counter++;
            }
        }
    }
    printOutput(output);
    return 0;
}

// function for Binary search

int binarySearch(vector<WordPair> &output, string word1)
{
    int startPoint=0;
    int mid=0;
    int endPoint=(output.size()-1);
    if(output.size()==0)
    {
        return -1;
    }
    else
    {
        while(startPoint<=endPoint)
        {
            mid=floor((startPoint+endPoint)/2);
            comparison++;                           //Comparison in the concordance
            if(output[mid].word<word1)
            {
                startPoint=mid+1;
            }
            else if(output[mid].word>word1)
            {
                endPoint=mid-1;
            }
            else if(output[mid].word==word1)
            {
                return mid;
            }
        }
        return -2;
    }
}

// Function to print the output

void printOutput(vector<WordPair> &output)
{
    cout<<"Alphabetic"<<endl<<"Number of unique words = "<<output.size()<<endl;
    for(int k=0;k<10;k++)
    {
        cout<<"\""<<output[k].word<<"\""<<" : "<<output[k].counter<<endl;
    }
    cout<<"..."<<endl;
    for(int k=(output.size()-10);k<output.size();k++)
    {
         cout<<"\""<<output[k].word<<"\""<<" : "<<output[k].counter<<endl;
    }
    cout<<"Number of total comparisons :"<<comparison<<"    Number of total assignments :"<<assignment<<endl;
}

