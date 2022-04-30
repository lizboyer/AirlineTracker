//Reference: https://www.geeksforgeeks.org/depth-first-search-or-dfs-for-a-graph/

#include "../include/algorithms.h"
#include <iostream>
using namespace std;

//DFS

DFS::DFS (AirTravel graph) {
	nodes = graph.graph_nodes;
	links = graph.link;
    visited.resize(nodes.size(), false);
	for (size_t i = 0; i < visited.size(); ++i) {    //iterates through vertex
		if (visited[i] == false) {  //if the node has not been visited, call DFShelper
			DFShelper(i);
		}
	}
}

void DFS::DFShelper (size_t v) {   
	visited[v] = true;  //turn visited to true
    vector<string> adjacent_ids = nodes[links[v]]->incident_edges;
	for (size_t i = 0; i < adjacent_ids.size(); ++i) {    //iterate through vertex
		auto it = nodes.find(adjacent_ids[i]);
		size_t j = links.find()->first;
		if (!visited[j]) {  //if the node has not been visited, call DFShelper
			DFShelper(j);
		}
	}
}

//Dijkstra's