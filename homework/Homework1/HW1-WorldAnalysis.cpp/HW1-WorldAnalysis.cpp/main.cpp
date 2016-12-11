//
//  main.cpp
//  HW1-WorldAnalysis.cpp
//
//  Created by Nabil Ettachfini,  8/29/16, Homework 1
// prof: Elle Boese
//  Copyright © 2016 Nabil Ettachfini. All rights reserved.
//

#include <iostream>
#include <fstream>
#include <cstdlib>
#include <vector>
#include <string>


using namespace std;

// struct to store word + count combinations

struct wordItem

{
    wordItem() : word(), count (0) {}
    string word;
    int count;
};

/*
 
 * Function name: getStopWords
 
 * Purpose: read stop word list from file and store into vector
 
 * @param ignoreWordFile - filename (the file storing ignore words)
 
 * @param _vecIgnoreWords - store ignore words from the file (pass by reference)
 
 * @return - none
 
 * Note: The number of words is fixed to 50
 
 */

void getStopWords(char *ignoreWordFileName, vector<string>& _vecIgnoreWords); //

/*
 
 * Function name: isCommonWord
 
 * Purpose: to see if a word is a common word
 
 * @param word - a word (which you want to check if it is a common word)
 
 * @param _vecIgnoreWords - the vector type of string storing ignore/common words
 
 * @return - true (if word is a common word), or false (otherwise)
 
 */

bool isCommonWord(string word, vector<string>& _vecIgnoreWords);

/*
 
 * Function name: printTopN
 
 * Purpose: to print the top N high frequency words
 
 * @param wordItemList - a pointer that points to an array of wordItems
 
 * @param topN - the number of top frequency words to print
 
 * @return none
 
 */

void printTopN(wordItem wordItemList[], int topN);

void  doubleArray (wordItem **arr,  int  *currSize);

bool iswordnotused ( string word,  wordItem wordItemList[], int arrSize); // find if word is already in item list

int getTotalNumberNonCommonWords (wordItem wordItemList[] ,int arrSize);

int getAllcommon(wordItem wordItemList[] ,int arrSize);

const int STOPWORD_LIST_SIZE = 50;

// ./a.out 10 HW1-HungerGames_edit.txt HW1-ignoreWords.txt

int main(int argc, char* argv[])

{
    
    vector<string> vecIgnoreWords(STOPWORD_LIST_SIZE);
    int uniqueWordsArrSize=100;
    wordItem *uniqueWords= new wordItem[uniqueWordsArrSize];
    // verify we have the correct # of parameters, else throw error msg & return
    
    if (argc != 4)
        
    {
        
        
        cout << "Usage: ";
        
        cout << argv[0] << " <number of words> <filename.txt> <ignorefilename.txt>";
        
        cout << endl;
        
        
        return 0;
    }
    
    int numCommonWords = stoi(argv[1]);
    
    char *stopWords = argv[3];
    
    /* **********************************
     
     1. Implement your code here.
     
     Read words from HW1-HungerGames_edit.txt, store and count the words.
     
     2. Implement the three functions after the main() function seperately.
     
     ********************************** */
   getStopWords(stopWords, vecIgnoreWords);
    
    ifstream txtstream;
    txtstream.open(argv[2]); // opening file
    if(txtstream.fail())
    {
        cout<<"Could not read the file"<<endl;
        return 1;
    }
    
    string currWord;
    int currIndex=0;
    int arrDoubles=0;
    while( txtstream>> currWord)
    {
        if( !isCommonWord(currWord, vecIgnoreWords))
        {
            if( iswordnotused(currWord, uniqueWords,uniqueWordsArrSize)) // adding the unique word after doubling is causing the error
            {
                
                uniqueWords[currIndex] .word= currWord; //add unique non common word to the list  of unique
                uniqueWords[currIndex].count++; // increase  count by 1 and increase the current index
                currIndex++;
            }
            else
            {
                for(int i=0; i< currIndex;i++)
                {
                    if( uniqueWords[i].word == currWord)
                    {
                        uniqueWords[i].count++;
                        break;
                    }
                }
            }
            // find  this non unique word and increase its count by 1;
        }
        
        if(currIndex>= uniqueWordsArrSize)
        {
            doubleArray( &uniqueWords, &uniqueWordsArrSize);
            arrDoubles++;
        }
    }
    printTopN(uniqueWords, numCommonWords);
    
    cout<<"#"  << endl;
    cout<<   "Array doubled: "   << arrDoubles <<endl;
    cout<< "#"<<endl;
    cout<<   "Unique non-common words: "  <<  getTotalNumberNonCommonWords (uniqueWords, uniqueWordsArrSize) << endl;
    cout<<  "#"  <<endl;
    cout <<"Total non-common words: " << getAllcommon( uniqueWords, uniqueWordsArrSize)  <<  endl;
    
    
    
    txtstream.close();
    
    return 0;
}

