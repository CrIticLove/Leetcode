#include <vector>
#include <stack>
using namespace std;

// Definition for a Node.
class Node
{
public:
    int val;
    vector<Node *> children;

    Node() {}

    Node(int _val)
    {
        val = _val;
    }

    Node(int _val, vector<Node *> _children)
    {
        val = _val;
        children = _children;
    }
};

class Solution_recursion
{
public:
    vector<int> ans;
    vector<int> preorder(Node *root)
    {
        preorderHelper(root);
        return ans;
    }

    void preorderHelper(Node *root)
    {
        if (root == nullptr)
            return;
        ans.push_back(root->val);
        for (Node *c : root->children)
        {
            preorderHelper(c);
        }
    }
};

class Solution_iteration
{
public:
    vector<int> preorder(Node *root)
    {
        vector<int> ans;
        stack<Node *> stk;
        vector<Node *>::reverse_iterator it;
        if (root == nullptr)
            return ans;
        stk.push(root);
        while (!stk.empty())
        {
            root = stk.top();
            stk.pop();
            ans.push_back(root->val);
            it = (root->children).rbegin();
            for (; it != root->children.rend(); ++it)
            {
                stk.push(*it);
            }
        }
        return ans;
    }
};
