#include <iostream>
#include <unordered_map>
#include <cmath>

/*
Roman numerals are represented by seven different symbols: I, V, X, L, C, D and M.

Symbol       Value
I             1
V             5
X             10
L             50
C             100
D             500
M             1000
For example, two is written as II in Roman numeral, just two one's added together. Twelve is written as, XII, which is simply X + II. The number twenty seven is written as XXVII, which is XX + V + II.

Roman numerals are usually written largest to smallest from left to right. However, the numeral for four is not IIII. Instead, the number four is written as IV. Because the one is before the five we subtract it making four. The same principle applies to the number nine, which is written as IX. There are six instances where subtraction is used:

I can be placed before V (5) and X (10) to make 4 and 9. 
X can be placed before L (50) and C (100) to make 40 and 90. 
C can be placed before D (500) and M (1000) to make 400 and 900.
Given a roman numeral, convert it to an integer. Input is guaranteed to be within the range from 1 to 3999.

Example 1:

Input: "III"
Output: 3
Example 2:

Input: "IV"
Output: 4
Example 3:

Input: "IX"
Output: 9
Example 4:

Input: "LVIII"
Output: 58
Explanation: L = 50, V= 5, III = 3.
Example 5:

Input: "MCMXCIV"
Output: 1994
Explanation: M = 1000, CM = 900, XC = 90 and IV = 4. */

class Solution 
{
public:
    int romanToInt(std::string s) 
    {
        std::unordered_map<char, int> numeral_map;
        intializeNumeralMap(numeral_map);

        int total = 0;

        for(int i = 0; i < s.length(); i++)
        {
            int curr_num = numeral_map[s[i]];

            if(i == s.length()-1) total += curr_num;
            else
            {
                int next_num = numeral_map[s[i+1]];

                if(specialCase(curr_num, next_num))
                {
                    total += (next_num - curr_num);
                    i++;
                }
                else
                {
                    total += curr_num;
                }

                       
            }
        }

        return total;
    }

    bool specialCase(int curr_num, int next_num)
    {
        return isPowerOfTen(curr_num) && areSameOrderOfMagnitude(curr_num, next_num) && next_num > curr_num;
    }

    bool isPowerOfTen(int curr_num)
    {
        int power = log10(curr_num);
        return curr_num == pow(10, power);
    }

    bool areSameOrderOfMagnitude(int curr_num, int next_num)
    {
        return ((int)log10(curr_num) - (int)log10(next_num)) < 2;
    }

    void intializeNumeralMap(std::unordered_map<char, int> &numeral_map)
    {
        numeral_map['I'] = 1;
        numeral_map['V'] = 5;
        numeral_map['X'] = 10;
        numeral_map['L'] = 50;
        numeral_map['C'] = 100;
        numeral_map['D'] = 500;
        numeral_map['M'] = 1000;
    }
};

int main()
{
    Solution solution;
    int test = solution.romanToInt("III");
    std::cout << test;
    return 0;
}