#include <iostream>
#include <string>
#include <stdexcept>

using namespace std;

//For the variable-length string class of the previous exercise, replace the characterAt method with an overloaded [] operator.
// For example, if myString is an object of our class, then myString[1] should return the same result as myString.characterAt(1).

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

char myString::operator[] (int position)
{
    charNode* loopPtr = this->listHead;
    int length = 0;
    while (loopPtr->next != NULL)
    {
        length++;
        loopPtr = loopPtr->next;
    }
    loopPtr = this->listHead;
    if (position > length)
    {
        throw out_of_range {"Array index out of range"};
    }
    for (int i = 0; i != position; i++)
    {
        loopPtr = loopPtr->next;
    }
    return loopPtr->character;
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

int main()
{
    myString mine {"Mislav"};
    // myString other {"Petar"};
    // mine.print();
    char position = mine[2];
    cout << position << endl;
    // mine.concatenate(mine, other);
    // mine.print();
    // cout << position << endl;
    return 0;
}
