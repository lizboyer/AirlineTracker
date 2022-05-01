#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <unordered_map>
#include <string>
#include <cmath>

using std::unordered_map;
using std::vector;
using std::string;

#include "../include/graph.h"

AirTravel::Node::Node(){};

AirTravel::Node::Node(vector<string> strings){
    name_ = strings[0];
    identifier_ = strings[1];
    lat_ = stod(strings[2]);
    long_ = stod(strings[3]);
}

string AirTravel::Node::id() const{
    return identifier_;
}

string AirTravel::Node::name() const{
    return name_;
}

double AirTravel::Node::lat() const{
    return lat_;
}

double AirTravel::Node::lon() const{
    return long_;
}

void AirTravel::Node::set_adjacent(vector<string> edges){
    incident_edges = edges;
}


AirTravel::AirTravel(){}

AirTravel::AirTravel(string airports_file, string routes_file){
    vector<vector<string>> nodes = node_formatter(airports_file);

    vector<vector<string>> edges = edge_formatter(routes_file);
    size_t i = 0;

    //makes all the nodes
    for(vector<string> & airport : nodes){
        Node newnode(airport);
        string id = newnode.id();

        graph_nodes[id] = newnode;
        link[i] = id;
        i++;
    };

    //sets the edges
    for(auto it : graph_nodes){
        string id = it.first;
        Node & node = it.second;

        vector<string> incident = build_edges(id, edges);
        node.set_adjacent(incident);

        // if (incident.empty()) {          this code will ensure that nodes
        //     graph_nodes.erase(id);       with no outgoing edges will not be 
        // }                                included in the graph
    }
}


double AirTravel::CalcDist(string depart_id, string dest_id) {
    AirTravel::Node node1 = graph_nodes[depart_id];
    AirTravel::Node node2 = graph_nodes[dest_id];

    double lat1 = node1.lat();
    double lon1 = node1.lon();
    double lat2 = node2.lat();
    double lon2 = node2.lon();

    return std::sqrt(std::pow((lat2-lat1),2) + std::pow((lon2-lon1),2));
    
}


vector<vector<string>> AirTravel::node_formatter(string filename){
   
    //airports formatter
    std::fstream AIfile (filename, std::ios::in);

    //std::fstream AOfile (filename, std::ios::out);
    vector<vector<string>> data_vec;
    vector<string> temp;

    std::string Aline;
    while (AIfile.is_open()) {
        
        std::getline(AIfile, Aline);

        std::istringstream ss(Aline);
        std::string Atoken;

        int counter = 0;
        temp.clear();
        while(std::getline(ss, Atoken, ',')) {
            if (counter == 1 || counter == 4 || counter == 6 || counter == 7) {
                //if (counter != 1) {
                    //AOfile << ", ";
                temp.push_back(Atoken);
                
               // AOfile << Atoken;
            }
            counter++;
        }
        //AOfile << std::endl;
        data_vec.push_back(temp);

        if (AIfile.eof()) {
            break;
        }
    }
    return data_vec;
}



vector<vector<string>> AirTravel::edge_formatter(string filename){
    //routes formatter
    std::fstream RIfile (filename, std::ios::in);
    //std::fstream ROfile ("./data/routes_formatted.dat", std::ios::out);
    vector<vector<string>> data_vec;
    vector<string> temp;

    std::string Rline;
    while (RIfile.is_open()) {
        std::getline(RIfile, Rline);

        std::istringstream ss(Rline);
        std::string Rtoken;

        int counter = 0;
        temp.clear();
        while(std::getline(ss, Rtoken, ',')) {
            if (counter == 2 || counter == 4) {
                //if (counter != 2) {
                    //ROfile << ", "; }
                
                temp.push_back(Rtoken);
                //ROfile << Rtoken;
            }
            counter++;
        }
        //ROfile << std::endl;
        
        data_vec.push_back(temp);
        if (RIfile.eof()) {
            break;
        }
    }
    return data_vec;
}


vector<string> AirTravel::build_edges(string id, vector<vector<string>> & routes){
    vector<string> adjacent_ids;
    
    for (vector<string> & route : routes) {
        if (route[0] == id) {
            adjacent_ids.push_back(route[1]);
        }
    }

    return adjacent_ids;
}

void AirTravel::remove_extraneous() {
    unordered_map<string, bool> tracker;
    string key;
    for (auto it : graph_nodes) {
        key = it.first;
        tracker[key] = false;
    }
        

    for (auto it : graph_nodes){
        vector<string> & ed = it.second.incident_edges;
        for (int i = 0; i < int(ed.size()); i++) {
            tracker[ed[i]] = true;
        }
    }

    for (auto it : tracker) {
        if(!it.second)
            graph_nodes.erase(it.first);
    
    }
}