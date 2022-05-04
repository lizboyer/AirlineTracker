#pragma once


#include <vector>
#include <queue>
#include <utility>
#include <sstream>
#include <map>
#include <string>
#include <ostream>
#include <algorithm>

#include "../../parsing/include/graph.h"

class DFS {

    public:
    /**
    * Called by main function. Iterates through
    * the graph until it hits a node that has not
    * been visited. It then calls DFShelper.
    */
    DFS (AirTravel graph);


    /**
    * Called by DFS when a node has not been visited.
    * Sets "visited" to true on that node, and continues
    * iterating through the rest of the graph until it runs
    * into another unvisited node, whereupon it calls itself.
    * @param v the name of the PNG file to sketchify
    */
    void DFShelper (string id);

    vector<bool> visited { false };
    
    private:
    unordered_map<string, AirTravel::Node> nodes;
    unordered_map<string, size_t> links;
};

vector<string> dijkstra (AirTravel graph, string startID, string destinationID);

// Kosaraju's algorithm for strongly connected component
// this algorithm uses topological sort, including a dfs, to sort 
// the nodes by finishing time. It then reverses the dirrection of 
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

