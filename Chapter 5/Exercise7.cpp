#include <iostream>

using namespace std;

//Take the student record functions from Chapter 4 (addRecord and averageRecord) and use them to create a class representing
// a collection of student records, as before, making sure to implement all necessary constructors, a destructor, and an
// overloaded assignment operator.

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
        studentCollection& operator= (const studentCollection& rhs);
        void print();
    private:
        listNode* listHead {NULL}; // this is instead of default constructor
};

/*
studentCollection& studentCollection::operator= (const studentCollection& rhs) //works, but has hacks -- needs improvement
{
    listNode* loopPtr = this->listHead; // first element of the left hand side
    while (loopPtr != NULL)
    {
        listNode* temp = loopPtr->next;
        // cout << "Deleting node with student number " << loopPtr->studentNum << endl;
        delete(loopPtr);
        loopPtr = temp;
    }
    this->listHead = NULL;
    loopPtr = rhs.listHead;
    bool first = true;
    bool first2 = true;
    while (loopPtr != NULL)
    {
        listNode* newNode = new listNode;
        newNode->grade = loopPtr->grade;
        newNode->studentNum = loopPtr->studentNum;
        newNode->next = NULL;
        if (first == true)
        {
            this->listHead = newNode;
            first = false;
        }
        listNode* temp = this->listHead;
        while (temp->next != NULL)
        {
            cout << "Executed" << endl;
            temp = temp->next;
        }
        if (first2 == false)
        {
            temp->next = newNode;
        }
        loopPtr = loopPtr->next;
        first2 = false;
    }
    return *this;
}
*/

// solution from reddit

studentCollection& studentCollection::operator = (const studentCollection& rhs) //works,but has hacks -- needs improvement
{
    if(this != &rhs)
    {
        listNode* loopPtr = this->listHead; // first element of the left hand side
        while (loopPtr != NULL)
        {
            listNode* temp = loopPtr->next;
            // cout << "Deleting node with student number " << loopPtr->studentNum << endl;
            delete(loopPtr);
            loopPtr = temp;
        }
        this->listHead = NULL;
        loopPtr = rhs.listHead;
        if(loopPtr != NULL)
        {
            this->listHead = new listNode;
            listNode* x = this->listHead;
            while (loopPtr != NULL)
            {
                x->grade = loopPtr->grade;
                x->studentNum = loopPtr->studentNum;
                x->next = NULL;
                loopPtr = loopPtr->next;
                if (loopPtr != NULL)
                {
                    x->next = new listNode;
                    x = x->next;
                }
            }
        }
    }
    return *this;
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
    //double average = sc.averageRecord();
    //cout << average << endl;
    studentCollection sc2;
    sc2.addRecord(50000, 50);
    sc2.addRecord(50001, 55);
    sc2.addRecord(50002, 60);
    //sc2.addRecord(50003, 65);
    sc = sc2;
    sc.print();
    cout << "--------------" << endl;
    sc2.print();
    //double average = sc.averageRecord();
    //cout << average << endl;
    return 0;
}