void  getStopWords(char *ignoreWordFileName, vector<string>& _vecIgnoreWords)

{
    
    ifstream file1;
    file1.open(ignoreWordFileName);
    if(file1.fail())
    {
        return;
    }
    string currWord;
    int currIndex=0;
    for (int i=0;  i <_vecIgnoreWords.size(); i++)
    {
        
        file1>> currWord;  // reads  a word from currword from the file
        _vecIgnoreWords[currIndex]=currWord;
        currIndex ++;
    }
    
    file1.close();
    return ;
    
}

bool isCommonWord(string word, vector<string>& _vecIgnoreWords)

{
    for( int i=0 ; i < _vecIgnoreWords .size(); ++i)
    {
        if(word== _vecIgnoreWords[i]){
            return true;
        }
    }
    return false;
    
}

bool iswordnotused ( string word,  wordItem wordItemList[], int arrSize)
{
    for( int i=0 ;i < arrSize;i++)
    {
        if ( wordItemList[i].word.empty()) // get word from the struct and checking if empty
        {
            break;
        }
        if (word== wordItemList[i].word) // go through each word looking for similar entries
            
        {
            return false;
        }
    }
    return true;
    
}


void doubleArray (wordItem **arr,  int  *currSize)
{
    wordItem *tempVals = new wordItem[*currSize];  // copy values from old array to a new one.
    
    for (int i=0; i< *currSize; ++i)
    {
        tempVals[i].word=(*arr)[i].word;
        tempVals[i].count=(*arr)[i].count;
    }
    
    delete [] (*arr);
    
    
    (*arr) = new wordItem[2*(*currSize)];
    
    for(int i=0; i<(*currSize); i++)
    {
        (*arr)[i].word=tempVals[i].word;
        (* arr)[i].count=tempVals[i].count;
        
    }
    delete [] tempVals;
    *currSize *= 2;
    
    return;
}
void printTopN(wordItem wordItemList[], int topN)
{
    
    wordItem  *mostCommonWords = new wordItem[topN];
    
    // Now get top n words by looping through all values of word list
    // several times, excluding already-added words when they're found
    for (int i = 0; i < topN; i++)
    {
        int currMaxIndex = 0;
        for (int j = 0; !wordItemList[j].word.empty(); j++)
        {
            if (wordItemList[currMaxIndex].count < wordItemList[j].count)
            {
                // Compare this word to the highest words already in the
                // list to exclude it
                bool alreadyExists = false;
                for (int k = 0; k < i; k++)
                {
                    if (wordItemList[j].word == mostCommonWords[k].word)
                    {
                        alreadyExists = true; break;
                    }
                }
                if (!alreadyExists)
                {
                    currMaxIndex = j;
                }
            }
        }
        // Here reference is okay, so we won't copy the struct's vars
        mostCommonWords[i] = wordItemList[currMaxIndex];
    }
    
    // Finally, print all the words with counts
    for (int i = 0; i < topN; i++)
    {
        cout << mostCommonWords[i].count << " - "
        << mostCommonWords[i].word << endl;
    }
    return;
}
int getTotalNumberNonCommonWords (wordItem wordItemList[] ,int arrSize)
{
    int i;
    
    for(i=0 ; i < arrSize; i++)
    {
        if ( wordItemList[i].word.empty())
        {
            break;
        }
    }
    return i;
}
int getAllcommon(wordItem wordItemList[] ,int arrSize)
{
    int sum=0;
    for( int i=0; i < arrSize; ++i)
    {
        sum += wordItemList[i].count;
    }
    return sum;
}


