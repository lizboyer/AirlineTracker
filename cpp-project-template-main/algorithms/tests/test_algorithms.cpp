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

TEST_CASE("Testing Dijkstra's") {
	AirTravel graph = AirTravel("./algorithms/tests/test_nodes.dat","./algorithms/tests/test_edges.dat");

	//Tests for direct edge between two nodes
	vector<string> path_direct = dijkstra(graph, "AAA", "CCC");
	vector<string> ans_direct {"AAA", "CCC"};
	REQUIRE(path_direct.size() == ans_direct.size());
	for (size_t i = 0; i < path_direct.size(); i++) REQUIRE(path_direct[i] == ans_direct[i]);

	//Tests for no direct edge but indirect connection between two nodes
	vector<string> path_indirect = dijkstra(graph, "BBB", "DDD");
	vector<string> ans_indirect {"BBB", "AAA", "DDD"};
	REQUIRE(path_indirect.size() == ans_indirect.size());
	for (size_t i = 0; i < path_indirect.size(); i++) REQUIRE(path_indirect[i] == ans_indirect[i]);

	//Tests for multiple paths between two nodes - should determine based on lowest distance
	vector<string> path_multiple = dijkstra(graph, "CCC", "EEE");
	vector<string> ans_multiple {"CCC", "EEE"};
	REQUIRE(path_multiple.size() == ans_multiple.size());
	for (size_t i = 0; i < path_multiple.size(); i++) REQUIRE(path_multiple[i] == ans_multiple[i]);
}

TEST_CASE("Testing Kosaraju's graph1") {
	string node_file = "./data/testing_k/k_test1_nodes.dat";
    string edge_file = "./data/testing_k/k_test1_edges.dat";

	AirTravel graph(node_file, edge_file);

	REQUIRE(graph.graph_nodes.size() == 5);
	//REQUIRE(graph.graph_nodes["CCC"].adja)

	int comp = Kosaraju(graph);

	REQUIRE(comp == 3);
}

TEST_CASE("Testing Kosaraju's graph2") {
	string node_file = "./data/testing_k/k_test2_nodes.dat";
    string edge_file = "./data/testing_k/k_test2_edges.dat";

	AirTravel graph(node_file, edge_file);

	REQUIRE(graph.graph_nodes.size() == 6);
	//REQUIRE(graph.graph_nodes["CCC"].adja)

	int comp = Kosaraju(graph);

	REQUIRE(comp == 2);
}

TEST_CASE("Testing Kosaraju's graph3, disconnected graph") {
	string node_file = "./data/testing_k/k_test3_nodes.dat";
    string edge_file = "./data/testing_k/k_test3_edges.dat";

	AirTravel graph(node_file, edge_file);

	REQUIRE(graph.graph_nodes.size() == 4);
	//REQUIRE(graph.graph_nodes["CCC"].adja)

	int comp = Kosaraju(graph);

	REQUIRE(comp == 3);
}
