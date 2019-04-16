/*
Name: Naveed Naqi
Implementation of the ReadMap Class
*/

#include "RouteMap.hpp"
#include <iostream>
#include <stack>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>

bool RouteMap::readMap(std::string input_file_name)
{
    //Creates a file input stream that reads the csv
    std::fstream fin(input_file_name);

    //Returns an error message if the file cannot be opened
    if(!fin.is_open())
    {
        std::cout << "ERROR: File can't be opened" << std::endl;
    }

    std::string row = "";

    std::vector<std::string> all_cities;
    std::vector<std::string> all_routes;

    std::string elements = "";

    int curr_line_number = 0;

    while(std::getline(fin, row))
    {
        if (curr_line_number == 0)
        {
            std::stringstream read_row(row);

            while(read_row.good())
            {
                std::getline(read_row, elements, ',');
                all_cities.push_back(elements);
            }
        }

        if (curr_line_number == 1)
        {
            std::stringstream read_row(row);

            while(read_row.good())
            {
                std::getline(read_row, elements, ',');
                all_routes.push_back(elements);
            }
        }

        curr_line_number++;
    }

    /*
    Prints out all elements in a vector    */
    for (std::vector<std::string>::iterator it = all_cities.begin(); it != all_cities.end(); ++it)
    {
        std::cout << *it << std::endl;
    }


    return true;

}