#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <unordered_map>
#include <string>

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

string AirTravel::Node::get_id() const{
    return identifier_;
}

void AirTravel::Node::set_adjacent(vector<string> edges){
    incident_edges = edges;
}


AirTravel::AirTravel(){}

AirTravel::AirTravel(string airports_file, string routes_file){
    vector<vector<string>> nodes = node_formatter(airports_file);

    vector<vector<string>> edges = edge_formatter(routes_file);
    size_t i = 0;
    for(vector<string> & airports : nodes){
        Node newnode(airports);
        string id = newnode.get_id();

        graph_nodes[id] = newnode;
        link[i] = id;
        i++;
    };

    for(auto it : graph_nodes){
        string id = it.first;
        Node & node = it.second;

        vector<string> incident = build_edges(id, edges);
        node.set_adjacent(incident);
    }
}


vector<vector<string>> AirTravel::node_formatter(string filename){
    
    std::cout << "starting function" << "\n"; ///////// debug //////////
    std::cout << "filename = " << filename << "\n"; ///////// debug //////////
   
    //airports formatter
    std::fstream AIfile (filename, std::ios::in);

    std::cout << AIfile.is_open() << "\n"; ///////// debug //////////

    //std::fstream AOfile (filename, std::ios::out);
    vector<vector<string>> data_vec;
    vector<string> temp;

    std::cout << AIfile.is_open() << "\n"; ///////// debug //////////

    std::string Aline;
    while (AIfile.is_open()) {
        
        //std::cout << "file gets opened" << "\n"; ///////// debug //////////
        
        std::getline(AIfile, Aline);

        //std::cout << Aline << "\n";  ///////// debug //////////

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