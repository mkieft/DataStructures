// CPP program to implement hashing with chaining
#include<iostream>
#include "hash.hpp"

using namespace std;

node* HashTable::createNode(string key, node* next)
{
    node* nw = new node;
    nw->key = key;
    nw->next = next;
    return nw;
}

HashTable::HashTable(int bsize) //constructor ,allocate an array of pointers
{
    tableSize = bsize;
    table = new node*[tableSize]; 
    for(int i=0; i< bsize; i++)
    {
        table[i] = nullptr; //when initialize nothing is in table so the pointers should be linked to null
    }
}

//function to calculate hash function
//gets index
//for homework - universal hashing
unsigned int HashTable::hashFunction(string key)
{
    unsigned int hash = 0;

    for(int i=0; i<key.length(); i++)
    {
        hash+= key[i];
    }
    return hash % tableSize; 

}

//function to search
node* HashTable::searchItem(string key)
{
    int index = hashFunction(key);
    //if found return pointer to key, if not return nullptr
    node* temp = table[index];

    while(temp!= nullptr)
    {
        if(temp->key == key)
        {
            return temp;
        }
        temp=temp->next; 
    }

    return nullptr;
}

//function to insert
//if tries to put a key already in the table - return error
bool HashTable::insertItem(string key)
{
    if(!searchItem(key))
    {
        int index = hashFunction(key);
        node* n = createNode(key, nullptr);

        n->next = table[index]; //place at the head
        table[index] = n; //anything in table there will go after n 
        return true;
    }
    else
    {   //already in the table
        return false; 
    }
    
}

// function to delete
bool HashTable::deleteItem(string key)
{
    int index = hashFunction(key);
    node* temp = table[index];
    bool found = false;
    if(temp == nullptr)
    {
        return found;
    }
    else if(temp->key == key) //found key at head
    {
        table[index]=temp->next; //update head pointer
        delete temp;
        found = true;
    }
    else //not the head
    {
        while(temp->next && !found) //check for pointer and still not found
        {
            if(temp->next->key==key) //stop before the one want to delete to reset pointer
            {
                found = true; 
                node* delptr = temp->next; //points to what we want to delete
                temp->next = temp->next->next; //bypass it
                delete delptr; 
            }
            else
            {
                temp= temp->next; //not found go to the next node 
            }
        }
    }
    return found;
}

// function to display hash table
void HashTable::printTable()
{
    for (int i = 0; i < tableSize; i++) {
        cout << i <<"|| ";
        node* temp = table[i];
        while(temp)
        {
            cout<< temp->key;
            if(temp->next!=nullptr)
            {
                cout<<"-->";
            }
            temp = temp->next;
        }
        cout<<endl;

    }
}
