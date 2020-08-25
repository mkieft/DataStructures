/*
Maura Kieft 
Homework #7 Help
*/
#include <fstream>
#include <iostream> 
#include <sstream>
#include <string>
#include "HW7-HashTable.hpp"

using namespace std;

int main()
{
	char* ignoreFileName = "HW7-stopWords.txt";
	HashTable stopWordsTable(STOPWORD_TABLE_SIZE);
	getStopWords(ignoreFileName, stopWordsTable);
	printTable(); 


	return 0; 
}