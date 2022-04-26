#include "catch2/catch.hpp"

#include "../include/graph.h"

using std::unordered_map;
using std::vector;
using std::string;


TEST_CASE("node_formatter returns propper vectors") {
    AirTravel graph = AirTravel();

    vector<vector<string>> nodes = graph.node_format("./tests/test_nodes.dat");

    REQUIRE(!nodes.empty());
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