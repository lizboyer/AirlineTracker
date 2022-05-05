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
	std::cout << "Adjacent nodes of AAA: " << graph.graph_nodes["AAA"].incident_edges.size() << std::endl;
	std::cout << "Adjacent nodes of BBB: " << graph.graph_nodes["BBB"].incident_edges.size() << std::endl;
	std::cout << "Adjacent nodes of CCC: " << graph.graph_nodes["CCC"].incident_edges.size() << std::endl;
	std::cout << "Adjacent nodes of DDD: " << graph.graph_nodes["DDD"].incident_edges.size() << std::endl;
	std::cout << "Adjacent nodes of EEE: " << graph.graph_nodes["EEE"].incident_edges.size() << std::endl;
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

	std::cout << "this is test 3" << std::endl;
	AirTravel graph(node_file, edge_file);

	REQUIRE(graph.graph_nodes.size() == 4);
	//REQUIRE(graph.graph_nodes["CCC"].adja)

	int comp = Kosaraju(graph);

	REQUIRE(comp == 3);
}
