#include <iostream>
#include <string>
#include <algorithm>
#include <sstream>
using namespace std;

template<class K, class V>
class BinaryTree
{
public:
    class Node;
private:
    Node* root;
public:
    BinaryTree() : root(nullptr) {}
    ~BinaryTree()
    {
        // You have to delete all Nodes in BinaryTree. However in this task, you can ignore it.
    }
    class Node
    {
    private:
        K key;
        V value;
        Node* pLeft, * pRight;
        friend class BinaryTree<K, V>;
    public:
        Node(K key, V value) : key(key), value(value), pLeft(NULL), pRight(NULL) {}
        ~Node() {}
    };
    void addNode(string posFromRoot, K key, V value)
    {
        if (posFromRoot == "")
        {
            this->root = new Node(key, value);
            return;
        }
        Node* walker = this->root;
        int l = posFromRoot.length();
        for (int i = 0; i < l - 1; i++)
        {
            if (!walker)
                return;
            if (posFromRoot[i] == 'L')
                walker = walker->pLeft;
            if (posFromRoot[i] == 'R')
                walker = walker->pRight;
        }
        if (posFromRoot[l - 1] == 'L')
            walker->pLeft = new Node(key, value);
        if (posFromRoot[l - 1] == 'R')
            walker->pRight = new Node(key, value);
    }
    // STUDENT ANSWER BEGIN 
    int getHeight()
    {
        return getHeight(root);
    }
    int getHeight(Node* node)
    {
        if (node == NULL)
            return 0;
        else
        {
            int lheight = getHeight(node->pLeft);
            int rheight = getHeight(node->pRight);
            if (lheight > rheight)
                return(lheight + 1);
            else return(rheight + 1);
        }
    }

    string preOrder()
    {
        return preOrder(root);
    }
    string preOrder(Node* node)
    {
        if (node == NULL)
            return "";
        else
        {
            string s = "";
            s += node->value;
            s += preOrder(node->pLeft);
            s += preOrder(node->pRight);
            return s;
        }
    }

    string inOrder()
    {
        return inOrder(root);
    }
    string inOrder(Node* node)
    {
        if (node == NULL)
            return "";
        else
        {
            string s = "";
            s += inOrder(node->pLeft);
            s += node->value;
            s += inOrder(node->pRight);
            return s;
        }
    }

    string postOrder()
    {
        return postOrder(root);
    }
    string postOrder(Node* node)
    {
        if (node == NULL)
            return "";
        else
        {
            string s = "";
            s += postOrder(node->pLeft);
            s += postOrder(node->pRight);
            s += node->value;
            return s;
        }
    }
    // STUDENT ANSWER END
};

int main()
{
    BinaryTree<int, int> binaryTree;
    binaryTree.addNode("", 2, 4); // Add to root
    binaryTree.addNode("L", 3, 6); // Add to root's left node
    binaryTree.addNode("R", 5, 9); // Add to root's right node

    cout << binaryTree.getHeight() << endl;
    cout << binaryTree.preOrder() << endl;
    cout << binaryTree.inOrder() << endl;
    cout << binaryTree.postOrder() << endl;
}