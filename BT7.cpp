#include <iostream>
#include <stack>
#include <queue>
#include <utility>

using namespace std;

class BTNode
{
public:
    int val;
    BTNode *left;
    BTNode *right;
    BTNode()
    {
        this->left = this->right = NULL;
    }
    BTNode(int val)
    {
        this->val = val;
        this->left = this->right = NULL;
    }
    BTNode(int val, BTNode *&left, BTNode *&right)
    {
        this->val = val;
        this->left = left;
        this->right = right;
    }

    int lowestAncestor(BTNode *root, int a, int b)
    {
        if (root == NULL)
            return -1;
        if (root->val == a || root->val == b)
            return root->val;
        int left = lowestAncestor(root->left, a, b);
        int right = lowestAncestor(root->right, a, b);
        if (left != -1 && right != -1)
            return root->val;
        if (left != -1)
            return left;
        if (right != -1)
            return right;
        return -1;
    }
};
