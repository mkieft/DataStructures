/*
Maura Kieft
Homework 1 Part 2
*/

#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>



using namespace std;
struct student
{
	string username;
	float gpa;
	int age;
};

void addUser(vector<student> &gradeList, string name, float _gpa, int _age);
void printList(const vector<student> &gradeList);


int main(int argc, char*argv[])
{
	vector<student> *gradeList;
	string line; 
	string name;
	string gpa;
	string age;
	int _age;
	int _gpa; 

	ifstream infile(argv[1]);
	cout << "Filename: " << argv[1] << endl; 
	if(infile.is_open())
	{
		while(getline(infile,line))
		{
			stringstream ss(line); 
			getline(ss,name); //extracts name
			getline(ss,gpa);	//extracts gpa
			getline(ss, age);	//extracts age

			_age = stoi(age);	//converts age to int
			_gpa = stof(gpa);	//converts gpa tp floar
 
			addUser(*gradeList, name, _gpa, _age); 
			printList(*gradeList); 

		}
	}
	printList(*gradeList);

	infile.close(); 

	return 0;
}
void addUser(vector<student> &gradeList, string name, float _gpa, int _age)
{
	struct student user; //new struct to assign details
	user.username = name;
	user.gpa = _gpa;
	user.age = _age;

	gradeList.push_back(user); //adds user to gradeList vector


}

void printList(const vector<student> &gradeList)
{
	for (int i = 0; i < gradeList.size(); i++)
	{
		cout << gradeList.at(i).username << "[" << gradeList.at(i).gpa << "] age: " <<gradeList.at(i).age <<endl;

	}


}