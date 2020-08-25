// A C++ program to demonstrate common Binary Heap Operations
#include<iostream>
#include<climits>
#include "heap.hpp"
using namespace std;

// Prototype of a utility function to swap two integers
void swap(int *x, int *y);


// Constructor: Builds a heap from a given array a[] of given size
MinHeap::MinHeap(int cap)   //look at hpp class MinHeap file
{
    capacity = cap; 
    heap_size = 0; //initially empty
    harr = new int[cap +1]; //real application store objects

}

// Return the index of parent of the node at index i
int MinHeap::parent(int i)
{

    return i / 2;
}

// Return index of left child of node at index i
int MinHeap::left(int i)
{
    return 2 * i;
}

// Return index of right child of node at index i
int MinHeap::right(int i)
{
    return 2* i +1;
}

// Return the minimum value in the heap
//like peak operation 
int MinHeap::getMin()
{
    if(heap_size > 0 )
    {
        return harr[1];
    }
    else
    {
        cout << "Heap empty." << endl;
        return -1;
    }
    
}

// Inserts a new key 'k'
void MinHeap::pushMinHeap(int k)
{
    

    // Fix the min heap property if it is violated

    //cout<<endl<<"Index of "<<harr[i]<<" : "<<i<<endl;
    //cout<<"Parent of "<<harr[i]<<" : "<<harr[parent(i)]<<" at index : "<<parent(i)<<endl;
    // --- ENTER CODE HERE --- //

    // Corner case: If heap is full
    if(heap_size == capacity)
    {
        cout << "Heap is full, can't push. " << endl;
        return;
    }

    // increment the heap size
    heap_size++; 
    int i = heap_size; //i is the index of new thing ,add at end of array

    // insert the new key at the end
    harr[i] = k; 

    ReverseHeapify(i); 
    //cout<<endl;
}

// Heapify after inserting an element to the heap
void MinHeap::ReverseHeapify(int i)
{
    int pi = parent(i); //index of parent
    if(pi != 0 && harr[pi] > harr[i]) //swap if parents value bigger than childs 
    {
        swap(&harr[i], &harr[pi]);
        ReverseHeapify(pi);
    }

}

// A recursive method to heapify a subtree with the root at given index
// This method assumes that the subtrees are already heapified
void MinHeap::MinHeapify(int i)
{
    // left and right children
    int li, ri;
    li = left(i);
    ri = right(i);

     // set given index as smallest
    int smallest = i;

    // compare it with its left and right children and set smallest
    if(li <= heap_size && harr[li] <= harr[smallest])
    {
        smallest = li; 
    }
    if(ri <= heap_size && harr[ri] <= harr[smallest])
    {
        smallest = ri; 
    }
      //cout<<endl<<"Index of "<<harr[i]<<" : "<<i<<endl;
    //cout<<"Parent of "<<harr[i]<<" : "<<harr[parent(i)]<<" at index : "<<parent(i)<<endl;
    //cout<<"Heapifying "<<harr[i]<<" and its subtrees"<<endl;
    //cout<<endl<<"Index of "<<harr[smallest]<<" : "<<smallest<<endl;
    // Heapify
    // ----- ENTER CODE HERE ----



    // swap if not less than its one of the children
    if(smallest != i) //otherwise min heap property satisfied and dont need swap 
    {
        swap(&harr[i], &harr[smallest]); //swap index
        MinHeapify(smallest); // recursive 
    }

  
}

// Method to remove minimum element (or root) from min heap
void MinHeap::popMinHeap()
{
    //CORNER CASE: HEAP EMPTY, HEAP SIZE 1
    if(heap_size <= 0)
    {
        cout << "heap empty." <<endl;
        return;
    }
    if(heap_size ==1)
    {
        heap_size--;
    }

    // Store the minimum value, and remove it from heap
    // Set the last element in the heap as root

    //cout<<endl<<"Replaced root with the Last element"<<endl;

    // Decrease the heap size by 1
    //cout<<"Now the root is : "<< harr[1]<<endl;
    // Move the root to its appropriate place


    // HEAPIFY
    else
    {
        //set last element in heap as rot
        harr[1] = harr[heap_size]; 
        heap_size--;
        MinHeapify(1); 
    }

    

}

void MinHeap::printMinHeap()
{
    for(int i=1;i<=heap_size;i++)
        cout<<i<<":"<<harr[i]<<endl;
}
// A utility function to swap two elements
void swap(int *x, int *y)
{
    int temp = *x;
    *x = *y;
    *y = temp;
}
