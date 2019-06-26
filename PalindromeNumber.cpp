#include <iostream>
#include <cmath>

/*
Determine whether an integer is a palindrome. An integer is a palindrome when it reads the same backward as forward.

Example 1:

Input: 121
Output: true
Example 2:

Input: -121
Output: false
Explanation: From left to right, it reads -121. From right to left, it becomes 121-. Therefore it is not a palindrome.
Example 3:

Input: 10
Output: false
Explanation: Reads 01 from right to left. Therefore it is not a palindrome.
Follow up:

Coud you solve it without converting the integer to a string? */

class Solution 
{
public:
    bool isPalindrome(int x) 
    {
        int place_val = findPlaceVal(x);

        int left = 0;
        int right = 0;

        if(x < 0) return false;

        while(x != 0)
        {
            left = x/pow(10, place_val);
            right = x % 10;

            x %= (int)pow(10, place_val);
            x /= 10;

            place_val -= 2;

            if(left != right)
            {
                return false;
            }
        }

        return true;
    }

    int findPlaceVal(int number)
    {
        return log10(number);
    }
};

int main()
{
    Solution solution;
    bool test = solution.isPalindrome(312213);
    test ? std::cout << "Yes" : std::cout << "No";
    return 0;
}