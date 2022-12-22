#include <bits/stdc++.h>

using namespace std;

class BSTNode
{
public:
    int val;
    BSTNode *left;
    BSTNode *right;
    BSTNode()
    {
        this->left = this->right = nullptr;
    }
    BSTNode(int val)
    {
        this->val = val;
        this->left = this->right = nullptr;
    }
    BSTNode(int val, BSTNode *&left, BSTNode *&right)
    {
        this->val = val;
        this->left = left;
        this->right = right;
    }

    int singleChild(BSTNode *root)
    {
        if (root == nullptr)
            return 0;
        if (root->left == nullptr && root->right != nullptr)
            return 1 + singleChild(root->right);
        else if (root->left != nullptr && root->right == nullptr)
            return 1 + singleChild(root->left);
        else
            return singleChild(root->left) + singleChild(root->right);
    }
};