/*
Maura Kieft
Homework #2
9/21/2018
Boese

*/
#include <cstdlib>
#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
 
using namespace std;

struct wordItem					//creates struct 
{
	string word;
	int count = 0;
};

void getStopWords(const char *ignoreWordFileName, vector<string> &_vecIgnoreWords);
bool isStopWord(string word, vector<string>&_vecIgnoreWords);
bool inArray(string wordNow, wordItem list[], int length);
void arrayDb(struct wordItem list[], int length);

int getTotalNumberNonStopWords(wordItem list[], int length);
void arraySort(wordItem list[], int length);
void printTopN(wordItem wordItemList[], int topN);
const int STOPWORD_LIST_SIZE = 50;
const int INITIAL_ARRAY_SIZE = 100;

int main(int argc, char*argv[])
{
	vector<string> vecIgnoreWords(STOPWORD_LIST_SIZE);

	if (argc != 4)
	{
		cout << "Usage: ";
		cout << argv[0] << "<number of words> <filename.txt> <ignorefilename.txt>";
		cout << endl;
		return 0;
	}
	getStopWords(argv[3], vecIgnoreWords);		//calls getStopWords function which loads vector with stop words

	int topN = atoi(argv[1]);
	char* wordList = argv[2];

	ifstream infile(wordList);
	string line;
	int numCount = 0;
	int arrayCount = 0;
	int numDoublings = 0;

	

	wordItem* wordCount; //pointer to use for doubling
	wordCount = new wordItem[INITIAL_ARRAY_SIZE];
	int currentMax = INITIAL_ARRAY_SIZE;

	if (infile.is_open())
	{

		while (infile >>line)				//access word by word from file
		{
			istringstream ss(line);
			string temp;
			while (getline(ss, temp, ''))
			{

			if((isStopWord(temp, vecIgnoreWords) != true) //if word not in stopwords vector or array 
			{
				 
				if (arrayCount > 0)		//checking if there's room in the array
				{
					for (int j = 0; j < arrayCount; j++)
					{
						if(wordCount[j].word == temp)
						{
							wordCount[j].count++;			//sets the struct word in the array
							break;
						}		
						if (j == arrayCount-1)
						{
							wordCount[arrayCount].word = temp;
							wordCount[arrayCount].count= 0;
							arrayCount++;
						}			
					}
				} 
				if (arrayCount== 0)
				{
					wordCount[arrayCount].word = temp;
					wordCount[arrayCount].count = 0;
					arrayCount++;
				}
			}
				if (currentMax == arrayCount)					//double array if not enough room
				{

					wordItem* tempArr = new wordItem[currentMax*2];
						for (int a = 0; a< currentMax; a++)
							{
									tempArr[a].word=list[a].word;		//copies data into new array 
									tempArr[a].count = list[a].count;

							}
					delete[]wordCount;			//frees up old array memory
					wordCount = tempArr;
					currentMax = currentMax * 2;
					numDoublings++;	//adds one to number of times array was doubled

					

				}
				
			}
		}
		
	}
	
	int numberOfUniqueWords = 0;
	for (int i = 0; i < currentMax; i++){
		if(wordCount[i].count > 0);
		{
			numberOfUniqueWords++;
		}

	}
	arraySort(wordCount, currentMax); //calls function to sort array from largest to smallest value 

	printTopN(wordCount, stoi(argv[1])); //prints topN words taken from command line arg[1]

	
	cout << "#" << endl;
	cout << "Array doubled: " << numDoublings << endl;
	cout << "#" << endl;
	cout << "Unique non-stop words: " << numberOfUniqueWords;
	cout << "#" << endl;
	cout << "Total non-stop words: ";
	cout << getTotalNumberNonStopWords(wordCount, currentMax) << endl;


	return 0;

}//main
void getStopWords(char *ignoreWordFileName,vector<string> &_vecIgnoreWords)
{
	ifstream inToFile(ignoreWordFileName);
	string line;

	if (inToFile.is_open())
	{
		int i = 0;
		while (getline(inToFile,line))		//reads file line by line into vector
		{
			_vecIgnoreWords.at(i)=line;
			i++;
		}
		
	}
	

	

}//getStopWords

bool isStopWord(string word, vector<string> &_vecIgnoreWords)			//searches from beginning to end for the word
{
	for (unsigned int i=0; i < _vecIgnoreWords.size(); i++)
	{
		if(_vecIgnoreWords.at(i) == word)
		{
			return true;
		}
	}
	return false; 


}//isCommon



void arraySort(wordItem wordItemList[], int numberOfUniqueWords)
{
	flag = 1;
	wordItem temp;
	int numCount = numberOfUniqueWords;
	for (int i =1; (i<= numCount) && flag; i++)
	{
		flag = 0;
		for (int j = 0; j< (numCount -1); j++)
		{
			if(wordItemList[j+1].count > wordItemList[j].count)		//switches ascending order
			{
				temp = wordItemList[j];
				wordItemList[j]= wordItemList[j+1];
				wordItemList[j+1] = temp;
				flag = 1;			//indicates swap 
			}
		}
	}
	return;

}//arraySort

void printTopN(wordItem wordItemList[], int n)
{
	for (int k = 0; k <= n ; k++)
	{
		cout << wordItemList[k].count << " - " << wordItemList[k].word << endl;
	}
}//printTopN

int getTotalNumberNonStopWords(wordItem wordItemList[], int numberOfUniqueWords)
{
	int totalWords = 0;

   for (int i = 0; i < numberOfUniqueWords; i++)
   {  
       totalWords = totalWords + wordItemList[i].count;
   }

   return totalWords;
    
	
}//getTotalNumberNonStopWords
