#include <vector>
#include <stack>
using namespace std;

// Definition for a binary tree node.
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution
{
private:
    bool forward;

public:
    Solution() : forward(true) {}
    vector<vector<int> > zigzagLevelOrder(TreeNode *root)
    {
        vector<vector<int> > ans;
        vector<int> temp;
        vector<TreeNode *> tempNodeVec;
        stack<TreeNode *> stackStore;
        int size;
        if (!root)
            return ans;

        stackStore.push(root);
        while (!stackStore.empty())
        {
            size = stackStore.size();
            for (int i = 0; i < size; i++)
            {
                TreeNode *t = stackStore.top();
                stackStore.pop();
                temp.push_back(t->val);
                if (forward)
                {
                    if (t->left)
                        tempNodeVec.push_back(t->left);
                    if (t->right)
                        tempNodeVec.push_back(t->right);
                }
                else
                {
                    if (t->right)
                        tempNodeVec.push_back(t->right);
                    if (t->left)
                        tempNodeVec.push_back(t->left);
                }
            }
            for (auto item : tempNodeVec)
            {
                stackStore.push(item);
            }
            tempNodeVec.clear();
            forward = !forward;
            ans.push_back(temp);
            temp.clear();
        }
        return ans;
    }
};