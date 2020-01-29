#include <iostream>
#include <vector>
#include <cmath>

float roundNumbers(float num) {
    num = num * 100 + 0.5;
    num = (int) num;
    return num/100;
}



int getCentTarget(float num) {
    return (num - (int)num)*100;
}

int coinChange(float target) {

    target = roundNumbers(target*1.3);
    int dollar_target = 0;//getDollarTarget(target);
    int cent_target = getCentTarget(target);
        
    const std::size_t DOLLAR_SIZE = 9;
    int dollars[DOLLAR_SIZE] = {500, 200, 100, 50, 20, 10, 5, 2, 1};

    const std::size_t CENT_SIZE = 6;
    int cents[CENT_SIZE] = {50, 25, 10, 2, 1};

    int counter = 0;
    /*

    while(dollar_target > 0) {

        int max_index = 0;

        for(int i = 0; i < DOLLAR_SIZE; i++) {
            if(dollars[i]  == dollar_target) {
                max_index = i;
                break;
            }
            else if (dollars[i] < dollar_target) {
                max_index = i-1;
                break;
            }
        }


        //std::cout << dollars[max_index] << std::endl;
        counter += dollar_target/dollars[max_index];
        //std::cout << dollar_target << std::endl;
        dollar_target -= counter * dollars[max_index];
    }
    */

    return dollar_target < 0 ? -1 : counter;
}


int main() {
    std::cout << coinChange(13.25);

    return 0;
}