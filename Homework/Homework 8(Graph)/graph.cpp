#include <iostream>
#include <climits>
#include <list>
#include "graph.hpp"
using namespace std; 


	/*
class constructor
Purpose: perform all operations necessary to instantiate a class 	object
Parameters: none
*/
Graph::Graph()
{
	new vector<vertex> vertices;	
}

/*
class destructor
Purpose: free all resources that the object has aquired
Parameters: none
*/
Graph::~Graph()
{
	for (int i =0; i < vertices.size(); i++)
	{
		vertices.pop(i); 
	}

}

/*
Method Name: addEdge
Purpose: Creates an edge between two vertices (using an adjVertex
	struct)
Param: v1 - vertex at one end of edge
Param: v2 - vertex at opposite end of edge
*/
void Graph::addEdge(std::string v1, std::string v2, int distance)
{
	vertex *city1 = findVertex(v1);
	vertex *city2 = findVertex(v2);

	adjVertex adjOne;
	adjOne.distance = distance;
	adjOne.v = city2;
	city1->adj.push_back(adjOne);  

}

/*
Method Name: addVertex
Purpose: Creates a vertex
Param: name - name of the vertex (city name)
*/
void Graph::addVertex(std::string name)
{
	vertex vx;
	vx.name = name;
	vx.district = -1;
	vx.visited = false;
	vertices.push_back(vx); 

}

/*
Method Name: displayEdges
Purpose: print all edges in graph (see writeup for format)
Parameters: none
*/
void Graph::displayEdges()
{

	for(int i =0; i < vertices.size(); i++)
	{
		cout << vertices[i].district << ":" << vertices[i].name << "-->";
		for (int j = 0; j < vertices[i].adj.size(); j++)
		{
			cout << vertices[i].adj[j].v->name;
			cout<< "(" << vertices[i].adj[j].distance << "miles)";
			if(j!= vertices[i].adj.size()-1)
			{
				cout << "***";
			}
			cout << "\n" << endl;
		}
	}


}

/*
Method Name: assignDistricts
Purpose: Iterate through the vertices, perform BFT to find connected
	components, and assign to district
Parameters: none
*/
void Graph::assignDistricts()
{
	int distID =1;

	for(int i =0; i< vertices.size(); i++)
	{
		if(vertices[i].district == -1)
		{
			BFTraversalLabel(vertices[i].name, distID);
			distID++;
		}
	}


}

 /*
Method Name: findVertex
Purpose: Find and return the vertex of the specified city
Param: name - name of the city vertex to be returned
returns pointer to a vertex
*/
vertex * Graph::findVertex(std::string name)
{
	for (int i =0; i < vertices.size(); i++)
	{
		if(vertices[i].name == name)
		{
			return &vertices[i];
		}

	}
	return NULL;
}

/*
Method Name: BFTraversalLabel
Purpose: Call BFTraversalLabel from within assignDistricts to label
	the districts. This method should implement a breadth first
	traversal from the startingCity and assign all cities
	encountered the distID value
Param: name - name of starting city for breadth first traversal
*/
void Graph::BFTraversalLabel(std::string startingCity, int distID)
{
	vector<vertex*> queue;

	for(int i = 0; i < vertices.size(); i++) //mark unvisited
	{
		if(vertices[i].name ==startingCity)
		{
			vertices[i].visited = true; //current vertex marked as visited
			queue.push(&vertices[i]);
			vertices[i].district = distID;

			break; // continue with search
		}
	}
	while(queue.empty() != true)
	{
		vertex *next = queue.front(); 
		queue.pop();

		for (int i =0; i < next->adj.size(); i++)
		{
			if(next->adj[i].v->visited == false)
			{
				next->adj[i].v->visited = true;
				next->adj[i].v->district = distID;
				queue.push(next->adj[i].v);
			}
		}
	}

 



}