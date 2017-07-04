#include <iostream>
#include <string>

using namespace std;

//For the variable-length string class of the previous exercises, add a remove method that takes a starting position and
// a number of characters and removes that many characters from the middle of the string. So myString.remove(5,3) would
// remove three characters starting at the fifth position. Make sure your method behaves when the value of either of the
// parameters is invalid.

class myString
{
    private:
        struct charNode
        {
            char character;
            charNode* next;
        };
    public:
        myString(string initialString);
        void print();
        char characterAt(int position);
        void concatenate(myString& s1, const myString& s2);
        char operator [] (int position);
        void remove(int startPos, int removeAmount);
    private:
        charNode* listHead {NULL};
        void append(charNode*& listHead, char toAppend);
        int length(const myString& s);
};

myString::myString(string initialString)
{
    // workaround because append adds from the end
    for (int i = initialString.length(); i >= 0; i--)
    {
        char c = initialString[i];
        append(listHead, c);
    }
}

char myString::characterAt(int position)
{
    charNode* loopPtr = this->listHead;
    for (int i = 0; i != position; i++)
    {
        loopPtr = loopPtr->next;
    }
    return loopPtr->character;
}

void myString::remove(int startPos, int removeAmount)
{
    if ((startPos < 0) || (removeAmount < 0))
    {
        cout << "Ooops! Arguments must be positive! (havent modified the string)" << endl;
        return;
    }
    charNode* loopPtr = listHead;
    int count = 0;
    while (loopPtr->next != NULL)
    {
        count++;
        loopPtr = loopPtr->next;
    }
    if ((startPos > count) || ((startPos + removeAmount) > count))
    {
        cout << "Oops! Starting position or remove amount out of range! (havent modified the string" << endl;
        return;
    }
    charNode* start = listHead;
    charNode* trail = NULL;
    for (int i = 0; i < startPos; i++)
    {
        trail = start;
        start = start->next;
    }
    cout << trail->character << " " << start->character << endl;
    for (int i = 0; i < removeAmount; i++)
    {
        charNode* temp = start->next;
        delete(start);
        trail->next = temp;
        start = temp;
        temp = temp->next;
    }
}

void myString::append(charNode*& listHead, char toAppend) // appends to the beggining of the listHead structure
{
    charNode* newCharacter = new charNode;
    newCharacter->character = toAppend;
    newCharacter->next = listHead;
    listHead = newCharacter;
}

void myString::print()
{
    charNode* loopPtr = listHead;
    while (loopPtr != NULL)
    {
        cout << loopPtr->character;
        loopPtr = loopPtr->next;
    }
}

int myString::length(const myString& s)
{
    int count = 0;
    charNode* loopPtr = s.listHead;
    while (loopPtr != NULL)
    {
        count++;
        loopPtr = loopPtr->next;
    }
    return count;
}

void myString::concatenate(myString& s1, const myString& s2)
{
    charNode* s1Ptr = s1.listHead;
    charNode* trail = NULL;
    while (s1Ptr != NULL)
    {
        trail = s1Ptr;
        s1Ptr = s1Ptr->next;
    }
    delete s1Ptr;
    // trail is now at the end of the 1st myString (omitting the \0)
    charNode* s2Ptr = s2.listHead;
    while (s2Ptr->character != '\0') //end-of-string
    {
        charNode* newNode = new charNode;
        trail->character = s2Ptr->character;
        trail->next = newNode;
        newNode->character = '\0'; // end-of-string
        newNode->next = NULL;
        s2Ptr = s2Ptr->next;
        trail = trail->next;
    }
}

char myString::operator [] (int position) // deprecated: see 5th_Chapter_Exercise_4.cpp
{
    charNode* loopPtr = listHead;
    for (int i = 0; i < position; i++)
    {
        loopPtr = loopPtr->next;
    }
    if (loopPtr->character == NULL) //huh? possible?
    {

    }
    return loopPtr->character;

}

int main()
{
    myString mine {"Mislav"};
    // myString other {"Petar"};
    // mine.print();
    mine.remove(3, 2);
    mine.print();
    // char position = mine[2];
    // cout << position << endl;
    // mine.concatenate(mine, other);
    // mine.print();
    // cout << position << endl;
    return 0;
}
