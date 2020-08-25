#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>
#include <queue>

#include "XCgraph.hpp"
using namespace std;

int main(int argc, char* argv[])
{
	Graph graph; //creates new graph

	vector<string> ids; //stores ids from first text file
	ifstream infile; 

	infile.open(argv[1]);
	if(!infile)
	{
		cout << "Couldn't open file." << endl;
		return;
	}
	while(infile.is_open)
	{
		string line;
		string fileID; 
		getline(infile, line);

		while(getline(line, fileID)) //reads in ID textfile, creates vector to store the id's to open their txt file
		{
			ids.push_back({fileID, '.txt'}); //appends id with txt  

		}
	}
	infile.close(); 

	//read in vertices
	string filenameID; //filename to open id
	for(unsigned int n = 0; n < ids.size(); n++) //read in each file name stored in ids vector
	{
		cout << id[n] << endl;

		filenameID = id[n].c_str(); //store id into filename to open txt file

		infile.open(filenameID);

		vector<vertex> networks; 
		string id; // to store elements from txt file 
		string name;
		string friends; 
		string hobbies; 
		string lineIn;
		if(infile.is_open)
		{
			while(!infile.eof())
			{
				getline(infile, id);
				graph.addVertex(id);
				networks[n].id = id;

				getline(infile,name);
				networks[n].name = name;

				getline(infile, hobbies, ','); 
				while(getline(infile, hobbies, ','))
				{
					//graph.addUserToHobby(hobbies, id);
				}
				getline(infile, friends);
				while(getline(infile, friends))
				{
					graph.addEdge(id, friends); 
				}
			}
				


		

				
			
		}


	}
	
	

	//graph.assignSocialCircles(); //finds social circles

	//graph.displayEdges();





	return 0; 
}



