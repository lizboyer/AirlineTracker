#include "catch2/catch.hpp"

#include "../include/algorithms.h"
using namespace std;

TEST_CASE(“Testing DFS”) {

	//Tests that once DFS is called on the graph, all points will eventually be visited.	
	DFS sea = DFS(AirTravel("./test_nodes","./test_edges"));
	for (size_t v = 0; v < sea.visited.size(); ++v) {
		REQUIRE sea.visited[v] == true;
	}
}