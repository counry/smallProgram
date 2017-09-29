/*
 * =====================================================================================
 *
 *       Filename:  read_file.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  10/10/2014 10:30:52 AM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  YOUR NAME (), 
 *        Company:  
 *
 * =====================================================================================
 */


#include <iostream>
#include <algorithm>
#include <fstream>
#include <sstream>

int main(void)
{
    std::string infile = "/Users/counry/Downloads/test.data.xml";
    std::ifstream fin;
    std::string line;
    fin.open(infile, std::ifstream::in);
    if (fin.is_open()) {
        while (getline(fin, line)) {
            if (line == "") {
                continue;
            }
            uint64_t obj_id;
            std::string boundary;
            std::istringstream iss(line);
            if (!(iss >> obj_id >> boundary)) {
                continue;
            }
            std::cout << "obj_id:" << obj_id << " boundary:" << boundary << std::endl;
        }
    } else {
        std::cout << "file " << infile << " is not exists" << std::endl;
    }
    return 0;
}
