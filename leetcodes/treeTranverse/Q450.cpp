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
        if (root == nullptr)
            return root;
        if (key < root->val)
        {
            root->left = deleteNode(root->left, key);
            return root;
        }
        else if (key > root->val)
        {
            root->right = deleteNode(root->right, key);
            return root;
        }
        // found
        if (root->left == nullptr && root->right == nullptr)
        {
            delete root;
            return nullptr;
        }
        if (root->right != nullptr && root->left == nullptr)
        {
            TreeNode *right = root->right;
            delete root;
            return right;
        }
        if (root->left != nullptr && root->right == nullptr)
        {
            TreeNode *left = root->left;
            delete root;
            return left;
        }
        TreeNode *temp = root->right;
        int successor = findSuccessor(root);
        root->val = successor;
        root->right = deleteNode(root->right, successor);

        // delete predecessor
        // int predecessor = findPredecessor(root);
        // root->val = predecessor;
        // root->left = deleteNode(root->left, predecessor);

        return root;
    }
};
