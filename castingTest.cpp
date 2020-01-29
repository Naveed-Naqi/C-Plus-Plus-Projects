#include <iostream>
#include <sstream>

int main() {
    
    std::string test1 = "3";
    std::stringstream stream(test1);

    int x = 0;
    stream >> x;
    std::cout<< x + 3;

    stream("5");
    int y = 0;
    stream >> y;

    std::cout << y;



    return 0;
}