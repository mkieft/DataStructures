#include "MovieTree.hpp"
#include <iostream>
#include <string>
#include <fstream>

using namespace std;

int main(int argc, char*argv[1])
{
	ifstream infile;

	if(argc != 2)
	{
		cout << "Filename not provided." << endl;
		return 0;
	}
	else
	{
	infile.open(argv[1]);
	//}

	MovieTree Movies;
	string title;
	string fName;
	char ch;
	int rank, quantity, year;

	if(infile.is_open())
	{
		while(infile >>rank)
		{
			infile>>ch;
			title = "";
			while(true)
			{
				ch = infile.get();
				if(ch == ',')
				{
					break;
				}
				else
				{
					title += ch;
				}
			}
			infile >> year;
			infile >> ch;
			infile >> quantity;
			Movies.addMovieNode(rank,title, year, quantity);
		}
	}
	else
	{
		cout << "Can not open the file." <<endl;
		return 0;
	}


	int option;
	do
	{
       cout << "======Main Menu======" << endl;
       cout << "1. Find a movie" << endl;
       cout << "2. Rent a movie" << endl;
       cout << "3. Print the inventory" << endl;
       cout << "4. Delete a movie" << endl;
       cout << "5. Count movies " << endl;
       cout << "6. Quit" << endl;
       cin >> option;
       switch (option){
       case 1:
           cout << "Enter title:" << endl;
           getline(cin, title);
           getline(cin, title);
           Movies.findMovie(title);
           break;
       case 2:
           cout << "Enter title:" << endl;
           getline(cin, title);
           getline(cin, title);
           Movies.rentMovie(title);
           break;
       case 3:
           Movies.printMovieInventory();
           break;

       case 4:
       		cout << "Enter title: " << endl;
       		getline(cin, title);
       		getline(cin, title);
       		Movies.deleteMovie(title);
       		break;
       case 5:
       		Movies.countMovies();
       		break;
      	}

   		} while(option!=6);

   		cout << "Goodbye! " <<endl;


	return 0;


}
