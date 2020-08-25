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
MovieNode *deleteMovieNode(MovieNode *node, string title)
{
	bool found = false;
	MovieNode *prePtr = nullptr;
	MovieNode *current = node;
	if(current==nullptr)
	{
		cout << "Movie not found. " << endl;
		return NULL;
	}
	while(current != nullptr)
	{
		if(current->title == title)
		{
			found=true;
			break;
		}
		else
		{
			prePtr = current;
			if(title > current->title)
			{
				current=current->rightChild;
			}
			else
			{
				current=current->leftChild;
			}
		}
		}
		if(!found)
		{
			cout << "Movie not found. " <<endl;
			return NULL;

		}
		//Case 1: single child
		if((current->leftChild == nullptr && current->rightChild != nullptr) || (current->leftChild != nullptr && current->rightChild== nullptr))
		{
			if(current->leftChild == nullptr && current->rightChild != nullptr)
			{
				if(prePtr->leftChild == current)
				{
					prePtr->leftChild=current->rightChild;
					delete current;
					current=nullptr;

				}
				else
				{
					prePtr->rightChild=current->rightChild;
					delete current;
					current = nullptr;
				}
			}
			else // left leaf tree
			{
				if(prePtr->leftChild==current)
				{
					prePtr->leftChild=current->leftChild;
					delete current;
					current = nullptr;
				}
				else
				{
					prePtr->rightChild=current->leftChild;
					delete current;
					current=nullptr;
				}
			}
			return current;
		}
		if(current->leftChild == nullptr && current->rightChild==nullptr)
		{
			if(prePtr->leftChild=current)
			{
				prePtr->leftChild=nullptr;
			}
			else
			{
				prePtr->rightChild=nullptr;
			}
			delete current;
			return current;
		}
		//case 3 two children
		if(current->leftChild != nullptr && current->rightChild!=nullptr)
		{
			MovieNode *temp = current->rightChild;
			if((current->leftChild==nullptr)&&(current->rightChild==nullptr))
			{
				current=temp;
				delete temp;
				current->rightChild=nullptr;
			}
			else
			{
				if((current->rightChild)->leftChild!= nullptr)
				{
					MovieNode *leftCur;
					MovieNode *leftPre;
					leftPre=current->rightChild;
					leftCur=(current->rightChild)->leftChild;
					while(leftCur->leftChild!=nullptr)
					{
						leftPre=leftCur;
						leftCur=leftCur->leftChild;
					}
					current->title = leftCur->title;
					delete leftCur;
					leftPre->leftChild ==nullptr;
				}
				else
				{
					MovieNode *temp = current->rightChild;
					current->title = temp->title;
					current->rightChild=temp->rightChild;
					delete temp;
				}
			}
			return current;
		}
}
void MovieTree::deleteMovie(std::string title)
{
    deleteMovieNode(root, title);
}
/*MovieNode *minimumNode(MovieNode *node)
{
	MovieNode *current = node;
	while(current->leftChild != NULL)
	{
		current=current->leftChild;
	}
	return current; 
}
MovieNode* deleteMovieHelper(MovieNode *node, std::string title)
{
	if(root == NULL) return root;

	else if(title < node->title)
	{
		node->leftChild = deleteMovieHelper(node->leftChild, title);
	}
	else if(title > node->title)
	{
		node->rightChild = deleteMovieHelper(node->rightChild, title);
	}
	else
	{
		//Case 1: no children
		if(node->leftChild == NULL && node->rightChild == NULL)
		{
			delete node;
			node = NULL;
		}
		//case 2: one child
		else if(node->leftChild == NULL)
		{
			MovieNode temp = node;
			node = node->rightChild;
			delete temp; 
		}
		else if(node->rightChild == NULL)
		{
			MovieNode temp = node;
			node = node->leftChild;
			delete node; 
		}
		else
		{
			MovieNode * = findMin(node->rightChild);
			node->title = temp->title;
			node->rightChild= deleteMovieHelper(node->rightChild, temp->title);
		}
	}
	return node;
}
*/
/*MovieNode* getMinValueHelper(MovieNode *node)
{
	if(node == NULL)
	{
		return nullptr;
	}
	if(node->leftChild != NULL )
	{
		return getMinValueHelper(node->leftChild);
	}
	return node->title; 
}

*/
/*MovieNode *minimumNode(MovieNode *node)
{
	MovieNode *current = node;
	while(current->leftChild != NULL)
	{
		current=current->leftChild;
	}
	return current; 
}
MovieNode* deleteMovieHelper(MovieNode* node, std::string title)
{
	if(root == NULL) //base case
	{
		cout << "Movie not found. " << endl; 
		return root;
	}
	//if the title is smaller than the root: it is in the left subtree
	if(title < root->title)
	{
		root->leftChild=deleteMovieHelper(root->leftChild,title);

	}
	//if the title is greater than the root: it is in the right subtree 
	else if(title > root->title)
	{
		root->rightChild = deleteMovieHelper(root->rightChild,title);

	}
	//if key is the same, then we found the title and it needs to be deleted
	else
	{
		//node with only one child or no children 
		if(root->leftChild == NULL)
		{
			MovieNode *temp = root->rightChild;
			free(root);
			return temp;	
		}
		else if(root->rightChild == NULL)
		{
			MovieNode *temp = root->leftChild;
			free(root);
			return temp; 
		}
		MovieNode *temp = minimumNode(root->rightChild);
		root->title = temp->title; //copy successor
		root->rightChild = deleteMovieHelper(root->rightChild, temp->title);
	}
	return root; 
}
void MovieTree::deleteMovie(std::string title)
{
	deleteMovieHelper(root, title);

}
*/
int countMoviesHelper(MovieNode *node)
{
	if(node == NULL)
	{
		return 0;
	}
	else
	{
		return(countMoviesHelper(node->leftChild)+1+countMoviesHelper(node->rightChild));
	}
	
}
    // Descr: Count & print the # of nodes in the tree
    //    See 'Count movies in the tree'. (TODO)
void MovieTree::countMovies()
{	
	int count = 0;
    if(root == NULL){
		
		count = 0;

	}
	else{
		count = countMoviesHelper(root);
		
	}
	cout << "Count = " << count << endl;
	
}
