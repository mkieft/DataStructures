#include <iostream>
#include "BST.hpp"
using namespace std;

/**
Create a node with key as data
**/

Node* BST:: createNode(int data)
{
    Node* newNode = new Node;
    newNode->key = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

BST::BST()
{
    root = NULL;
}

/**
parameterized constructor. It will create the root and put the data in the root.
**/

BST::BST(int data)
{
    root = createNode(data);
}

/**
Destructor
**/

BST::~BST(){
     destroyNode(root);
}

 /**
 This function will destroy the subtree rooted at currNode.
 Think about in what order should you destroy. POSTORDER. or right-left-root
 **/

void BST:: destroyNode(Node *currNode)
{
     if(currNode!=NULL)
     {
         destroyNode(currNode->left);
         destroyNode(currNode->right);
         delete currNode;
         currNode = NULL;
     }
 }

//--------------------------------------------INSERT NODE IN THE TREE--------------------------------------

/**
This function will add the data in the tree rooted at currNode.
We will call this function from addNode.
NOTE: root is a private member of BST. Hence addNode function can not diretly access it.
      So we need this helper function. Implement your code for inserting a node in this function.
**/

Node* BST:: addNodeHelper(Node* currNode, int data)
{
    if(currNode == NULL)
    {
        return createNode(data);
    }
    if(currNode->key > data)
    {
        currNode->left = addNodeHelper(currNode->left, data);
    }
    else if(currNode->key < data)
    {
        currNode->right = addNodeHelper(currNode->right, data);
    }

    return currNode;
}

 /**
 This function will insert the data in the tree. As this function can not access the rooted
 it will call the addNodeHelper function.
 **/

void BST:: addNode( int data)
{
    if(root == NULL)
        root = createNode(data);
    else
        addNodeHelper(root,data);
}

//--------------------------------------------GET NUMBER OF NODES-------------------------------------------

int BST::getSizeHelper(Node* currNode)
{
    if(currNode == NULL)
        return 0;
    return getSizeHelper(currNode->left)+ getSizeHelper(currNode->right)+1;
}

int BST::getSize()
{
    return getSizeHelper(root);
}
//-------------------------------------------GET MINIMUM VALUE FROM THE TREE---------------------------------

/**
Find the minimum in the subtree rooted ar currNode
Go to the left most node of this subtree.
**/

int BST::getMinValueHelper(Node* root)
{
    if(root->left == NULL)
        return root->key;
    return getMinValueHelper(root->left);
}
//returns the maximum value from the left subtree to update the max value 
int BST::getMaxValueHelper(Node* curNode)
{
    if(curNode->right == NULL)
    {
        return curNode->key;
    }
    return getMaxValueHelper(curNode->right);
   
}

int BST::getMinValue()
{
    if(root == NULL)
    {
        cout<<" Tree empty"<<endl;
        return -1;
    }
    return getMinValueHelper(root);
}

//--------------------------------------------GET MAXIMUM DEPTH OF THE TREE----------------------------------

int BST::getMaxDepthHelper(Node* currNode)
{
    if( currNode == NULL)
        return 0;

    if(currNode->left == NULL && currNode->right == NULL)
        return 0;

    int left_depth = getMaxDepthHelper(currNode->left);
    int right_depth = getMaxDepthHelper(currNode->right);

    if(left_depth > right_depth)
        return left_depth+1;
    return right_depth+1;
}

int BST::getMaxDepth()
{
    return getMaxDepthHelper(root);
}

void BST:: printTreeHelper(Node* curNode)
{
    if(curNode)
    {
           printTreeHelper( curNode->left);
           cout << " "<< curNode->key;
           printTreeHelper( curNode->right);
    }
}
void BST:: printTree(){
    printTreeHelper(root);
    cout<<endl;
}



//every recursive call returns a pointer to itself
//private in .hpp file (deleteNode is public)
Node* BST:: deleteNodeHelper(Node* curNode, int key)
{
    if( curNode == nullptr)     //node not found
    {
        return nullptr;
    }
    if(curNode->key!= key)
    {
        //cout << " [visit] " << curNode->key <<endl;

        if(key < curNode->key) //if the node were looking for is less than the current nodes key -> go left
        {
            curNode->left = deleteNodeHelper(curNode->left , key);
        }
        else
        {
           /* cout << " [found] " << curNode->key;            //helps show what node it is visiting
            cout << "[left] " << curNode->left;
            cout << " [right] " << curNode->right << endl;
            */
            curNode->right = deleteNodeHelper(curNode->right, key);
        }
    }
    else
    {
        // found the key! delete it
        if(curNode->left == nullptr && curNode->right == nullptr)   //case 1: no children; just delete
        {
            delete curNode;
            curNode = nullptr; // return for bottom statement
        }
        else if (curNode->right == nullptr) //case 2A: one child on left
        {
            Node *temp = curNode->left; //save pointer to child, delete current node, update child w pointer
            delete curNode;
            curNode = temp; 
        }
        else if(curNode->left == nullptr) //case 2B: one child on right
        {
            Node *temp = curNode->right;
            delete curNode;
            curNode = temp;

        }
        else                            //case 3: two children (replace with max from left, or min on the right)
        {                               //lets take max value of left
            int tempKey = getMaxValueHelper(curNode->left); //will return the maximum key in that substree
            curNode->key = tempKey; 
            curNode->left = deleteNodeHelper(curNode->left, tempKey); //deleting tempKey (max value found) from left subtree
            //dont need to change right pointer, since were only copying the key into the spot

        }
    }


    return curNode;
}
/**
Delete the node with key.
**/
 void BST:: deleteNode(int key)
 {

     cout<<"Deleting "<<key<<endl;
     root = deleteNodeHelper(root, key); //upadate root to whatever deleteNodeHelper returns
 }
