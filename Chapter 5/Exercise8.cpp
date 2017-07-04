#include <iostream>

using namespace std;

//For the student record collection class of the previous exercise, add a method RecordsWithinRange that takes a low grade and
// a high grade as parameters and returns a new collection consisting of the records in that range (the original collection
// is unaffected). For example, myCollection.RecordsWithinRange(75, 80) would return a collection of all records with grades in
// the range 75–80 inclusive.

class studentCollection
{
    private:
        struct listNode
        {
             int studentNum;
             int grade;
             listNode *next;
        };
    public:
        void addRecord(int stuNum, int gr);
        double averageRecord();
        ~studentCollection();
        studentCollection operator= (const studentCollection& rhs);
        studentCollection RecordsWithinRange(int low, int high);
        void print();
    private:
        listNode* listHead {NULL}; // this is instead of default constructor
};

studentCollection studentCollection::RecordsWithinRange(int low, int high)
{
    listNode* loopPtr = this->listHead;
    studentCollection toReturn;
    while (loopPtr != NULL)
    {
        if ((loopPtr->grade > low) && (loopPtr->grade < high))
        {
            listNode* newNode = new listNode;
            newNode->grade = loopPtr->grade;
            newNode->studentNum = loopPtr->studentNum;
            newNode->next = toReturn.listHead;
            toReturn.listHead = newNode;
        }
        loopPtr = loopPtr->next;
    }
    return toReturn;
}

studentCollection studentCollection::operator= (const studentCollection& rhs)
{
    listNode* loopPtr = this->listHead; // first element of the left hand side
    //cout << loopPtr->studentNum << endl;
    while (loopPtr != NULL)
    {
        listNode* temp = loopPtr->next;
        cout << "Deleting node with student number " << loopPtr->studentNum << endl;
        delete(loopPtr);
        loopPtr = temp;
    }
    studentCollection toReturn;
    loopPtr = rhs.listHead;
    cout << loopPtr->studentNum << endl;
    while (loopPtr != NULL)
    {
        listNode* newNode = new listNode;
        cout << "Creating a new node with student number " << loopPtr->studentNum << endl;
        newNode->grade = loopPtr->grade;
        newNode->studentNum = loopPtr->studentNum;
        newNode->next = toReturn.listHead;
        toReturn.listHead = newNode;
        loopPtr = loopPtr->next;
    }
    return toReturn;
}

studentCollection::~studentCollection()
{
    listNode* loopPtr = listHead;
    listNode* temp;
    while (loopPtr != NULL)
    {
        temp = loopPtr->next;
        delete(loopPtr);
        loopPtr = temp;
    }
}

void studentCollection::addRecord(int stuNum, int gr)
{
    listNode* newNode = new listNode;
    newNode->studentNum = stuNum;
    newNode->grade = gr;
    newNode->next = listHead;
    listHead = newNode;
}

double studentCollection::averageRecord()
{
    double total = 0;
    int count = 0;
    listNode* loopPtr = listHead;
    while (loopPtr != NULL)
    {
        total += loopPtr->grade;
        count++;
        loopPtr = loopPtr->next;
    }
    return (total / count);
}

void studentCollection::print()
{
    listNode* loopPtr = this->listHead;
    while (loopPtr != NULL)
    {
        cout << loopPtr->studentNum << " " << loopPtr->grade << endl;
        loopPtr = loopPtr->next;
    }
}

int main()
{
    studentCollection sc;
    sc.addRecord(43983, 50);
    sc.addRecord(43984, 85);
    sc.addRecord(43985, 75);
    sc = sc.RecordsWithinRange(55, 95);
    return 0;
}
