#include <string>
#include <iostream>
#include "MovieTree.hpp"
using namespace std; 

MovieTree::MovieTree()
{
	root = NULL;
}
void deleteAll(MovieNode *node){
	if(node==NULL){
		return;
	}
	else
	{
		deleteAll(node->leftChild);
		deleteAll(node->rightChild);
		delete node;
	}

}
MovieTree::~MovieTree()
{
	deleteAll(root);

}
MovieNode* searchHelper(MovieNode *node, std::string title)
{

	
	while(node != NULL)
	{

		if(node->title.compare(title)==0)
		{
		return node;
		}

		if(node->title.compare(title) > 0)
		{
			if(node->leftChild != NULL)
			{
			node = node->leftChild;
			}
			else
			{
			return NULL;
			break;
			}
		}
		else
		{
			if(node->rightChild != NULL)
			{
			node = node->rightChild;
			}
			else
			{
			return NULL;
			break;
			}
			}

	}
	return 0;
}



void helpPrintMovieInventory(MovieNode *node)
{
	if(node == NULL)
	{
		return;
	}
	else
	{
		helpPrintMovieInventory(node->leftChild);
		std::cout<< "Movie: " << node->title << " " << node->quantity << std::endl;
		helpPrintMovieInventory(node->rightChild);
	}
	
}
 	// Descr: see 'print the entire inventory'
    //    in the homework manual. (TODO)
void MovieTree:: printMovieInventory(){

	if(root==NULL){
		return;

	}
	else
	{
		helpPrintMovieInventory(root);
	}
}



    // Descr: add movie to BST, at spot in tree
    //    alphabetically-sorted by title. (TODO)
    //  param rating: IMDB rating of movie
    //  param title: title of movie
    //  param releaseYear: release year of movie
    //  param quantity: # of copies available to rent
void MovieTree::addMovieNode(int ranking, std::string title, int releaseYear, int quantity)
{
	if(root == NULL)
	{
		root = new MovieNode(ranking, title, releaseYear, quantity);
	}
	else
	{
		MovieNode *temp = root;
		while(true)
		{
			if(temp->title.compare(title)>0)
			{
				if(temp->leftChild != NULL)
				{
					temp = temp->leftChild;
				}
				else
				{
					temp->leftChild = new MovieNode(ranking, title, releaseYear, quantity);
					break;
				}
			}
			else
			{
				if (temp->rightChild != NULL)
				{
					temp = temp->rightChild;
				}
				else
				{
					temp->rightChild= new MovieNode(ranking, title, releaseYear, quantity);
					break;
				}
			}
		}
	}



}


    // Descr: Search the BST for the given title and
    //    print that movie's info in the predefined 
    //    format. See 'Find a movie' in the manual. (TODO)
    //  param title: title of node to find
void MovieTree::findMovie(std::string title)
{
MovieNode *foundMovie = searchHelper(root,title);
	if (foundMovie!=NULL)
	
	{

	cout << "Movie " << "'"<< foundMovie->title <<"' Info:"<< endl;
	cout << "================================" << endl;
	cout << "Ranking : " << foundMovie->ranking << endl;
	cout << "Title   : " << foundMovie->title << endl;
	cout << "Year    : " << foundMovie->year << endl;
	cout << "Quantity: " << foundMovie->quantity << endl;
	}
	else
	{
		cout<< "Movie not found." << endl;
	}

}

    // Descr: update the inventory to indicate a movie
    //    has been rented and print predefined info.
    //    See 'Rent a movie' in the manual. (TODO)
    //  param title: title of node to rent
	


void MovieTree::rentMovie(string title)
{
    
   if(searchHelper(root,title)==NULL){
		cout<< "Movie not found." << endl;
	}

	

	else
	{
		if(searchHelper(root,title)->quantity == 0)
		{
			cout<<"Movie out of stock."<<endl;
			return;
		}
	cout<<"Movie has been rented."<<endl;
	searchHelper(root,title)->quantity--;
	findMovie(title);
	}
	
}