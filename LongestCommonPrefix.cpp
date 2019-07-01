#include <vector>
#include <iostream>

/*
Write a function to find the longest common prefix string amongst an array of strings.

If there is no common prefix, return an empty string "".

Example 1:

Input: ["flower","flow","flight"]
Output: "fl"
Example 2:

Input: ["dog","racecar","car"]
Output: ""
Explanation: There is no common prefix among the input strings.
Note:

All given inputs are in lowercase letters a-z. 
*/

class Solution 
{
public:
    std::string longestCommonPrefix(std::vector<std::string>& strs) 
    {
        if(strs.size() == 0) return "";

        std::string prefix = strs[0];

        for(int i = 1; i < strs.size(); i++)
        {
            while(strs[i].find(prefix) != 0)
            {
                prefix = prefix.substr(0, prefix.length()-1);

                if (prefix.length() == 0) return "";
            }
        }

        return prefix;
    }
};

int main()
{
    std::vector<std::string> words;

    words.push_back("Bieqw");
    words.push_back("Bigasd");
    words.push_back("Bibsfg");
    words.push_back("Biasdasd");
    words.push_back("Bigsdfs");
    words.push_back("Bihg");
    words.push_back("Bi");
    words.push_back("Biess");
    words.push_back("Bieewewas");
    words.push_back("Bifdafas");

    Solution solution;

    std::string prefix = solution.longestCommonPrefix(words);

    std::cout << prefix << std::endl;

    return 0;
}