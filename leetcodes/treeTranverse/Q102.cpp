#include <vector>
#include <queue>
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
    vector<vector<int>> levelOrder(TreeNode *root)
    {
        queue<TreeNode *> queue;
        vector<vector<int>> ans;
        vector<int> temp;
        if (!root)
            return ans;
        queue.push(root);
        while (!queue.empty())
        {
            int size = queue.size();
            for (int i = 0; i < size; i++)
            {
                TreeNode *front = queue.front();
                queue.pop();
                temp.push_back(front->val);
                if (front->left)
                    queue.push(front->left);
                if (front->right)
                    queue.push(front->right);
            }
            ans.push_back(temp);
            temp.clear();
        }
        return ans;
    }
};
