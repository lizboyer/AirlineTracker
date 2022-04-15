#pragma once

#include <iostream>
#include <vector>
#include <unordered_map>
#include <string>

using std::unordered_map;
using std::vector;
using std::string;



/*this is the "AorTravel class (we could change the name to whatever)"
it contains a nested class node. The nodes are stored in a std::unordered map, 
which is a hash map. The keys should be the 3 letter identifiers, so that 
you can search by identifier in constant time.
*/
class AirTravel {
    private:

        class Node {
            /*The Node class has a private variable for each of the relevant categories 
            that we wanted . It also has a vector of strings, which are the 3 
            letter identifiers. This way, you can access the adjacent nodes in constant time
            because the 3 letter identifiers are also the keys of the hash map.
            */
        public:
            //default constructor
            Node();

            //constructs the node from a vector of strings where each string
            //is one of the member variables.
            Node(vector<string> strings);

            //returns the vector of identifiers of adjacent nodes
            //vector<string> Adjacent();

            //returns the airport's identifier
            string get_id() const;

            void set_adjacent(vector<string> edges);

        private:

            string name_;
            string identifier_;
            double lat_;
            double long_;

            vector<string> incident_edges;
  
        };

        unordered_map<string, Node> graph_nodes;

    public:

        AirTravel();

        AirTravel(string airports_file, string routes_file);

        //double CalcDist(string depart_id, string dest_id);

    
    private:


        /*  used in the constructor to build the graph
        takes in a filename as a string, the file should be the
        csv containing the airports, returns a vector of vectors of strings,
        where each nested vector contains strings of the member variables of the node
        representing that airport
        */
        vector<vector<string>> node_format(string filename);


        /*  used in the constructor to build the graph
        takes in a filename as a string, the file should be the
        csv containing the routes, returns a vector of vectors of strings,
        where each nested vector contains 2 strings, which are the identifier ofthe
        source airport and desitination airport respectively.
        */
        vector<vector<string>> edge_format(string filename);

        /*   used in the constructor to build the graph
        takes in a string which is a 3 letter identifier and a
        reference to the 2d vector of routes. Iterates through the 2d
        vector of edges/routes and returns a vector of all the identifiers which are 
        destinations of the id it takes in.
        */
        vector<string> build_edges(string id, vector<vector<string>> & routes);

};

