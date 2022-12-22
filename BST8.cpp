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

    BSTNode *subtreeWithRange(BSTNode *root, int lo, int hi)
    {
        if (root == nullptr)
            return nullptr;
        if (root->val >= lo && root->val <= hi)
            return root;
        else if (root->val < lo)
            return subtreeWithRange(root->right, lo, hi);
        else
            return subtreeWithRange(root->left, lo, hi);
    }
};