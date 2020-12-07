#include <unordered_map>
using namespace std;

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
    unordered_map<TreeNode *, int> dp;
    unordered_map<TreeNode *, int>::iterator it;
    int rob(TreeNode *root)
    {
        helper(root);
        return dp[root];
    }
    int helper(TreeNode *root)
    {
        if (!root)
        {
            // 不插入叶节点比较快和省内存
            // dp.insert(make_pair(root, 0));
            return 0;
        }
        it = dp.find(root);
        if (it != dp.end())
        {
            return it->second;
        }
        int rob, not_rob;
        rob =
            (root->val) +
            (root->left ? (helper(root->left->left) + helper(root->left->right)) : 0) +
            (root->right ? (helper(root->right->left) + helper(root->right->right)) : 0);
        not_rob =
            helper(root->left) + helper(root->right);
        rob = max(rob, not_rob);
        dp.insert(make_pair(root, rob));
        return rob;
    }
};
