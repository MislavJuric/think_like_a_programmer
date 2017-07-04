#include <iostream>
#include <cstring>

using namespace std;

// A complaint offered against the policy/strategy pattern is that it requires exposing some internals of the class,
// such as types. Modify the “first student” program from earlier in this chapter so that the policy functions are all
// stored within the class and are chosen by passing a code value (of a new, enumerated type, for example), instead of
// passing the policy function itself.

struct studentRecord
{
    int stuNum;
    int grade;
    string name;
};

class studentCollection;

typedef bool (studentCollection::*firstStudentPolicy) (studentRecord r1, studentRecord r2);

class studentCollection
{
    private:
        struct studentNode
        {
            studentRecord studentData;
            studentNode* next;
        };
        bool higherGrade(studentRecord r1, studentRecord r2)
        {
            return r1.grade > r2.grade;
        }
        bool lowerStudentNumber(studentRecord r1, studentRecord r2)
        {
            return r1.stuNum < r2.stuNum;
        }
        bool nameComesFirst(studentRecord r1, studentRecord r2)
        {
            return strcmp(r1.name.c_str(), r2.name.c_str()) < 0;
        }
    public:
        studentCollection();
        ~studentCollection();
        void addRecord(studentRecord newStudent);
        studentRecord recordWithNumber(int idNum);
        void removeRecord(int idNum);
        void setFirstStudentPolicy(firstStudentPolicy f) { _currentPolicy = f; }
        studentRecord firstStudent();
        studentCollection& operator=(const studentCollection & rhs); // rhs == right-hand side
        studentCollection(const studentCollection &original);
        enum class policy
        {
            higherGrade,
            lowerStudentNumber,
            nameComesFirst
        };
        void choosePolicy(policy p)
        {
            if (p == policy::higherGrade)
            {
                _currentPolicy = &studentCollection::higherGrade;
            }
            else if (p == policy::lowerStudentNumber)
            {
                _currentPolicy = &studentCollection::lowerStudentNumber;
            }
            else if (p == policy::nameComesFirst)
            {
                _currentPolicy = &studentCollection::nameComesFirst;
            }
        }
    private:
        firstStudentPolicy _currentPolicy;
        typedef studentNode* studentList;
        studentList _listHead;
        void deleteList(studentList &listPtr);
        studentList copiedList (const studentList original);
};

studentRecord studentCollection::firstStudent()
{
    if (_listHead == NULL || _currentPolicy == NULL)
    {
        studentRecord dummyRecord{-1, -1, ""};
        return dummyRecord;
    }
    studentNode * loopPtr = _listHead;
    studentRecord first = loopPtr->studentData;
    loopPtr = loopPtr->next;
    while (loopPtr != NULL)
    {
        if ((this->*_currentPolicy)(loopPtr->studentData, first)) //if it passes the comparison
        {
            first = loopPtr->studentData;
        }
        loopPtr = loopPtr->next;
    }
    return first;
}

studentCollection& studentCollection::operator=(const studentCollection &rhs)
{
    if (this != &rhs)
    {
        deleteList(_listHead);
        _listHead = copiedList(rhs._listHead);
    }
    return *this;
}

studentCollection::studentList studentCollection::copiedList(const studentList original)
{
    if (original == NULL)
    {
        return NULL;
    }
    studentList newList = new studentNode;
    newList->studentData = original->studentData;
    studentNode * oldLoopPtr = original->next;
    studentNode * newLoopPtr = newList;
    while (oldLoopPtr != NULL)
    {
        newLoopPtr->next = new studentNode;
        newLoopPtr = newLoopPtr->next;
        newLoopPtr->studentData = oldLoopPtr->studentData;
        oldLoopPtr = oldLoopPtr->next;
    }
    newLoopPtr->next = NULL;
    return newList;
}

studentCollection::~studentCollection()
{
    deleteList(_listHead); // deleteList not static, how can it be called?
}

void studentCollection::deleteList(studentList &listPtr)
{
    while (listPtr != NULL)
    {
        studentNode* temp = listPtr;
        listPtr = listPtr->next;
        delete temp;
    }
}

studentCollection::studentCollection()
{
    _listHead = NULL;
    _currentPolicy = NULL;
}

void studentCollection::addRecord(studentRecord newStudent)
{
    studentNode* newNode = new studentNode;
    newNode->studentData = newStudent;
    newNode->next = _listHead;
    _listHead = newNode;
}

studentRecord studentCollection::recordWithNumber(int idNum)
{
    studentNode* loopPtr = _listHead;
    while (loopPtr != NULL && loopPtr->studentData.stuNum != idNum) // short-circuit evaluation
    {
        loopPtr = loopPtr->next;
    }
    if (loopPtr != NULL)
    {
        return loopPtr->studentData;
    }
    else
    {
        studentRecord dummyRecord{-1, -1, ""}; // dummy record - in the book, he probably uses the class from the previous example
        return dummyRecord;
    }
}

void studentCollection::removeRecord(int idNum)
{
    studentNode* loopPtr = _listHead;
    studentNode* trailing = NULL;
    while (loopPtr != NULL && loopPtr->studentData.stuNum != idNum)
    {
        trailing = loopPtr;
        loopPtr = loopPtr->next;
    }
    if (loopPtr == NULL)
    {
        return;
    }
    if (trailing == NULL)
    {
        _listHead = _listHead->next;
    }
    trailing->next = loopPtr->next;
    delete loopPtr;
}

studentCollection::studentCollection(const studentCollection &original)
{
    _listHead = copiedList(original._listHead);
}

int main()
{
    studentCollection sc;
    sc.addRecord(studentRecord{1, 5, "Mislav"});
    sc.addRecord(studentRecord{2, 4, "Marko"});
    sc.addRecord(studentRecord{3, 3, "Matea"});
    sc.choosePolicy(studentCollection::policy::nameComesFirst);
    studentRecord result = sc.firstStudent();
    cout << result.name << endl;
    sc.choosePolicy(studentCollection::policy::higherGrade);
    result = sc.firstStudent();
    cout << result.name << endl;
    return 0;
}
