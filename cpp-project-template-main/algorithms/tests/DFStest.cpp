#include "catch2/catch.hpp"

#include "../include/algorithms.h"
using namespace std;

TEST_CASE("Testing DFS") {

	//Tests that all points have not yet been visited if DFS is not called.
	//SECTION("Testing Initial Conditions")
	//	for (size_t i = 0; i < visited.size(); ++i) {
	//		REQUIRE(visited[i] == false);
	//	}


	//Tests that once DFS is called on the graph, all points will eventually be visited.
	SECTION("Testing Full Iteration")	
		DFS(AirTravel("./test_nodes","./test_edges"));
		for (size_t v = 0; v < visited.size(); ++i) {
			REQUIRE(visited[v] == true);
		}
} 