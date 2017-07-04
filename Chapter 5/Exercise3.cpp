#include <iostream>
#include <string>

using namespace std;

//Take the variable-length string functions from Chapter 4 (append, concatenate, and characterAt) and use them to create a
// class for variable-length strings, making sure to implement all necessary constructors, a destructor, and an overloaded
// assignment operator.

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
        void append(myString& listToAppendTo, char toAppend);
    private:
        charNode* listHead {NULL};
        int length(const myString& s);
};

myString::myString(string initialString)
{
    // workaround because append adds from the end
    for (int i = 0; i < initialString.length(); i++)
    {
        char c = initialString[i];
        append((*this), c);
    }
}

char myString::characterAt(int position)
{
    charNode* loopPtr = this->listHead;
    // provjeriti jel position izlazi iz scopea
    for (int i = 0; i != position; i++)
    {
        loopPtr = loopPtr->next;
    }
    return loopPtr->character;
}

void myString::append(myString& listToAppendTo, char toAppend) // appends to the beginning of the listHead structure
{
    charNode* newCharacter = new charNode;
    newCharacter->character = toAppend;
    /*
    newCharacter->next = listToAppendTo.listHead;
    listToAppendTo.listHead = newCharacter;
    */
    if (listToAppendTo.listHead == NULL)
    {
        newCharacter->next = NULL;
        listToAppendTo.listHead = newCharacter;
        return;
    }
    charNode* loopPtr = listToAppendTo.listHead;
    while (loopPtr->next != NULL)
    {
        loopPtr = loopPtr->next;
    }
    newCharacter->next = loopPtr->next;
    loopPtr->next = newCharacter;
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

void myString::concatenate(myString& s1, const myString& s2)
{
    //int s1_length = length(s1);
    int s2_length = length(s2);
    //int new_length = s1_length + s2_length - 1; // both have an empty character as their last element, hence the -1
    charNode* s1Ptr = s1.listHead;
    while (s1Ptr->next != NULL)
    {
        s1Ptr = s1Ptr->next;
    }
    // s1Ptr is now at the end of the 1st myString
    charNode* s2Ptr = s2.listHead;
    for (int i = 0; i < s2_length; i++)
    {
        charNode* newChar = new charNode;
        newChar->character = s2Ptr->character;
        newChar->next = NULL;
        s1Ptr->next = newChar;
        s1Ptr = s1Ptr->next;
        s2Ptr = s2Ptr->next;
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
    //cout << "Count is " << count << endl;
    return count;
}

int main()
{
    myString mine {"Mislav"};
    myString other {"Petar"};
    mine.print();
    cout << endl;
    other.append(other, 'b');
    other.print();
    cout << endl;
    //char position = mine.characterAt(2); //characterAt radi
    mine.concatenate(mine, other);
    mine.print();
    cout << endl;
    //cout << position << endl;
    return 0;
}
