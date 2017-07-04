#include <iostream>

using namespace std;

// Solve exercise 6-2 again, using a linked list instead of an array.

struct element
{
    int number;
    element* next;
};

bool parity(element* head)
{
    if (head == NULL)
    {
        return false;
    }
    bool vparity = parity(head->next); // variable parity
    if (head->number == 1)
    {
        vparity = !vparity;
    }
    return vparity;
}

int main()
{
    element* linkedList = NULL;
    element* node1 = new element;
    element* node2 = new element;
    element* node3 = new element;
    linkedList = node1;
    node1->number = 0;
    node1->next = node2;
    node2->number = 1;
    node2->next = node3;
    node3->number = 1;
    node3->next = NULL;
    bool vparity = parity(linkedList);
    cout << vparity << endl;
    return 0;
}
