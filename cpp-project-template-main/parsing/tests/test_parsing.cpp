#include "catch2/catch.hpp"
#include <iostream>

#include "../include/graph.h"

using std::unordered_map;
using std::vector;
using std::string;
using std::cout;
using namespace std;



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

TEST_CASE("node_formatter test large") {
    AirTravel graph = AirTravel();
    cout<< "running parsing test";

    vector<vector<string>> nodes = graph.node_formatter("./data/airports_formatted.dat");

    REQUIRE(!nodes.empty());
    REQUIRE(nodes.size() == 7698);

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


TEST_CASE("Graph size > 0") {
    string node_file = "./parsing/tests/test_nodes_small_simple.dat";
    string edge_file = "./parsing/tests/test_edges_small_simple.dat";


    AirTravel graph(node_file, edge_file);

    unordered_map<string, AirTravel::Node> & nodes = graph.graph_nodes;


    REQUIRE(!nodes.empty());
    REQUIRE(nodes.size() == 5);
}


TEST_CASE("build_edges works") {
    string node_file = "./parsing/tests/test_nodes_small_simple.dat";
    string edge_file = "./parsing/tests/test_edges_small_simple.dat";
    string id = "AAA";


    AirTravel graph = AirTravel();

    vector<vector<string>> edges = graph.edge_formatter(edge_file);


    vector<string> inc = graph.build_edges("AAA", edges);

    // std::cout << "passed" << endl;
    // std::cout << inc.size();

    REQUIRE(!inc.empty());
    REQUIRE(inc.size() == 4);
}


TEST_CASE("edges get built in graph constructor") {
    string node_file = "./parsing/tests/test_nodes_small_simple.dat";
    string edge_file = "./parsing/tests/test_edges_small_simple.dat";
    string id = "AAA";


    AirTravel graph = AirTravel(node_file, edge_file);


    vector<string> inc = graph.graph_nodes[id].incident_edges;

    // std::cout << "passed" << endl;
    // std::cout << inc.size();
    
    REQUIRE(!inc.empty());
    REQUIRE(inc.size() == 4);
}

