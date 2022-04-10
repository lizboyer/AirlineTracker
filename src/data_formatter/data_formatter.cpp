
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>

int main() {
    //airports formatter
    std::fstream AIfile ("./data/airports.dat", std::ios::in);
    std::fstream AOfile ("./data/airports_formatted.dat", std::ios::out);

    std::string Aline;
    while (AIfile.is_open()) {
        std::getline(AIfile, Aline);

        std::istringstream ss(Aline);
        std::string Atoken;

        int counter = 0;
        while(std::getline(ss, Atoken, ',')) {
            if (counter == 1 || counter == 4 || counter == 6 || counter == 7) {
                if (counter != 1) {
                    AOfile << ", ";
                }
                AOfile << Atoken;
            }
            counter++;
        }
        AOfile << std::endl;

        if (AIfile.eof()) {
            break;
        }
    }




    //routes formatter
    std::fstream RIfile ("./data/routes.dat", std::ios::in);
    std::fstream ROfile ("./data/routes_formatted.dat", std::ios::out);

    std::string Rline;
    while (RIfile.is_open()) {
        std::getline(RIfile, Rline);

        std::istringstream ss(Rline);
        std::string Rtoken;

        int counter = 0;
        while(std::getline(ss, Rtoken, ',')) {
            if (counter == 2 || counter == 3 || counter == 4 || counter == 5) {
                if (counter != 2) {
                    ROfile << ", ";
                }
                ROfile << Rtoken;
            }
            counter++;
        }
        ROfile << std::endl;
        
        if (RIfile.eof()) {
            break;
        }
    }
}