#include <iostream>

using namespace std;

//A binary search tree is a binary tree in which each node value is greater than any value in that node’s left subtree but
// less than any value in the node’s right subtree. Write a recursive function to determine whether a binary tree is a binary
// search tree.

struct Node
{
    int value;
    Node* leftChild;
    Node* rightChild;
};

bool isBinarySearchTree(Node* root)
{
    if ((root->leftChild == NULL) && (root->rightChild == NULL))
    {
        return true;
    }
    else if ((root->leftChild != NULL) && (root->rightChild == NULL))
    {
        if (root->value > root->leftChild->value)
        {
            return isBinarySearchTree(root->leftChild);
        }
        else
        {
            return false;
        }
    }
    else if ((root->leftChild == NULL) && (root->rightChild != NULL))
    {
        if (root->value < root->rightChild->value)
        {
            return isBinarySearchTree(root->rightChild);
        }
        else
        {
            return false;
        }
    }
    else
    {
        if ((root->value > root->leftChild->value) && (root->value < root->rightChild->value))
        {
            return (isBinarySearchTree(root->leftChild) && isBinarySearchTree(root->rightChild));
        }
        else
        {
            return false;
        }
    }
}

int main()
{
    Node* parentNode = new Node;
    Node* leftChild = new Node;
    Node* rightChild = new Node;
    Node* rightChildRightChild = new Node;
    parentNode->value = 108;
    leftChild->value = 18;
    rightChild->value = 190;
    rightChildRightChild->value = 180;
    parentNode->rightChild = rightChild;
    parentNode->leftChild = leftChild;
    leftChild->rightChild = NULL;
    leftChild->leftChild = NULL;
    rightChild->rightChild = rightChildRightChild;
    rightChild->leftChild = NULL;
    rightChildRightChild->rightChild = NULL;
    rightChildRightChild->leftChild = NULL;
    cout << isBinarySearchTree(parentNode) << endl;
    return 0;
}
