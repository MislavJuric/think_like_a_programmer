/*
    To-do: strings with 0-terminator
*/

#include <iostream>

using namespace std;

//Following up on the previous exercise, implement the concatenate function. Note that if we make a call concatenate(s1, s2),
// where both parameters are pointers to the first nodes of their respective linked lists, the function should create a copy
// of each of the nodes in s2 and append them to the end of s1. That is, the function should not simply point the next field
// of the last node in s1’s list to the first node of s2’s list.

struct linkedString
{
    char letter;
    linkedString* next;
};

void removeChars(linkedString* s, int startPos, int amount)
{
    linkedString* loopPtr = s;
    linkedString* trail = NULL;
    int count = 0;
    while (count < startPos)
    {
        trail = loopPtr;
        loopPtr = loopPtr->next;
        count++;
    }
    for (int i = 0; i < amount; i++)
    {
        linkedString* temp = loopPtr->next;
        trail->next = temp;
        delete loopPtr;
        loopPtr = temp;
    }

}

void concatenate(linkedString* &string1, linkedString* string2)
{
    linkedString* loopPointer = string1;
    linkedString* trail = NULL;
    while (loopPointer != NULL)
    {
        trail = loopPointer;
        loopPointer = loopPointer->next;
    }
    linkedString* string2Pointer = string2;
    while (string2Pointer != NULL)
    {
        linkedString* newNode = new linkedString;
        newNode->letter = string2Pointer->letter;
        newNode->next = string2Pointer->next;
        trail->next = newNode;
        trail = trail->next;
        string2Pointer = string2Pointer->next;
    }
}

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
    /* linkedString* newNode = new linkedString;
    newNode->letter = 0;
    newNode->next = NULL; */
    trail->next = NULL;
}

void output(linkedString* headPointer)
{
    linkedString* loopPtr = headPointer;
    while (loopPtr != NULL)
    {
        /*

        NULL terminating character check

        if ((loopPtr->letter) == 0)
        {
            break;
        }

        */
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
    headPointer = node1;
    node1->next = node2;
    node2->next = node3;
    node3->next = node4;
    node4->next = NULL;
    node1 = node2 = node3 = node4 = NULL;
    linkedString* headPointer2 = NULL;
    linkedString* node5 = new linkedString;
    node5->letter = 'b';
    linkedString* node6 = new linkedString;
    node6->letter = 'e';
    linkedString* node7 = new linkedString;
    node7->letter = 'd';
    headPointer2 = node5;
    node5->next = node6;
    node6->next = node7;
    node7->next = NULL;
    concatenate(headPointer, headPointer2);
    removeChars(headPointer, 4, 1);
    output(headPointer);
    /*

    append i characterAt tests

    append(headPointer, '!');
    output(headPointer);
    int result = characterAt(headPointer, 's');
    cout << result << endl;

    */


    return 0;
}
