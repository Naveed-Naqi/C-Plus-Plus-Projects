#include "RouteMap.cpp"
#include "City.cpp"

int main()
{
    RouteMap map;

    //map.readMap("Map.csv");

    City old_city("B");

    City new_city("A");
    City new_city1("C");

    new_city.addDestination(old_city);
    new_city.addDestination(new_city1);

    City Travel = new_city.getDestination(0);
    City Travel1 = new_city.getDestination(1);

    std::cout << Travel.getName() << std::endl;
    std::cout << Travel1.getName() << std::endl;
}