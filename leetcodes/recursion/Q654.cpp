#include <vector>
using namespace std;

// Definition for a binary tree node.
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution
{
public:
    TreeNode *constructMaximumBinaryTree(vector<int> &nums)
    {
        TreeNode *root;
        root = helper(nums, 0, nums.size());
        return root;
    }

    TreeNode *helper(vector<int> &nums, int i, int j)
    {
        if (i >= j)
            return nullptr;
        int pos = max_element(nums.begin() + i, nums.begin() + j) - nums.begin();
        TreeNode *temp = new TreeNode(nums[pos]);
        temp->left = helper(nums, i, pos);
        temp->right = helper(nums, pos + 1, j);
        return temp;
    }
};
