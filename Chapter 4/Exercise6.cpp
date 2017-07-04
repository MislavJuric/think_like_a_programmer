#include <iostream>

using namespace std;

//Let’s create an implementation for strings that uses a linked list of characters instead of dynamically allocated arrays.
// So we’ll have a linked list where the data payload is a single char; this will allow strings to grow without having to
// re-create the entire string. We’ll start by implementing the append and characterAt functions.

struct linkedString
{
    char letter;
    linkedString* next;
};

void append(linkedString* headPointer, char letterToAppend)
{
    linkedString* loopPointer = headPointer;
    linkedString* trail = NULL;
    while (loopPointer != NULL)
    {
        trail = loopPointer;
        loopPointer = loopPointer->next;
    }
    // after the while loop, trail should be at the last element

    /*

    Bad code: it places the character after the NULL

    linkedString* newNode = new linkedString;
    newNode->letter = letterToAppend;
    newNode->next = NULL;
    trail->next = newNode;
    */

    trail->letter = letterToAppend;
    linkedString* newNode = new linkedString;
    newNode->letter = 0;
    newNode->next = NULL;
    trail->next = newNode;
}

void output(linkedString* headPointer)
{
    linkedString* loopPtr = headPointer;
    while (loopPtr != NULL)
    {
        if ((loopPtr->letter) == 0)
        {
            break;
        }
        cout << loopPtr->letter << endl;
        loopPtr = loopPtr->next;
    }
}

int characterAt(linkedString* headPointer, char character)
{
    linkedString* loopPtr = headPointer;
    int position = 0;
    while ((loopPtr->letter) != character)
    {
        position++;
        loopPtr = loopPtr->next;
    }
    return position;
}

int main()
{
    linkedString* headPointer = NULL;
    linkedString* node1 = new linkedString;
    node1->letter = 't';
    linkedString* node2 = new linkedString;
    node2->letter = 'e';
    linkedString* node3 = new linkedString;
    node3->letter = 's';
    linkedString* node4 = new linkedString;
    node4->letter = 't';
    linkedString* node5 = new linkedString;
    node5->letter = 0;
    headPointer = node1;
    node1->next = node2;
    node2->next = node3;
    node3->next = node4;
    node4->next = node5;
    node5->next = NULL;
    node1 = node2 = node3 = node4 = node5 = NULL;

    /*

    append i characterAt tests

    append(headPointer, '!');
    output(headPointer);
    int result = characterAt(headPointer, 's');
    cout << result << endl;

    */


    return 0;
}
