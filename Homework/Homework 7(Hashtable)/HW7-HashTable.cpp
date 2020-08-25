/*
Maura Kieft
Homework #7
11/06/2018
Boese

*/
#include <iostream>
#include <fstream> 
#include <vector>
#include "HW7-HashTable.hpp"

using namespace std;


HashTable::HashTable(int hashTableSize) //constructor
{
	
	hashTable = new wordItem*[hashTableSize];
	numCollisions = 0;
	numItems = 0;
	for (int i=0; i<hashTableSize;i++)
	{
		hashTable[i]=nullptr;
	}

}
HashTable::~HashTable()
{
	for (int i = 0; i< hashTableSize; i++)
	{
		wordItem* temp = hashTable[i];
		while(temp!=nullptr)
		{
			wordItem* temp2 = temp->next;
			delete temp; 
			temp = temp2;
		}
	}
	delete[] hashTable;
}

//function to calculate index for hash 
unsigned int HashTable::getHash(std::string word)
{
	
    int hash = 5381;
    for(unsigned int i = 0; i<(word.length()-1);i++ )
    {
    	hash = ((hash <<5) +hash) +word[i];
    }
    hash %= hashTableSize;
    if(hash <0 )
    {
    	hash+= hashTableSize;
    }
    return hash;
}


void HashTable::addWord(std::string word)
{
	wordItem* newWord = new wordItem;
	newWord->word = word;
	newWord->next = nullptr;
	newWord->count = 1; 
	int index = getHash(word);
	wordItem* temp = hashTable[index];
	
	 
	if(temp != nullptr)
	{
		numCollisions= numCollisions+1;
		newWord->next=hashTable[index];
		hashTable[index] = newWord;
	}
	else
	{
		hashTable[index] = newWord;
	}
	numItems = numItems+1;

	return; 
}



wordItem* HashTable::searchTable(std::string word)
{
	wordItem* temp= hashTable[getHash(word)];
	while(temp!= nullptr && temp->word != word)//search until its found
	{
		temp=temp->next; 
	}
	return temp; 
}


bool HashTable::isInTable(std::string word)
{
	bool present;
	wordItem* temp =searchTable(word);
	if(temp == nullptr)
	{
		present = false;
	}
	else
	{
		present=true;
	}
	return present ;
}
void HashTable::incrementCount(std::string word)
{
	
	wordItem *temp =searchTable(word);
	temp->count += 1;
	return;
}
void HashTable::printTopN(int n)
{
	wordItem* topN[n]; //create new array 
	int minVal = 0;
	int numInArray = 0;

	for(int i=0; i<hashTableSize; i++) //searches the hash table array
	{
		wordItem* temp = hashTable[i];
		while(temp!=nullptr)
		{
			if(temp->count >minVal) //if the count is bigger than the min val currently
			{
				int j = numInArray;
				while(j>0 && (temp->count > topN[j-1]->count)) //while temp is bigger than the count of the top n already in array
				{
					topN[j]=topN[j-1];
					j=j-1;
				}
				topN[j]=temp;
				numInArray=min(numInArray+1,n);
				minVal=topN[numInArray-1]->count; 
			}	
			temp = temp->next;
		}
	}
	for(int i=0; i< n; i++)
	{
		cout << topN[i]->count << " - " << topN[i]->word<<endl;
	}
	return;

}
int HashTable::getNumCollisions()
{
	return numCollisions;
}
int HashTable::getNumItems()
{
	int count = 0;
	for(int i =0; i<hashTableSize;i++)
	{
		wordItem* temp = hashTable[i];
		while(temp!=nullptr)
		{
			count += temp->count;
			temp=temp->next;
		}
	}
	return count;
}
int HashTable::getTotalNumWords()
{
	int count = 0;
	for(int i=0; i<hashTableSize; i++) // searches table size and counts every item
	{
		wordItem* temp = hashTable[i];
		while(temp!= nullptr)
		{
			count += temp->count; //adds to count 
			temp=temp->next;
		}
	}
	return count;
}

/* load stopwords into the stopwords hash table */
void getStopWords(char *ignoreWordFileName, HashTable &stopWordsTable)
{
 
	ifstream inToFile;
	string line;
	inToFile.open(ignoreWordFileName);

	if(inToFile.is_open())
	{
		
		while(inToFile >> line) //reads in file line by line
		{
			stopWordsTable.addWord(line); // adds stopwords to stopwordstable

		}
		inToFile.close(); 
	}
	else
	{
		cout << "File not opened " << endl;
	}
	return;
}




bool isStopWord(std::string word, HashTable &stopWordsTable)
{
	/*bool present = false; 
	unsigned int hash = 5381;
	for(auto c : word) // help on cplusplus.com 
	{
	    hash = hash * 33 +c;
	}
	hash = hash % 50; 
	
	for (int i = 0; i<=50; i++)
	{
		wordItem* temp = &stopWordsTable[i];
		while(temp!=nullptr)
		{
			if(temp->word == word)
			{
				present = true; 
			}
			temp = temp->next; 
		}
	}
	return present; 
	*/

	/*bool isStopWord = false;

	for(int i=0; i<50; i++) //searches the hash table array
	{
		wordItem* temp = stopWordsTable[i];
		while(temp!=nullptr)
		{
			if(temp->word == word) //word found
			{
				isStopWord = true;
			}	
			temp = temp->next;
		}
	}
	return isStopWord;
	*/
	bool isFound;
	isFound = (stopWordsTable.isInTable(word));
	return isFound;

}
//use hash function to get to the right bucket and linked list from that bucket

//delete hash table with[] have to go through linked list and delete nodes before delete[]
