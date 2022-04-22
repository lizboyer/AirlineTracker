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
	AirTravel graph = AirTravel("./test_nodes","./test_edges");
	DFS dfs = DFS(graph);
	int i = 0;
	for (size_t v = 0; v < dfs.visited.size(); ++v) {
		cout << i << endl;
		i++;
		REQUIRE(dfs.visited[v] == true);
	}
} 
