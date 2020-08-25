#include<iostream>
#include<climits>
#include<list>
#include "graph.hpp"
using namespace std;

Graph::Graph(int V)	//constructor
{	
	//"this" keyword which refers to the object from within the object
	//"this" points to the current object 

    this->V = V; //instance variable V and V passed into the constructor 
    adj = new list<int>[V]; //linked list implementation for c++ 

}
//each spot in adj list is neighbors of a single vertex
//add edge: 
void Graph::addEdge(int v, int w)
{
	//directed 
	adj[v].push_back(w); //adds new neighbor, spot v adds w to v's list 

	//for undirected have to add an edge from w to v too
	//adj[w].push_back(v); 
}

void Graph::print()
{
	for(int i =0; i < V; i++)
	{
		cout << "[" << i << "] --> ";		

		//iterator to give next object one at a time (is simply an object that gives the next thing in the list) 
		list<int>::iterator itr; 
		for(itr = adj[i].begin(); itr != adj[i].end(); ++itr)	//++itr is a funciton call which retrieves next item in the list
		{
			int s = *itr; //dereference object iterator 
			cout << s << ", ";
		}
		cout << endl; 
	}


}

//explores all of nodes reach from specific node


//looks at neighbors add to queue, visit neighbors in order you see them 

//1.) start at specific node s
//2.) while still nodes havent visited, add to queue-> mark as added to queue
//3.) pop off the queue look at its neighbors and add if havent seen yet
//in order to reach nodes not connected, have to do another BFS visit 

void Graph::BFS_visit(int s, bool visited[])
{
	list<int> queue; 
	visited[s] = true; 
	queue.push_back(s); 

	while(!queue.empty())
	{
		s = queue.front(); //peak 
		cout << s << " ";
		queue.pop_front(); 


		//second syntax for iterator
		//look at neighbors of s in adj list 
		//creates new iterator "auto" matches type of the list 
		//"loop over all of the things in adj list at spot s and save in variable v"
		for(auto v : adj[s])
		{
			if(!visited[v])
			{
				queue.push_back(v); 
				visited[v] = true; 
			}
		}

	}


}

//explore entire graph 

void Graph::BFS()
{
	bool visited[V]; 
	for(int i =0; i < V; i++)
	{
		visited[i] = false;
	}
	//call BFS visit one time for each component if havent visited yet 
	for(int s = 0; s < V; s++)
	{
		if(!visited[s])
		{
			BFS_visit(s, visited); 
		}
	}

}

void Graph::DFS_visit(int s, bool visited[])
{

}

//almost the same as BFS but uses stack instead of a queue
//explores down, then comes back up 
void Graph::DFS()
{

}
