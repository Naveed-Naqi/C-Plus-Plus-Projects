#include <vector>
#include<iostream>

#define print(x) std::cout << x << "\n";

class Solution {
public:
    float round(float amount) {
        float temp = (int)(amount * 100 + 0.5);
        return (float)temp/100;
    }

    int coinChange(float amount) {


        amount = round(amount*1.3);
        int decimal = getDecimal(amount);
        int whole_num = getWholeNum(amount);

        int dollars[9] = {500, 200, 100, 50, 20 ,10 , 5, 2, 1};
        int cents[6] = {50, 25, 10, 5, 2, 1};

        return coinChangeHelper(whole_num, dollars, 9) + coinChangeHelper(decimal, cents, 6);
    }

    int coinChangeHelper(int amount, int* arr, std::size_t size) {

        int* count = new int[amount +1]();

        for(int i = 1; i < size; i++) {
            count[i] = amount +1;
        }
        count[0] = 0;

        for(int i = 1; i <= amount; i++) {
            for(int j = 0; j < size; j++) {
                if(arr[j] <= i) {
                    count[i]= std::min(count[i], count[i-arr[j]]+1);
                }
            }
        }

        return count[amount] > amount ? -1 : count[amount];
    }

    int getWholeNum(float amount) {
        return (int)amount;
    }

    float getDecimal(float amount) {
        return (amount - (int)amount) * 100;
    }
};

int main() {

    Solution solution;

    std::cout << solution.coinChange(1.25) << std::endl;
    return 0;
}