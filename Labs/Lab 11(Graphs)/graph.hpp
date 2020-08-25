#ifndef GRAPH_HPP
#define GRAPH_HPP
#include<list>
// This class represents a directed graph using
// adjacency list representation
class Graph
{
    int V;    // No. of vertices

    // Pointer to an array containing adjacency
    // lists

    std::list<int> *adj;    //list of integers (doesn't have to be, can be a list of objects etc.)



public:
    Graph(int V);  // Constructor (takes # of vertices to put in list)

    // function to add an edge to graph (could have list of lists to add vertices at the end)
    void addEdge(int v, int w);

    void print(); //prints adjacency list

    // prints BFS traversal from a given source s
    void BFS_visit(int s, bool visited[]);
    void DFS_visit(int s, bool visited[]); 
    void BFS();
    void DFS();
};
#endif
