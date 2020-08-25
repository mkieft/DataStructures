/*
Maura Kieft
Homework 1
*/
#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>



using namespace std;


void printArray(int myArray[], int numEntries);
int insertIntoSortedArray(int myArray[], int numEntries, int newValue);
void inArrayFind(int myArray[], int numEntries, int findNum);

int main(int argc, char*argv[])
{

	ifstream infile (argv[1]); //to open file from user input
	int myArray[100]; 
	string line; //to store from file
	int numEntries = 0;
	int findNum;

	cout << argv[1] << endl;
	if(infile.is_open())
	{
		while(getline(infile,line))
		{
			int newValue = atoi(line.c_str());
			insertIntoSortedArray(myArray, numEntries, newValue);
			numEntries++;
			printArray(myArray, numEntries);
		}
	}
	printArray(myArray, numEntries);

	cout << "Number of Entries: "<< numEntries << endl;

	cout << "Enter a Number to be found: ";

	cin >>findNum;
	inArrayFind(myArray,numEntries, findNum);
	

	infile.close(); 

	return 0; 


}
void inArrayFind(int myArray[], int numEntries, int findNum)
{
	int pos;
	for(int i =0; i<numEntries; i++)
	{
		if(myArray[i] == findNum)
		{
			pos = i; 
			cout << "Number " << myArray[pos] << " found " << "at position: " << pos +1 << endl; 

		}


	}

	

}
int insertIntoSortedArray(int myArray[], int numEntries, int newValue)
{
	int pos, temp;

	if(numEntries == 0)
	{
		myArray[0] = newValue;
		return 1;
	}
	for (int i = 0; i < numEntries; i++)
	{
		if(myArray[i]<newValue)
		{
			i++;
		}
		else
		{
			temp = myArray[i];
			pos = i+1;
			myArray [i] = newValue;
			break;
		}
	}
	for(int i =pos; i < numEntries +1; i++)
	{
		int tmp = myArray[i];
		myArray[i] = temp;
		temp = tmp; 
	}
	return numEntries +1;


}
void printArray(int myArray[], int numEntries)
{
	for (int i =0; i< numEntries; i++)
	{
		cout << myArray[i];
		if(i != numEntries-1)
		{
			cout << ", ";

		}
		else
		{
			cout << endl; 
		}
	}
}