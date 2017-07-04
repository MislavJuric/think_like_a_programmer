#include <iostream>

using namespace std;

//For the digit list of the previous exercise, write a function that takes two such lists and produces a new list
// representing their sum.

struct listElem
{
    int digit;
    listElem* next;
};

listElem* addNumbers(listElem* number, listElem* number2)
{
    int first_number = 0;
    listElem* loopPtr = number;
    while (loopPtr != NULL)
    {
        first_number = (first_number * 10) + loopPtr->digit;
        loopPtr = loopPtr->next;
    }
    int second_number = 0;
    loopPtr = number2;
    while (loopPtr != NULL)
    {
        second_number = (second_number * 10) + loopPtr->digit;
        loopPtr = loopPtr->next;
    }
    cout << first_number << " " << second_number << endl;
    int result = first_number + second_number;
    listElem* toReturn = NULL;
    while (result > 0)
    {
        listElem* newElem = new listElem;
        newElem->digit = result % 10;
        newElem->next = toReturn;
        toReturn = newElem;
        result /= 10;
    }
    return toReturn;
}

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
    /*
    listElem* loopPtr = number;
    while (loopPtr != NULL)
    {
        cout << loopPtr->digit << endl;
        loopPtr = loopPtr->next;
    }
    */
    cin >> input;
    listElem* number2 = NULL;
    while (input > 0)
    {
        int digit = input % 10;
        listElem* newElem = new listElem;
        newElem->next = number2;
        number2 = newElem;
        newElem->digit = digit;
        input /= 10;
    }
    /*
    loopPtr = number2;
    while (loopPtr != NULL)
    {
        cout << loopPtr->digit << endl;
        loopPtr = loopPtr->next;
    }
    */
    listElem* result = addNumbers(number, number2);
    listElem* loopPtr = result;
    while (loopPtr != NULL)
    {
        cout << loopPtr->digit << endl;
        loopPtr = loopPtr->next;
    }
    return 0;
}
