#include <iostream>
#include <algorithm>

using namespace std;

//Are you disappointed we didn’t do more with sorting? I’m here to help. To make sure you are comfortable with qsort,
// write code that uses the function to sort an array of our student struct. First have it sort by grade, and then try it
// again using the student ID.

struct student
{
    int grade;
    int studentID;
    string name;
};

int compareByGrade(const void* pointer1, const void* pointer2)
{
    student* value1 = (student*) (pointer1);
    student* value2 = (student*) (pointer2);
    // return value1->grade - value2->grade;
    return (*value1).grade - (*value2).grade;
}

int compareByStudentID(const void* pointer1, const void* pointer2)
{
    student* value1 = (student*) (pointer1);
    student* value2 = (student*) (pointer2);
    // return value1->grade - value2->grade;
    return (*value1).studentID - (*value2).studentID;
}

int main()
{
    const int ARRAY_SIZE = 10;
    student studentArray[ARRAY_SIZE] = {
    {87, 10001, "Fred"},
    {28, 10002, "Tom"},
    {100, 10003, "Alistair"},
    {78, 10004, "Sasha"},
    {84, 10005, "Erin"},
    {98, 10006, "Belinda"},
    {75, 10007, "Leslie"},
    {70, 10008, "Candy"},
    {81, 10009, "Aretha"},
    {68, 10010, "Veronica"}
    };
    qsort(studentArray, ARRAY_SIZE, sizeof(student), compareByStudentID);
    for (int i = 0; i < ARRAY_SIZE; i++)
    {
        cout << studentArray[i].name << endl;
    }
    return 0;
}
