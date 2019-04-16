/*
Name: Naveed Naqi
Interface of the City Class
*/

#include "City.hpp"

City::City(std::string city_name): city_name_(city_name){} //End Constructor

std::string City::getName() const
{
    return city_name_;
}//End getName

void City::addDestination(const City new_city)
{
    destinations_.push_back(new_city);
}//End addDestination

City City::getDestination(size_t position)
{
    //Should add exception handling here to make sure position < destinations_.getSize()

    return destinations_.at(position);
}//End getDestination

void City::setName(std::string city_name)
{
    city_name_ = city_name;
}//End setName