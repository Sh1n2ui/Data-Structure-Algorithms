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

    vector<int> levelAlterTraverse(BSTNode *root)
    {
        vector<int> res;
        if (root == nullptr)
            return res;
        queue<BSTNode *> q;
        q.push(root);
        bool isLeft = true;
        while (!q.empty())
        {
            int size = q.size();
            vector<int> level;
            for (int i = 0; i < size; i++)
            {
                BSTNode *node = q.front();
                q.pop();
                level.push_back(node->val);
                if (node->left)
                    q.push(node->left);
                if (node->right)
                    q.push(node->right);
            }
            if (isLeft)
            {
                for (int i = 0; (unsigned)i < level.size(); i++)
                {
                    res.push_back(level[i]);
                }
            }
            else
            {
                for (int i = level.size() - 1; i >= 0; i--)
                {
                    res.push_back(level[i]);
                }
            }
            isLeft = !isLeft;
        }
        return res;
    }
};