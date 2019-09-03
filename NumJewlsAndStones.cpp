#include <iostream>
#include <unordered_map>

class Solution 
{
public:
    int numJewelsInStones(std::string J, std::string S) 
    {
        initMap(J);
        int count = 0;

        for(int i = 0; i < S.size(); i++)
        {
            if(char_map[S[i]])
            {
                count++;
            }
        }

        return count;
    }

private:
    std::unordered_map<char, bool> char_map;

    void initMap(std::string J)
    {
        for(int i = 0; i < J.size(); i++)
        {
            char_map[J[i]] = true;
        }
    }
};

int main()
{
    std::string J = "aA";
    std::string S = "aAAbbbb";

    Solution solution;

    int test = solution.numJewelsInStones(J, S);
    std::cout << test;

    return 0;
}