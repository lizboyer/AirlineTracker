#pragma once

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>

using std::string;
using std::vector;


class data_formatter {
    public:
        vector<vector<string>> node_format(string filename);

        vector<vector<string>> edge_format(string filename);
};