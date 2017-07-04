#include <iostream>

using namespace std;

//Write a program that processes an array of student objects and determines the grade quartiles—that is, the grade one would
// need to score as well as or better than 25% of the students, 50% of the students, and 75% of the students.

struct student
{
    int grade;
    int studentID;
    string name;
};

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
    int sum = 0;
    for (int i = 0; i < ARRAY_SIZE; i++)
    {
        sum += studentArray[i].grade;
    }
    int average_grade = sum / ARRAY_SIZE;
    int quartile = average_grade / 4; // wonder if this is correct?
    cout << "In order to be better than 25% of people you need to have a grade of " << quartile << ", to be better than 50% you need to be better than " << (quartile * 2) << " and to be better than 75% of the students you need to have a grade of " << (quartile * 3) << ".";
    return 0;
}
