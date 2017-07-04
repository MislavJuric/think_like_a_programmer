#include <iostream>

using namespace std;

//Write a recursive function that is passed a binary search tree’s root pointer and a new value to be inserted and that
// creates a new node with the new value, placing it in the correct location to maintain the binary search tree structure.
// Hint: Consider making the root pointer parameter a reference parameter.

struct Node
{
    int value;
    Node* leftChild;
    Node* rightChild;
};

void insertIntoBinarySearchTree(Node*& root, int value)
{
    if (root == NULL)
    {
        root = new Node;
        root->value = value;
        root->leftChild = NULL;
        root->rightChild = NULL;
        return;
    }
    if (value > root->value)
    {
        insertIntoBinarySearchTree(root->rightChild ,value);
    }
    if (value < root->value)
    {
        insertIntoBinarySearchTree(root->leftChild ,value);
    }
}

void printTree(Node* root)
{
    if (root->leftChild != NULL)
    {
       printTree(root->leftChild);
    }
    if (root != NULL)
    {
        cout << root->value << endl;
    }
    if (root->rightChild != NULL)
    {
        printTree(root->rightChild);
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
    rightChildRightChild->value = 210;
    parentNode->rightChild = rightChild;
    parentNode->leftChild = leftChild;
    leftChild->rightChild = NULL;
    leftChild->leftChild = NULL;
    rightChild->rightChild = rightChildRightChild;
    rightChild->leftChild = NULL;
    rightChildRightChild->rightChild = NULL;
    rightChildRightChild->leftChild = NULL;
    printTree(parentNode);
    cout << endl;
    insertIntoBinarySearchTree(parentNode, 80);
    printTree(parentNode);
    return 0;
}
