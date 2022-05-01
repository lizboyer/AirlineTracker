#include "catch2/catch.hpp"
#include <iostream>

#include "../include/algorithms.h"
#include "../../parsing/include/graph.h"
using namespace std;

TEST_CASE("Testing DFS") {

	//Tests that all points have not yet been visited if DFS is not called.
	//SECTION("Testing Initial Conditions")
	//	for (size_t i = 0; i < visited.size(); ++i) {
	//		REQUIRE(visited[i] == false);
	//	}


	//Tests that once DFS is called on the graph, all points will eventually be visited.
	AirTravel graph = AirTravel("./algorithms/tests/test_nodes.dat","./algorithms/tests/test_edges.dat");
	DFS dfs = DFS(graph);
	REQUIRE(dfs.visited.size() == graph.graph_nodes.size());
	for (auto v : dfs.visited) {
		REQUIRE(v == true);
	}
} 
