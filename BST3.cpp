#include <iostream>
#include <string>
#include <sstream>

using namespace std;

template<class T>
class BinarySearchTree
{
public:
    class Node;

private:
    Node* root;

public:
    BinarySearchTree() : root(nullptr) {}
    ~BinarySearchTree()
    {
        // You have to delete all Nodes in BinaryTree. However in this task, you can ignore it.
    }

    class Node
    {
    private:
        T value;
        Node* pLeft, * pRight;
        friend class BinarySearchTree<T>;

    public:
        Node(T value) : value(value), pLeft(NULL), pRight(NULL) {}
        ~Node() {}
    };
    Node* addRec(Node* root, T value);
    void add(T value) ;
    // STUDENT ANSWER BEGIN
    
    bool find(T i)
    {
        Node* ptr = root;
        while (ptr != NULL)
        {
            if (ptr->value == i)
            {
                return true;
            }
            else if (ptr->value > i)
            {
                ptr = ptr->pLeft;
            }
            else
            {
                ptr = ptr->pRight;
            }
        }
        return false;
    }

    T sum(T l, T r)
    {
        T Sum = 0;
        Node* ptr = root;
        while (ptr != NULL)
        {
            if (ptr->value >= l && ptr->value <= r)
            {
                Sum += ptr->value;
                if (ptr->pLeft != NULL)
                {
                    Sum += sum(ptr->pLeft->value, r);
                }
                if (ptr->pRight != NULL)
                {
                    Sum += sum(l, ptr->pRight->value);
                }
                return Sum;
            }
            else if (ptr->value > r)
            {
                ptr = ptr->pLeft;
            }
            else
            {
                ptr = ptr->pRight;
            }
        }
        return Sum;
    }

    // STUDENT ANSWER END
};