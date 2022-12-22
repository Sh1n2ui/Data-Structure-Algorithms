#include <bits/stdc++.h>

using namespace std;

class BTNode {
    public: 
        int val; 
        BTNode *left; 
        BTNode *right; 
        BTNode() {
            this->left = this->right = NULL;
        } 
        BTNode(int val) {
            this->val = val;
            this->left = this->right = NULL;
        } 
        BTNode(int val, BTNode*& left, BTNode*& right) {
            this->val = val;
            this->left = left;
            this->right = right;
        }

        int rangeCount(BTNode* root, int lo, int hi)
        {
            if (root == NULL)
                return 0;
            if (root->val >= lo && root->val <= hi)
                return 1 + rangeCount(root->left, lo, hi) + rangeCount(root->right, lo, hi);
            else if (root->val < lo)
                return rangeCount(root->right, lo, hi);
            else
                return rangeCount(root->left, lo, hi);
        }
};