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
        map[')'] = '(';
        map['}'] = '{';
        map[']'] = '[';
    }
    bool isOpeningBrace(char curr_letter)
    {
        for (std::pair <char, char> element : map)
	    {
            if(curr_letter == element.second) { return true; }
	    }

        return false;
    }
    bool isClosingBrace(char curr_letter)
    {
        for (std::pair <char, char> element : map)
	    {
            if(curr_letter == element.first) { return true; }
	    }

        return false;
    }
    bool isValid(std::string s) 
    {
        std::stack<char> my_stack;

        for(int i = 0; i < s.length(); i++)
        {
            if(isOpeningBrace(s[i])) { my_stack.push(s[i]); }
            
            else if(isClosingBrace(s[i]))
            {
                if(my_stack.empty()) { return false; }

                else
                {
                    char opening_brace = my_stack.top();

                    if(opening_brace != map[s[i]]) { return false; }

                    my_stack.pop();
                }
            }  
        }

        return my_stack.empty() ? true : false;

    }
private:
    std::unordered_map<char, char> map;
        
};

int main()
{
    Solution solution;
    std::string test = "({()}asdad";

    solution.isValid(test) ? std::cout << "Y" : std::cout << "N";
    return 0;
}