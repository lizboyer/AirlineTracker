#include "data_formatter.h"

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>

using std::string;
using std::vector;


vector<vector<string>> data_formatter::node_format(string filename){
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



vector<vector<string>> data_formatter::edge_format(string filename){
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
            if (counter == 2 || counter == 3 || counter == 4 || counter == 5) {
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