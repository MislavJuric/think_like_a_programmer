#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

/*
    For the problem in 7-3, implement a solution by implementing an abstract
    data type that allows an arbitrary number of items to be stored and individual
    records to be retrieved based on a key value. A generic term for a structure
    that can efficiently store and retrieve items based on a key value is a symbol
    table, and common implementations of the symbol table idea are hash tables
    and binary search trees.
*/

#define ARRAY_SIZE 20

struct studentRecord
{
    int stuNum;
    int grade;
    string name;
};

ostream& operator << (ostream& os, studentRecord sr)
{
    os << "Student number: " << sr.stuNum << endl;
    os << "Grade: " << sr.grade << endl;
    os << "Name: " << sr.name;
}

// hash table implementation

// a nice exercise would be to do this parametrized (with templates), so that I'm not implementing it just for studentRecord

struct hashElement
{
    studentRecord data;
    hashElement *next;
};

class HashTable_Modulo
{
    private:
        hashElement** hashTable;
        int modulo {-1};
    public:
        HashTable_Modulo(int moduloArg);
        void AddElement(studentRecord elementToAdd);
        hashElement* SearchForElement(int studentNumber);
        void PrintAll();
        ~HashTable_Modulo();
        // other functions are unnecessary for this task
};

hashElement* HashTable_Modulo::SearchForElement(int studentNumber)
{
    int hashCompartment = studentNumber % modulo;
    hashElement* temp = hashTable[hashCompartment];
    while (temp != nullptr)
    {
        if (temp->data.stuNum != studentNumber)
        {
            temp = temp->next;
        }
        else
        {
            return temp;
        }
    }
}

HashTable_Modulo::HashTable_Modulo(int moduloArg)
{
    hashTable = new hashElement*[moduloArg] {nullptr};
    modulo = moduloArg;
}

HashTable_Modulo::~HashTable_Modulo()
{
    for (int i = 0; i < modulo; i++)
    {
        delete hashTable[i];
    }
    delete hashTable;
}

void HashTable_Modulo::AddElement(studentRecord elementToAdd)
{
    // I made this a parametrized type just as an exercise in templates, I know my type will be studentRecord
    int indexToPutIt = elementToAdd.stuNum % modulo;
    hashElement* oldPtr = hashTable[indexToPutIt];
    hashTable[indexToPutIt] = new hashElement;
    hashTable[indexToPutIt]->data = elementToAdd;
    hashTable[indexToPutIt]->next = oldPtr;
}

void HashTable_Modulo::PrintAll()
{
    for (int i = 0; i < modulo; i++)
    {
        hashElement* temp = hashTable[i];
        while (temp != nullptr)
        {
            cout << temp->data << endl;
            temp = temp->next;
        }
    }
}

int main()
{
    // randomly generating an array
    studentRecord studentArray[ARRAY_SIZE];
    HashTable_Modulo table{10}; // modulo will be 10 in this example
    string names[9] {"Bill", "Joe", "Bob", "Sally", "Janice", "Patrick", "John", "Bruce", "Maria"};
    srand(time(0));
    for (int i = 0; i < ARRAY_SIZE; i++)
    {
        studentArray[i].stuNum = 1 + rand() % 40000;
        studentArray[i].grade = 1 + rand() % 5;
        studentArray[i].name = names[rand() % 9];
    }
    for (int i = 0; i < ARRAY_SIZE; i++)
    {
        table.AddElement(studentArray[i]);
    }
    table.PrintAll();
    cout << "Enter the student number you are looking for: ";
    int toLookFor;
    cin >> toLookFor;
    hashElement* searchedForElement = table.SearchForElement(toLookFor);
    if (searchedForElement != nullptr)
    {
        cout << "Your element has been found. Here is the data: " << endl;
        cout << searchedForElement->data << endl;
    }
    else
    {
        cout << "Your element has not been found." << endl;
    }
    return 0;
}
