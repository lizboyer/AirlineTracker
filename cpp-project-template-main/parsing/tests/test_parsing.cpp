#include "catch2/catch.hpp"

#include "../include/graph.h"

using std::unordered_map;
using std::vector;
using std::string;


TEST_CASE("correct parsing") {
    AirTravel graph = AirTravel("./test_nodes","./test_edges");

    int count = 0;
    for(auto it : graph.graph_nodes) {
        if (it.first == "???")
            count++;
    }
    REQUIRE(count==0);

}