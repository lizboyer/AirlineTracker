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
