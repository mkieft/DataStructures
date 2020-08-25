/*
Maura Kieft
Homework #7
11/06/2018
Boese

*/

#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include "Hw7-HashTable.hpp"


using namespace std;
int main(int argc ,char* argv[])
{
	if(argc != 5)
	{
		cout << "Usage: ";
		cout << argv[0] << "<number of words> <filename.txt> <ignorefilename.txt>";
		cout << endl;
		return 0;
	}
	HashTable stopWordsTable(STOPWORD_TABLE_SIZE);
	getStopWords(argv[3], stopWordsTable);

	HashTable uniqueWordsTable(atoi(argv[4]));
	ifstream infile;
	infile.open(argv[2]);

	if(infile.is_open())
	{
		string wordIn;
		while (infile>> wordIn) //access line by line
		{
			if(isStopWord(wordIn, stopWordsTable) != true)
			{
				if(uniqueWordsTable.isInTable(wordIn))
				{
					uniqueWordsTable.incrementCount(wordIn);
				}
				else
				{
					uniqueWordsTable.addWord(wordIn);
				}
			}
		}
	}
	else
	{
		cout << "Cannot open file" << endl;
	}

	uniqueWordsTable.printTopN(10);
	cout << "#" << endl;
	cout << "Number of collisions: " << uniqueWordsTable.getNumCollisions() << endl;
	cout << "#" <<endl;
	cout << "Unique non-stop words: " << uniqueWordsTable.getNumItems() << endl;
	cout << "#" << endl;
	cout << "Total non-stop words: " << uniqueWordsTable.getTotalNumWords() << endl;

	return 0;
}
