#include <iostream>

class ArrayTest {

public:
    ArrayTest() {}
    
    void PrintArray() {

        for (int num : arr) {
            std::cout << num << std::endl;
        }
    }

private:
    int arr[3] = {1, 2, 3};
};

int main() {

    ArrayTest test;
    test.PrintArray();

    return 0;
}