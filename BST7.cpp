#include <bits/stdc++.h>

using namespace std;

class BSTNode
{
public: 
    int val; 
    BSTNode *left; 
    BSTNode *right; 
    BSTNode() {
        this->left = this->right = nullptr;
    } 
    BSTNode(int val) {
        this->val = val;
        this->left = this->right = nullptr;
    } 
    BSTNode(int val, BSTNode*& left, BSTNode*& right) {
        this->val = val;
        this->left = left;
        this->right = right;
    }

    int kthSmallest(BSTNode* root, int k)
    {
        if (root == nullptr)
            return -1;
        int left = kthSmallest(root->left, k);
        if (left != -1)
            return left;
        k--;
        if (k == 0)
            return root->val;
        return kthSmallest(root->right, k);
    }
};