//Reference: https://www.geeksforgeeks.org/depth-first-search-or-dfs-for-a-graph/

#include "../include/algorithms.h"
#include <iostream>
using namespace std;

//DFS

DFS::DFS (AirTravel graph) {
	nodes = graph.graph_nodes;
	links = graph.link;
    visited.resize(nodes.size(), false);
	for (auto i : nodes) {    //iterates through vertex
		if (visited[links[i.first]] == false) {  //if the node has not been visited, call DFShelper
			DFShelper(i.first);
		}
	}
}

void DFS::DFShelper (string id) {   
	visited[links[id]] = true;  //turn visited to true
    vector<string> adjacent_ids = nodes[id].incident_edges;
	for (auto i : adjacent_ids) {    //iterate through vertex
		if (!visited[links[i]]) {  //if the node has not been visited, call DFShelper
			DFShelper(i);
		}
	}
}

//Dijkstra's