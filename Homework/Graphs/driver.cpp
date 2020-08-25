/*
Maura Kieft
Boese
Homework 9
*/

#include <iostream>
#include <fstream>
#include <climits>
#include "graph.hpp" 

using namespace std;

void readFileIn(Graph & g, char* fileName);

 int main(int argc, char*argv[])
 {
     // Create a graph
     Graph graph;

     // Read file into graph
     readFileIn(graph, argv[1]);

    // Find districts
    graph.assignDistricts();

    graph.displayEdges();
     return 0;
 }

 void readFileIn(Graph & graph, char* fileName)
 {
     vector <string>cities;
     ifstream infile;
     //cout << fileName << endl;
     infile.open(fileName);
     if (!infile)   //file not found
     {
         cout << "Could not open file\n";
         return;
     }

     string city;   //store city name
     string line;
     getline(infile,line);
     std::stringstream ss(line);
   

     // Read a list of cities from the first line
     while (getline(ss,city,','))
     {
         if (city != "cities")
         {
             graph.addVertex(city);
             cities.push_back(city);
         }
     }

     // Now read in all the vertices
     int i = 0;
     string in;
     while (!infile.eof())
     {
         i = -1;
         getline(infile,line);
         stringstream ss(line);
 
         while (getline(ss,in,','))
         {
             if (i == -1)
                  {
                 city = in;
             }
             else
             {
                 if (in != "-1" && in != "0")
                 {
                    int dist = atoi(in.c_str());
                    cout << " ... Reading in " << city << " -- " << cities[i] << " -- " << dist << endl;
                     graph.addEdge(city, cities[i], dist);
                 }
             }
             i++;
         }
     }
 }