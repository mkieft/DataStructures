#include "graph.hpp"
#include<iostream>
#include<set>
#include<list>
#include<algorithm>
#include <limits> //for max integer
using namespace std;

//best is with a priority queue heap O(logn) for extract min 

const int INF = numeric_limits<int>::max(); 

Graph::Graph(int nodeCount) {
   n = nodeCount;
   adjList = new list<node>[n];
}

void Graph::showList(int src, list<node> lt) {
   list<node> :: iterator i;
   node tempNode;

   for(i = lt.begin(); i != lt.end(); i++) {
      tempNode = *i;
      cout << "(" << src << ")---("<<tempNode.dest << "|"<<tempNode.cost<<") ";
   }
   cout << endl;
}



void Graph::addEdge(int source, int dest, int cost)
{
   //undirected graph -- from source to destination and from destination to source
   node edge1;
   edge1.dest = dest;
   edge1.cost = cost;
   adjList[source].push_back(edge1); 

   node edge2;
   edge2.dest = source;
   edge2.cost = cost;
   adjList[source].push_back(edge2); 
}

void Graph::displayEdges()
{
   for(int i = 0; i<n; i++)
   {
      list<node> tempList = adjList[i];
      showList(i, tempList);
   }
}

int Graph:: min_element(int dist[], bool visited[])
{
   // Initialize min value
   int min = INF;
   int min_index = -1;

   for(int v = 0; v < n; v++)
   {
      if(!visited[v] && dist[v] <= min)
      {
         min = dist[v];
         min_index = v;
      }
   }

   return min_index;
}

void Graph::dijkstra( int *dist, int *prev, int start)
{
   //init
   bool visited[n];
   for(int u =0; u < n; u++)
   {
      dist[u] = INF;
      prev[u] = -1;
      visited[u] = false; 

   }
   dist[start] = 0; 

   //loop over all vertices in queue for queue (whie queue not empty keep pulling vertices)
   //array -> loop over arary

   for(int count = 0; count < n - 1; count++)   //dont have to visit last one -> no weights after last vertex to add
   {
      int u = min_element(dist, visited);
      visited[u] = true;

      for(auto it = adjList[u].begin(); it != adjList[u].end(); it++)
      {
         //relaxation step
         node v = *it; // v is the neighbor
         if( (dist[u] + v.cost) < dist[v.dest]) //if its less than current best element, theres better path and should update tracking
         {
            dist[v.dest] = dist[u]+ v.cost;  //came through u, save that 
            prev[v.dest] = u; 

         }

      }

   }
}
