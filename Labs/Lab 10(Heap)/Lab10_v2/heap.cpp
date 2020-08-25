// A C++ program to demonstrate common Binary Heap Operations
#include<iostream>
#include<climits>
#include "heap.hpp"
using namespace std;

// Prototype of a utility function to swap two integers
void swap(int *x, int *y);


// Constructor: Builds a heap from a given array a[] of given size
MinHeap::MinHeap(int cap)
{

}

// Return the index of parent of the node at index i
int MinHeap::parent(int i)
{
    return -1;
}

// Return index of left child of node at index i
int MinHeap::left(int i)
{
    return -1;
}

// Return index of right child of node at index i
int MinHeap::right(int i)
{
    return -1;
}

// Return the minimum value in the heap
int MinHeap::getMin()
{
    return -1;
}

// Inserts a new key 'k'
void MinHeap::pushMinHeap(int k)
{
    // Corner case: If heap is full

    // increment the heap size

    // insert the new key at the end


    // Fix the min heap property if it is violated

    //cout<<endl<<"Index of "<<harr[i]<<" : "<<i<<endl;
    //cout<<"Parent of "<<harr[i]<<" : "<<harr[parent(i)]<<" at index : "<<parent(i)<<endl;
    // --- ENTER CODE HERE --- //

    //cout<<endl;
}

// Heapify after inserting an element to the heap
void MinHeap::ReverseHeapify(int i)
{

}

// A recursive method to heapify a subtree with the root at given index
// This method assumes that the subtrees are already heapified
void MinHeap::MinHeapify(int i)
{
    // left and right children


    // set given index as smallest


    // compare it with its left and right children and set smallest

    // swap if not less than its one of the children

    //cout<<endl<<"Index of "<<harr[i]<<" : "<<i<<endl;
    //cout<<"Parent of "<<harr[i]<<" : "<<harr[parent(i)]<<" at index : "<<parent(i)<<endl;
    //cout<<"Heapifying "<<harr[i]<<" and its subtrees"<<endl;
    //cout<<endl<<"Index of "<<harr[smallest]<<" : "<<smallest<<endl;
    // Heapify
    // ----- ENTER CODE HERE ----
}

// Method to remove minimum element (or root) from min heap
void MinHeap::popMinHeap()
{
    //CORNER CASE: HEAP EMPTY, HEAP SIZE 1

    // Store the minimum value, and remove it from heap

    // Set the last element in the heap as root

    //cout<<endl<<"Replaced root with the Last element"<<endl;

    // Decrease the heap size by 1

    //cout<<"Now the root is : "<< harr[1]<<endl;
    // Move the root to its appropriate place


    // HEAPIFY

}

void MinHeap::printMinHeap()
{
    /*for(int i=1;i<=heap_size;i++)
        cout<<i<<":"<<harr[i]<<endl;*/
}
// A utility function to swap two elements
void swap(int *x, int *y)
{
    int temp = *x;
    *x = *y;
    *y = temp;
}
