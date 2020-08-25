#include <iostream> 
#include "HW7-HashTable.hpp"

using namespace std; 

wordItem* HashTable::createNode(string word, word* next)
{
	wordItem* nw = new wordItem;
	nw->word = word;
	nw->next = next;
	return nw; 
}
unsigned int HashTable::getHash(string word)
{
	unsigned int hash = 0;
	for(int i =0; i<word.length(); i++)
	{
		hash+= word[i];

	}
	return hash % STOPWORD_TABLE_SIZE;
}
wordItem* searchTable(std::string word)
{
	int index = getHash(word);
	// if found, return pointer to word 
	wordItemp* temp = stopWordsTable[index]
	while ( temp!= nullptr)
	{
		if(temp->word == word)
		{
			return temp;
		}
		temp = temp->next;
	}
	return nullptr; 
}

/* load stopwords into the stopwords hash table */
void getStopWords(char *ignoreWordFileName, HashTable &stopWordsTable)
{
	ifstream infile(ignoreWordFileName);
	string line;
	HashTable stopWordsTable

	if(infile.is_open())
	{
		while(infile>> line)
		{
			istringstream ss(line);
			string temp;
			while(getline(ss, temp, ''))
			{
				int index = getHash(word);
				wordItem* n = createNode(word, nullptr);

				n->next = stopWordsTable[index];
				stopWordsTable[index] = n;

			}
		}
	}
}




/* check table to see if a word is a stopword or not */
bool isStopWord(std::string word, HashTable &stopWordsTable)
{
	if(searchTable(word) == nullptr)
	{
		return false;
	}
	else
	{
		return true; 
	}
}

void HashTable::printTable()
{
	for (int i=0; i<STOPWORD_TABLE_SIZE; i++)
	{
		cout << i << "|| ";
		wordItem* temp = stopWordsTable[i];
		while(temp)
		{
			cout << temp->word;
			if(temp->next != nullptr)
			{
				cout<< "--->";
			}
			temp = temp->next;
		}
		cout << endl; 
	}
}

