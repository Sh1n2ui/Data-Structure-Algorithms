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
        
        int longestPathSum(BTNode* root)
        {
            if (root == NULL)
                return 0;
            int sum = 0;
            queue<BTNode*> q;
            q.push(root);
            while (!q.empty())
            {
                BTNode* node = q.front();
                q.pop();
                if (node->left == NULL && node->right == NULL)
                    sum += node->val;
                if (node->left != NULL)
                {
                    node->left->val += node->val * 10;
                    q.push(node->left);
                }
                if (node->right != NULL)
                {
                    node->right->val += node->val * 10;
                    q.push(node->right);
                }
            }
            return sum;
        }
};