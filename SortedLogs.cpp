#include <vector>
#include <iostream>

void swap(int &index1, int &index2) {
    int temp = index1;
    index1 = index2;
    index2 = temp;
}

void printLogs(int* arr, int size) {
    for(int i = 0; i < size; i++) {
        std::cout << arr[i] << "\t";
    }
    std::cout << "\n";
}

void sortLogs(int* logs, int size) {
 3
    
}

int main() {

    int logs[12] = { 0, 1, 1, 0, 1, 2, 1, 2, 0, 0, 0, 1 };

    printLogs(logs, 12);

    sortLogs(logs, 12);

    printLogs(logs, 12);

    return 0;
}