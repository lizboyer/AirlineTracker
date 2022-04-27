#include "catch2/catch.hpp"

#include "../include/graph.h"

using std::unordered_map;
using std::vector;
using std::string;


TEST_CASE("node_formatter test small_simple") {
    AirTravel graph = AirTravel();

    vector<vector<string>> nodes = graph.node_formatter("./parsing/tests/test_nodes_small_simple.dat");

    REQUIRE(!nodes.empty());
    REQUIRE(nodes.size() == 5);

    bool pass = true;

    for (int i = 0; i < nodes.size(); i++) {
        if (nodes[i].size() != 4)
            pass = false;
            break;
    }
    REQUIRE(pass);
}

TEST_CASE("edge_formatter test small_simple") {
    AirTravel graph = AirTravel();

    vector<vector<string>> edges = graph.edge_formatter("./parsing/tests/test_edges_small_simple.dat");

    REQUIRE(!edges.empty());
    REQUIRE(edges.size() == 4);

    bool pass = true;

    for (int i = 0; i < edges.size(); i++) {
        if (edges[i].size() != 2)
            pass = false;
            break;
    }
    REQUIRE(pass);
}


TEST_CASE("correct parsing") {
    AirTravel graph = AirTravel();

    int count = 0;
    for(auto it : graph.graph_nodes) {
        if (it.first == "???")
            count++;
    }
    REQUIRE(count==0);

}