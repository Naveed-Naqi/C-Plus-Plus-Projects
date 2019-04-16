/*
Name: Naveed Naqi
Interface of the ReadMap Class
*/

#ifndef ROUTEMAP_H_
#define ROUTEMAP_H_

#include <iostream>
#include "City.hpp"

class RouteMap
{
public: 
    /**
    @param input_file_name of a csv file representing a route map where the first
    line is a comma-separated list of city names, and the remainder is a
    comma-separated list of city-pairs of the form A-B, indicating that B
    is adjacent to A (i.e. there is an arrow in the map going from A to B)
    @post this depends on your design, the input data representing the map must
    have been stored. Cities must be stored in the same order in which
    they are read from the input file
    **/
    bool readMap(std::string input_file_name);
private:
    std::vector<City> cities;
};

#endif // ROUTEMAP_H_