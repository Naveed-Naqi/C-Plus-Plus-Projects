#include <iostream>
#include <thread>
#include <chrono>

void delay() {
    using namespace std::chrono;
    using namespace std::this_thread;

    std::cout << "Working...\n";
    sleep_for(nanoseconds(10));
    sleep_until(system_clock::now() + seconds(2));
}

int main() {
    bool is_finished = false;
    int counter = 0;

    while(!is_finished) {
        
        delay();
        counter++;
        if(counter>10) { is_finished = true; }
    }
}