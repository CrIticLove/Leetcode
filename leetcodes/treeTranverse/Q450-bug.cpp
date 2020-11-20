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
    int findPredecessor(TreeNode *root)
    {
        root = root->left;
        while (root->right)
        {
            root = root->right;
        }
        return root->val;
    }
    int findSuccessor(TreeNode *root)
    {
        root = root->right;
        while (root->left)
        {
            root = root->left;
        }
        return root->val;
    }
    TreeNode *deleteNode(TreeNode *root, int key)
    {
        TreeNode *search = root;
        while (search->val != key)
        {
            if (search->val > key)
            {
                search = search->left;
            }
            else
            {
                search = search->right;
            }
        }
        if (!search->left && !search->right)
        {
            search = nullptr;
        }
        if (search->left)
        {
            search->val = findPredecessor(search);
            search->left = deleteNode(search->left, search->val);
        }
        else
        {
            search->val = findSuccessor(search);
            search->right = deleteNode(search->right, search->val);
        }
        return root;
    }
};