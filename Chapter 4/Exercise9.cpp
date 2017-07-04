#include <iostream>

using namespace std;

//Imagine a linked list where instead of the node storing a character, the node stores a digit: an int in the range 0–9.
// We could represent positive numbers of any size using such a linked list; the number 149, for example, would be a linked
// list in which the first node stores a 1, the second a 4, and the third and last a 9. Write a function intToList that takes
// an integer value and produces a linked list of this sort. Hint: You may find it easier to build the linked list backward,
// so if the value were 149, you would create the 9 node first.

struct listElem
{
    int digit;
    listElem* next;
};

int main()
{
    int input = 0;
    cin >> input;
    listElem* number = NULL;
    while (input > 0)
    {
        int digit = input % 10;
        listElem* newElem = new listElem;
        newElem->next = number;
        number = newElem;
        newElem->digit = digit;
        input /= 10;
    }
    listElem* loopPtr = number;
    while (loopPtr != NULL)
    {
        cout << loopPtr->digit << endl;
        loopPtr = loopPtr->next;
    }
    return 0;
}
