#include <iostream>
#include <list>

using namespace std;

//Rewrite our studentCollection functions from Chapter 4 (addRecord and averageRecord) so that instead of directly
// implementing a linked list, you use a class from the C++ library.

struct studentRecord
{
    int stuNum;
    int grade;
    string name;
};

class studentCollection
{
    public:
        studentCollection();
        ~studentCollection();
        void addRecord(studentRecord newStudent);
        double averageRecord();
        // I could copy the other methods, but let's keep this one clutter-free
    private:
        list<studentRecord> listOfStudents;
};

studentCollection::studentCollection()
{

}

studentCollection::~studentCollection()
{
    // do I need to destruct a std::list object?
}

void studentCollection::addRecord(studentRecord newStudent)
{
    listOfStudents.push_back(newStudent);
}

double studentCollection::averageRecord()
{
    double total = 0;
    int count = 0;
    for (list<studentRecord>::iterator iter = listOfStudents.begin(); iter != listOfStudents.end(); iter++)
    {
        total += iter->grade;
        count++;
    }
    if (total == -1)
    {
        // could throw an exception or something...
    }
    return (total / count);
}

int main()
{
    studentCollection sc;
    sc.addRecord(studentRecord{1, 5, "Mislav"});
    sc.addRecord(studentRecord{2, 4, "Marko"});
    cout << sc.averageRecord() << endl;
    return 0;
}
