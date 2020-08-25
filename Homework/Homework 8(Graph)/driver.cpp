/*
Maura Kieft
Boese
Homework 9
*/

#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>
#include <queue>
#include "graph.hpp"

using namespace std;

int main(int argc, char* argv[])
{
	Graph cities = Graph();  

	
	ifstream infile;
	infile.open(argv[1]);

	string line;
	string element;
	vector<string> cityName; //vector stores city names

	int num;

	if(infile.is_open())
	{
		getline(infile, line);
		stringstream ss(line);

		while(getline(ss, element, ','))
		{
			if(element != "cities")
			{
				cities.addVertex(element);
				cityName.push_back(element);
			}
		}
		int counter1 = 0;
		int counter2 = 0;

		while(getline(infile, line))
		{
			istringstream aa(line);
			getline(aa, element, ','); 

			while(getline(aa,element, ','))
			{
				istringstream(element) >> num; //puts distance into var to compare
				if(num != -1 && num != 0)
				{
					cities.addEdge(cityName[counter1], cityName[counter2], num);
					counter2++;
				}
				counter1++;
			}	
		}

	}

	

		/*getline(infile, line);
		stringstream ss(line);
		
		while(getline(ss, element)) //adds city names to vector
		{
			if(element != "cities")
			{
				city.addVertex(element);
				cityName.push_back(element);
			}
		}
		int count = 0;
		while(getline(infile, line))
		{
			int count2 = 0;
		    
		    istringstream aa(line);
		    getline(aa, element);
		    while(getline(aa, element))
		    {
		        istringstream(element) >> num;
		        if(num != -1 && num != 0)
		        {
		            city.addEdge(cityName[count], cityName[count2], num);
		            count2++;
		        }
		        count++;
		    }
		}
		
	}

	*/


	return 0; 
}