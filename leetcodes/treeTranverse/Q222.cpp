#include <vector>
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
public:
    int layer, temp1, temp2;
    int countNodes(TreeNode *root)
    {
        if (root == nullptr)
            return 0;
        temp1 = countLayer(root->left);
        temp2 = countLayer(root->right);
        if (temp1 == temp2)
        {
            return (1 << temp1) + countNodes(root->right);
        }
        else
        {
            return (1 << temp2) + countNodes(root->left);
        }
    }

    int countLayer(TreeNode *root)
    {
        layer = 0;
        while (root != nullptr)
        {
            root = root->left;
            ++layer;
        }
        return layer;
    }
};

class Solution_recursion
{
public:
    int countNodes(TreeNode *root)
    {
        if (root == NULL)
            return 0;
        return countNodes(root->left) + countNodes(root->right) + 1;
    }
};
