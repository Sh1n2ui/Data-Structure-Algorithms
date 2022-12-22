#include <iostream>
#include <string>
#include <sstream>
using namespace std;
#define SEPARATOR "#<ab@17943918#@>#"
template <class T>
class BinarySearchTree
{
public:
    class Node;

private:
    Node *root;

public:
    BinarySearchTree() : root(nullptr) {}
    ~BinarySearchTree()
    {
        // You have to delete all Nodes in BinaryTree. However in this task, you can ignore it.
        
    }

    // Helping function

    void add(T value)
    {
        Node *newNode = new Node(value);
        if (root == nullptr)
        {
            root = newNode;
            return;
        }
        Node *current = root;
        while (true)
        {
            if (value < current->value)
            {
                if (current->left == nullptr)
                {
                    current->left = newNode;
                    return;
                }
                current = current->left;
            }
            else
            {
                if (current->right == nullptr)
                {
                    current->right = newNode;
                    return;
                }
                current = current->right;
            }
        }
    }

    void deleteNode(T value)
    {
        Node *current = root;
        Node *parent = nullptr;
        while (current != nullptr)
        {
            if (current->value == value)
            {
                if (current->left == nullptr && current->right == nullptr)
                {
                    if (parent == nullptr)
                    {
                        root = nullptr;
                    }
                    else
                    {
                        if (parent->left == current)
                        {
                            parent->left = nullptr;
                        }
                        else
                        {
                            parent->right = nullptr;
                        }
                    }
                }
                else if (current->left == nullptr)
                {
                    if (parent == nullptr)
                    {
                        root = current->right;
                    }
                    else
                    {
                        if (parent->left == current)
                        {
                            parent->left = current->right;
                        }
                        else
                        {
                            parent->right = current->right;
                        }
                    }
                }
                else if (current->right == nullptr)
                {
                    if (parent == nullptr)
                    {
                        root = current->left;
                    }
                    else
                    {
                        if (parent->left == current)
                        {
                            parent->left = current->left;
                        }
                        else
                        {
                            parent->right = current->left;
                        }
                    }
                }
                else
                {
                    Node *successor = current->right;
                    Node *successorParent = current;
                    while (successor->left != nullptr)
                    {
                        successorParent = successor;
                        successor = successor->left;
                    }
                    current->value = successor->value;
                    if (successorParent->left == successor)
                    {
                        successorParent->left = successor->right;
                    }
                    else
                    {
                        successorParent->right = successor->right;
                    }
                }
                return;
            }
            else if (value < current->value)
            {
                parent = current;
                current = current->left;
            }
            else
            {
                parent = current;
                current = current->right;
            }
        }
    }
    string inOrderRec(Node *root)
    {
        stringstream ss;
        if (root != nullptr)
        {
            ss << inOrderRec(root->pLeft);
            ss << root->value << " ";
            ss << inOrderRec(root->pRight);
        }
        return ss.str();
    }

    string inOrder()
    {
        return inOrderRec(this->root);
    }

    class Node
    {
    private:
        T value;
        Node *pLeft, *pRight;
        friend class BinarySearchTree<T>;

    public:
        Node(T value) : value(value), pLeft(NULL), pRight(NULL) {}
        ~Node() {}
    };
};