#include <iostream>

using namespace std;

//Some words in programming have more than one common meaning. In Chapter 4, we learned about the heap, from which we get
// memory allocated with new. The term heap also describes a binary tree in which each node value is higher than any in the
// left or right subtree. Write a recursive function to determine whether a binary tree is a heap.

struct Node
{
    int value;
    Node* leftChild;
    Node* rightChild;
};

bool isHeap(Node* root)
{
    if ((root->leftChild == NULL) && (root->rightChild == NULL))
    {
        return true;
    }
    else if ((root->leftChild != NULL) && (root->rightChild == NULL))
    {
        if (root->value > root->leftChild->value)
        {
            return isHeap(root->leftChild);
        }
        else
        {
            return false;
        }
    }
    else if ((root->leftChild == NULL) && (root->rightChild != NULL))
    {
        if (root->value > root->rightChild->value)
        {
            return isHeap(root->rightChild);
        }
        else
        {
            return false;
        }
    }
    else
    {
        if ((root->value > root->leftChild->value) && (root->value > root->rightChild->value))
        {
            return (isHeap(root->leftChild) && isHeap(root->rightChild));
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
    parentNode->value = 210;
    leftChild->value = 209;
    rightChild->value = 12;
    rightChildRightChild->value = 90;
    parentNode->rightChild = rightChild;
    parentNode->leftChild = leftChild;
    leftChild->rightChild = NULL;
    leftChild->leftChild = NULL;
    rightChild->rightChild = rightChildRightChild;
    rightChild->leftChild = NULL;
    rightChildRightChild->rightChild = NULL;
    rightChildRightChild->leftChild = NULL;
    cout << isHeap(parentNode) << endl;
    return 0;
}
