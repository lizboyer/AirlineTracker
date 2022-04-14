#include <iostream>
#include <vector>
#include <unordered_map>
#include <string>

#include "graph.h"
#include "data_formatter/graph.hpp"
#include "data_formatter/data_formatter.h"

using std::unordered_map;
using std::vector;
using std::string;

AirTravel::Node::Node(){};

AirTravel::Node::Node(vector<string> strings){
    name_ = strings[0];
    identifier_ = strings[1];
    lat_ = stod(strings[2]);
    long_ = stod(strings[3]);
}

string AirTravel::Node::get_id(){
    return identifier_;
}


AirTravel::AirTravel(){}

AirTravel::AirTravel(string airports_file, string routes_file){
    vector<vector<string>> nodes = node_format(airports_file);

    vector<vector<string>> edges = edge_format(routes_file);

    for(int i = 0; i < int(nodes.size()); i++){
        Node newnode(nodes[i]);
        string id = newnode.get_id();

        graph_nodes[id] = newnode;

    };

    for
}