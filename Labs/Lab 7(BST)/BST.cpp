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
      //left subtree
      currNode->left = addNodeHelper(currNode->left, data);
    }
    else if(currNode->key < data)
    {
      //right subtree
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

  return getSizeHelper(currNode->left)+getSizeHelper(currNode->right)+1;

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
  if(!root->left)
    return root->key;
  return getMinValueHelper(root->left);
}

int BST::getMinValue()
{
  if(root == NULL)
  {
    cout<<"Tree is empty."<<endl;
    return -1;
  }
  return getMinValueHelper(root);
}

//--------------------------------------------GET MAXIMUM DEPTH OF THE TREE----------------------------------

int BST::getMaxDepthHelper(Node* currNode)
{
  if(currNode == NULL){
    return 0;
  }

  else{

  int left_depth = getMaxDepthHelper(currNode->left);
  int righ_depth = getMaxDepthHelper(currNode->right);

    if(left_depth > righ_depth)
    {
      return(left_depth+1);
    }
    else{
      return(righ_depth+1);
    }
  }
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
