//Reference: https://www.geeksforgeeks.org/depth-first-search-or-dfs-for-a-graph/

#include "../include/algorithms.h"
#include <iostream>
#include <cfloat>

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

vector<string> dijkstra (AirTravel graph, string startID, string destinationID) {
	// Final Path (a vector of ID)
	vector<string> path;
	double dist = 0;

	// double is the distance and string is the airport ID
	vector<pair<double, string>> min_heap;
	// iterate through everything and set 0 for the starting point and infinity for everything else
    for (pair<string, AirTravel::Node> element : graph.graph_nodes) {
		if (element.first == startID) {
			min_heap.push_back(pair<double, string>(0, element.first));
		} else {
			min_heap.push_back(pair<double, string>(DBL_MAX, element.first));
		}
    }

	make_heap(min_heap.begin(), min_heap.end(), std::greater<std::pair<double, string>>{});

	// total distance tracker
	// previous node tracker
	unordered_map<string, double> nodeDist; 
	unordered_map<string, string> prevNode; 
    for (pair<string, AirTravel::Node> element : graph.graph_nodes) {
		if (element.first == startID) nodeDist.insert(pair<string, double>(element.first, 0)); //sets distance to 0 for source ID
		else nodeDist.insert(pair<string, double>(element.first, DBL_MAX)); //sets distance to largest double value for all other airports
		prevNode.insert(pair<string, string>(element.first, ""));
	}

	while (!min_heap.empty()){
        pair<double, string> elem = min_heap[0];

		//removes element of smallest distance from min_heap
		pop_heap(min_heap.begin(), min_heap.end(), std::greater<std::pair<double, string>>{});
		min_heap.pop_back();

		string idx = elem.second;

		for (int i = 0; i < graph.graph_nodes[idx].incident_edges.size(); i++) {
			bool inHeap = false;
			string destIdx = graph.graph_nodes[idx].incident_edges[i];
			double destDist = graph.CalcDist(idx, destIdx);

			//checks if adjacent airport is in heap
			for (int j = 0; j < min_heap.size(); j++) {
				if (min_heap[j].second == destIdx) {
					inHeap = true;
					break;
				}
			}

			//if so, node distance is updated to true value and previous node is added
			if (inHeap && nodeDist[idx] != DBL_MAX && destDist + nodeDist[idx] < nodeDist[destIdx]) {
				nodeDist[destIdx] = destDist + nodeDist[idx];
                prevNode[destIdx] = idx;

				//updates values for min_heap
                for (int j = 0; j < min_heap.size(); j++){
                    if (min_heap[j].second == destIdx) {
                        min_heap[j].first = nodeDist[destIdx];
                        make_heap(min_heap.begin(), min_heap.end(), std::greater<std::pair<double, string>>{});
                    }
                }
			}
		}
		if (idx == destinationID) break;
	}
	//final distance is calculated
	dist = nodeDist[destinationID];

	//if undetermined, empty route is returned
	if (dist == DBL_MAX) return path;

	//if determined, route is found by going through the direct previous nodes of each airport until source ID is reached
	string i = destinationID;
	path.push_back(i);
	while (prevNode[i] != "") {
		path.push_back(prevNode[i]);
		i = prevNode[i];
	}
	reverse(path.begin(), path.end());
	return path;
}

/////////// Kosaraju ///////////////
int Kosaraju(AirTravel graph) {
	unordered_map<string, AirTravel::Node> nodes = graph.graph_nodes;
	unordered_map<string, AirTravel::Node> nodes_r;
	stack<string> stk;
	unordered_map<string, bool> visited;
	int num_components = 0;

	//set visited to false for all nodes,
	//also initialize the graph_nodes map that will become the reversed graph
	for(auto it : nodes) {
		visited[it.first] = false;
		nodes_r[it.first].incident_edges = {};
	}	

	//this begins the first dfs for topological sort
	//after this loop, the stack should be built
	for (auto it :nodes) {
		if (visited[it.first])
			continue;
		K_helper0(visited, nodes, stk, it.first);	
	}

	//time to reverse the graph
	vector<string> edges;

	for (auto it : nodes) {
		edges = it.second.incident_edges;
		for (int i = 0; i < int(edges.size()); i++)
			nodes_r[edges[i]].incident_edges.push_back(it.first);
	}

	//one more dfs, this time on the resversed graph,
	//counting each time we go to a new connected component
	for(auto it : nodes_r) {
		visited[it.first] = false;
	}

	string cur_node;
	while (!stk.empty()){
		num_components++;
		cur_node = stk.top();
		if (visited[cur_node]){
			stk.pop();
			continue;
		}
		K_helper1(visited, nodes_r, stk, cur_node);	
	}

	return num_components;
}

void K_helper0(unordered_map<string, bool> & visited,
	unordered_map<string, AirTravel::Node> & graph_nodes, 
	stack<string> & stk, string cur_node){
	
	vector<string> & edges = graph_nodes[cur_node].incident_edges;

	for(int i = 0; i < int(edges.size()); i++){
		if (!visited[edges[i]])
			K_helper0(visited, graph_nodes, stk, edges[i]);
	}
	stk.push(cur_node);
	visited[cur_node] = true;
}

void K_helper1(unordered_map<string, bool> & visited,
	unordered_map<string, AirTravel::Node> & graph_nodes, 
	stack<string> & stk, string cur_node){
	
	vector<string> & edges = graph_nodes[cur_node].incident_edges;

	for(int i = 0; i < int(edges.size()); i++){
		if (!visited[edges[i]])
			K_helper1(visited, graph_nodes, stk, edges[i]);
	}
	visited[cur_node] = true;
}
/////////// Kosaraju ////////////