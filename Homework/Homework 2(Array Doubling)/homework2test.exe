#include <cstdlib>
#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

struct wordItem
{
	string word;
	int count;
};

const int STOPWORD_LIST_SIZE = 50;
const int INITIAL_ARRAY_SIZE = 100;

int main(int argc, char*argv[])
{
	
	int n = atoi(argv[1]);
	string filename1(argv[2]);
	string ignoreWordFileName(argv[3]);


	ifstream infile;
	string tmpLine;
	vector<wordItem> wordList;
	

	infile.open(filename1);
	if (infile.is_open())
	{
		while(getline(infile, tmpLine))
        {
			stringstream line(tmpLine);
			wordItem data;
			while(line>>data.word)
            {
               wordList.push_back(data);
            }
        }
	}
	for (int i=0; i < n; i++)
        {
            cout << wordList[i].word << "\n";
        }


	return 0;
}//main