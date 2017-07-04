#include <iostream>

using namespace std;

//Solve exercise 6-1 again, using a linked list instead of an array.

struct element
{
    int number;
    element* next;
};

int positiveSum(element* head)
{
    if (head == NULL)
    {
        return 0;
    }
    int count = positiveSum(head->next);
    if (head->number > 0)
    {
        count += head->number;
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
    node1->number = 9;
    node1->next = node2;
    node2->number = 8;
    node2->next = node3;
    node3->number = -2;
    node3->next = NULL;
    int count = positiveSum(linkedList);
    cout << count << endl;
    return 0;
}
