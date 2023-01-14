#pragma once


#include <vector>
#include <queue>
#include <utility>
#include <sstream>
#include <map>
#include <string>
#include <ostream>
#include <algorithm>
#include <stack>

using namespace std;

#include "../../parsing/include/graph.h"

using std::stack;

class DFS {

    public:
    /**
    * Constructor for DFS. Iterates through each node and
    * marks them as visited. Calls DFSHelper for all
    * adjacent nodes to do the same.
    */
    DFS (AirTravel graph);


    /**
    * Called by DFS when an adjacent node has not been visited.
    * Sets "visited" to true on that node, and continues
    * iterating through the rest of the graph until it runs
    * into another unvisited node, whereupon it calls itself.
    * @param v the name of the PNG file to sketchify
    */
    void DFShelper (string id);

    vector<bool> visited { false };
    
    private:
    //reference structures for graph maps
    unordered_map<string, AirTravel::Node> nodes;
    unordered_map<string, size_t> links;
};
/**
* Dijkstra's algorithm to find the path between nodes
* as determined by smallest sum of distances in path,
* i.e. if there are multiple paths, the one with shortest
* distance will be outputted
**/
vector<string> dijkstra (AirTravel graph, string startID, string destinationID);

// Kosaraju's algorithm for strongly connected component
// this algorithm uses topological sort, including a dfs, to sort 
// the nodes by finishing time. It then reverses the direction of 
// all edges in the graph, and performs another dfs of all the nodes, 
// counting the strongly connected components. It then returns the
// number of strongly connected components of the graph.
// @AirTravel graph is an AirTravel object, which is the graph we are working on

//note, Kosaraju's algorithm may be particularly slow for our implimentation of the graph.
int Kosaraju(AirTravel graph);

void K_helper0(unordered_map<string, bool> & visited,
	unordered_map<string, AirTravel::Node> & graph_nodes, 
	stack<string> & stk, string cur_node);

void K_helper1(unordered_map<string, bool> & visited,
	unordered_map<string, AirTravel::Node> & graph_nodes, 
	stack<string> & stk, string cur_node);

