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
    T getMin()
    {
        Node* ptr = root;
        while (ptr->pLeft != NULL)
        {
            ptr = ptr->pLeft;
        }
        return ptr->value;
    }

    T getMax()
    {
        Node* ptr = root;
        while (ptr->pRight != NULL)
        {
            ptr = ptr->pRight;
        }
        return ptr->value;
    }
    // STUDENT ANSWER END
};