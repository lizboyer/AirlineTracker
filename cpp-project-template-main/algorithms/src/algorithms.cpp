//Reference: https://www.geeksforgeeks.org/depth-first-search-or-dfs-for-a-graph/

#include "../include/algorithms.h"
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
    vector<string> adjacent_ids = nodes[links[v]].incident_edges;
	for (size_t i = 0; i < adjacent_ids.size(); ++i) {    //iterate through vertex
		if (!visited[i]) {  //if the node has not been visited, call DFShelper
			DFShelper (i);
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
			min_heap.push_back(pair<double, string>(__DBL_MAX__, element.first));
		}
    }

	make_heap(min_heap.begin(), min_heap.end(), std::greater<std::pair<double, string>>{});

	// total distance tracker
	unordered_map<string, double> nodeDist; 
    for (pair<string, AirTravel::Node> element : graph.graph_nodes) {
		nodeDist.insert(pair<string, double>(element.first, __DBL_MAX__));
	}

	// previous node tracker
    unordered_map<string, string> prevNode; 
	for (pair<string, AirTravel::Node> element : graph.graph_nodes) {
		prevNode.insert(pair<string, string>(element.first, ""));
	}

	while (!min_heap.empty()){
        pair<double, string> elem = min_heap[0];

		pop_heap(min_heap.begin(), min_heap.end(), std::greater<std::pair<double, string>>{});
		min_heap.pop_back();
		string idx = elem.second;

		for (int i = 0; i < graph.graph_nodes[idx].incident_edges.size(); i++) {
			bool inHeap = false;
			string destIdx = graph.graph_nodes[idx].incident_edges[i];
			double destDist = graph.CalcDist(idx, destIdx);

			for (int j = 0; j < min_heap.size(); j++) {
				if (min_heap[j].second == destIdx) {
					inHeap = true;
					break;
				}
			}

			if (inHeap && nodeDist[idx] != __DBL_MAX__ && destDist + nodeDist[idx] < nodeDist[destIdx]) {
				nodeDist[destIdx] = destDist + nodeDist[idx];
                prevNode[destIdx] = idx;

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

	dist = nodeDist[destinationID];
	if (dist == __DBL_MAX__) return path;
	string i = destinationID;
	path.push_back(i);
	while (prevNode[i] != "") {

		path.push_back(prevNode[i]);
		i = prevNode[i];
	}
	reverse(path.begin(), path.end());
	return path;
}