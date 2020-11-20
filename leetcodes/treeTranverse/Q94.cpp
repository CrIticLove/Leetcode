#include <algorithm>
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
    vector<int> ans;
    vector<int> inorderTraversal(TreeNode *root)
    {
        tranverse(root);
        return ans;
    }
    void tranverse(TreeNode *root)
    {
        if (!root)
            return;
        tranverse(root->left);
        ans.push_back(root->val);
        tranverse(root->right);
    }
};
