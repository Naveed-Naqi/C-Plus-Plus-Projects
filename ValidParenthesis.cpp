#include <iostream>
#include <stack>
#include <unordered_map>

/*
Given a string containing just the characters '(', ')', '{', '}', '[' and ']', determine if the input string is valid.

An input string is valid if:

Open brackets must be closed by the same type of brackets.
Open brackets must be closed in the correct order.
Note that an empty string is also considered valid.

Example 1:

Input: "()"
Output: true
Example 2:

Input: "()[]{}"
Output: true
Example 3:

Input: "(]"
Output: false
Example 4:

Input: "([)]"
Output: false
Example 5:

Input: "{[]}"
Output: true
*/

class Solution 
{
public:
    Solution()
    {
        map['('] == ')';
        map['{'] == '}';
        map['['] == ']';
    }
    bool isValid(std::string s) 
    {
        std::stack<char> my_stack;

        for(int i = 0; i < s.length(); i++)
        {

            auto iterator = map.find(s[i]);

            if(iterator != map.end())
            {
                my_stack.push(s[i]);
            }
        }

        return true;

    }
private:
    std::unordered_map<char, char> map;
        
};

int main()
{
    Solution solution;
    std::string test = "({})";

    solution.isValid(test) ? std::cout << "Y" : std::cout << "N";
    return 0;
}