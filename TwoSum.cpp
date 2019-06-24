/*Given an array of integers, return indices of the two numbers such that they add up to a specific target.

You may assume that each input would have exactly one solution, and you may not use the same element twice.

Example:

Given nums = [2, 7, 11, 15], target = 9,

Because nums[0] + nums[1] = 2 + 7 = 9,
return [0, 1]. */

#include <unordered_map>
#include <vector>
#include <iostream>

#define print(x) std::cout << x << ", "; 

class Solution {
public:
    std::vector<int> twoSum(std::vector<int>& nums, int target) 
    {
        std::vector<int> correct_indices;
        std::unordered_map<int, int> freq_map;

        for(int i = 0; i < nums.size(); i++)
        {
            freq_map[nums[i]] = i;
        }

        for(int i = 0; i < nums.size(); i++)
        {
            int inverse = target - nums[i];
            std::unordered_map<int, int>::const_iterator iterator =  freq_map.find(inverse);

            if (iterator != freq_map.end())
            {
                correct_indices.push_back(i);
                correct_indices.push_back(iterator->second);
                return correct_indices;
            }
        }
        
        return correct_indices;
    }
};

void printVector(std::vector<int> &nums)
{
    for(int i = 0; i < nums.size(); i++)
    {
        print(nums[i]);
    }

    std::cout << "\n";
}

int main()
{   
    Solution test;
    std::vector<int> container;

    for(int i = 0; i < 10; i++)
    {
        container.push_back(i);
    }

    std::vector<int> correct_indices  = test.twoSum(container, 9);
    printVector(correct_indices);
} 