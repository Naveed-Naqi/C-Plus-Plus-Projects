#include <iostream>
/*
Given a 32-bit signed integer, reverse digits of an integer.

Example 1:

Input: 123
Output: 321
Example 2:

Input: -123
Output: -321
Example 3:

Input: 120
Output: 21
Note:
Assume we are dealing with an environment which could only store integers within the 32-bit signed integer range: [−231,  231 − 1]. 
For the purpose of this problem, assume that your function returns 0 when the reversed integer overflows.
 */

class Solution 
{
public:
    int reverse(int x) 
    {
        long int pop = 0;
        long int reversed_num = 0;

        while(x != 0)
        {
            pop = x % 10;
            x /= 10;
            if(reversed_num > INT32_MAX/10 || (reversed_num == INT32_MAX/10 && pop > 7)) return 0;
            if(reversed_num < INT32_MIN/10 || (reversed_num == INT32_MIN/10 && pop < -8)) return 0;
            reversed_num = (reversed_num*10) + pop;
        }

        return reversed_num;
    }
};

int main()
{
    int test = 5123;

    Solution solution;
    int solve = solution.reverse(test);
    //std::cout << solve;

}