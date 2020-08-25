#ifndef GRAPH_HPP
#define GRAPH_HPP

#include<vector>

const int HASHMAP_SIZE = 71;

struct vertex;

/*This is the struct for the adjacent vertices for each
 vertex in the graph. */
struct adjVertex
{
	vertex *v;
};

/*this is the struct for each vertex in the graph.  */
struct vertex
{
    std::string id;
    std::string name;
	int networkID;
    std::vector<adjVertex> friends;
    bool visited;
};

struct hobbylist
{
	std::string hobby;
	std::vector<vertex*> list;
};

class Graph
{
    public:
        Graph();
        ~Graph();
        void addEdge(std::string v1, std::string v2 );
        void addVertex(std::string id);
        void displayEdges();
		void assignSocialCircles();
		int addUserToHobby(std::string hobby, std::string id);
        // loop through the hash table. if there's a hobbylist
        // in the table, print it out along with the names of the people
        // who have that hobby (see document for example format)
		void displayHobbies();

        std::vector<vertex> vertices;

    private:
        vertex * findVertex(std::string name);
		hobbylist * hobbies[HASHMAP_SIZE];
        //call BFTraversalLabel from within assignSocialCircles to label the networkID.
        //This method should implement a breadth first traversal from the startingPerson
        //and assign all nodes encountered the networkID value
        void BFTraversalLabel(std::string startingCity, int distID);
};

#endif // GRAPH_HPP
