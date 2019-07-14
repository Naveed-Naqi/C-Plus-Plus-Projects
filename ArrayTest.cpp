#include <iostream>

struct Node
{
    int x, y;
};

Node* test()
{
    Node array[4] = {{0, 0}, {1, 1,}, {2, 2}, {3, 3}};
    return array;
}

int main()
{
    Node* my_array = test();

    std::cout << my_array[2].x;
}
