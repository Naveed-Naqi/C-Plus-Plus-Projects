
#include <vector>
#include <climits>
#include <iostream>

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};
 
class Solution {
public:
    int findMaxIndex(const std::vector<int>& nums, int start_index, int num_items) {
        
        int curr_max_index = start_index;

        for(int i = start_index; i < num_items; i++) {

            if(nums[curr_max_index] < nums[i]) {
                curr_max_index = i;
            }
        }
        
        return curr_max_index;
    }
    
    TreeNode* constructMaximumBinaryTree(std::vector<int>& nums) {
        return construct(nums, 0, nums.size());
    }

    TreeNode* construct(const std::vector<int>& nums, int start_index, int num_items) {

        if(start_index == num_items) { return nullptr; }

        int max_index = findMaxIndex(nums, start_index, num_items);
        TreeNode* root_ptr = new TreeNode(nums[max_index]);

        root_ptr->left = construct(nums, start_index, max_index);
        root_ptr->right = construct(nums, max_index+1, num_items);

        return root_ptr;
    }
    
};

void printTree(TreeNode* root_ptr) {

    if(root_ptr != nullptr) 
    {
        std::cout << root_ptr->val << std::endl;
        printTree(root_ptr->left);
        printTree(root_ptr->right);
    }
} 

int main()
{
    std::vector<int> nums{3, 2, 1, 6, 0, 5};

    Solution solution;
    TreeNode* root_ptr = solution.constructMaximumBinaryTree(nums);
    printTree(root_ptr);



    return 0;
}