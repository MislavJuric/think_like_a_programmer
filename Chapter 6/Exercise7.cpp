#include <iostream>

using namespace std;

// Solve exercise 6-3 again, using a linked list instead of an array.

struct element
{
    int number;
    element* next;
};

int targetCount(element* head, int target)
{
    if (head == NULL)
    {
        return 0;
    }
    int count = targetCount(head->next, target);
    if (head->number == target)
    {
        count++;
    }
    return count;
}

int main()
{
    element* linkedList = NULL;
    element* node1 = new element;
    element* node2 = new element;
    element* node3 = new element;
    linkedList = node1;
    node1->number = 10;
    node1->next = node2;
    node2->number = 1;
    node2->next = node3;
    node3->number = 1;
    node3->next = NULL;
    int count = targetCount(linkedList, 1);
    cout << count << endl;
    return 0;
}
