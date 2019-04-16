/*
Name: Naveed Naqi
Interface of the City Class
*/

#ifndef CITY_H_
#define CITY_H_

#include <iostream>
#include <vector>

class City
{
public:
    //Constructor, must initialize a city with a city_name
    City(std::string city_name);

    /*
    @pre: City object must have a city_name
    @post: Returns the city_name as a string
    */
    std::string getName() const;

    /*
    @param: input city_name is a valid string
    @post: Sets the city_name_ as the input parameter
    */
    void setName(std::string city_name);
    void addDestination(const City new_city);
    City getDestination(size_t position);
private:
    std::string city_name_;
    std::vector<City> destinations_;
};

#endif // CITY_H_