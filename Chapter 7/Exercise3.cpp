#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

/*
	Consider a collection of studentRecord objects. We want to be able to quickly
	find a particular record based on student number. Store the student records
	in an array, sort the array by student number, and investigate and implement
	the interpolation search algorithm.
*/

#define ARRAY_SIZE 9

struct studentRecord
{
    int stuNum;
    int grade;
    string name;
};

int interpolationSearch(studentRecord arr[], int studentNumberToLookFor, int lowIndex, int highIndex)
{
    // invariant
    if (studentNumberToLookFor < 0)
    {
        cout << "Student number can't be negative." << endl;
        return -1; // or throw an exception
    }
    int low = lowIndex;
    int high = highIndex;
    while (low < high)
    {
        int pos = (int)(low + ((studentNumberToLookFor - arr[low].stuNum) * (high - low)) / (arr[high].stuNum - arr[low].stuNum));
        if (arr[pos].stuNum == studentNumberToLookFor)
        {
            return pos;
        }
        else
        {
            if (arr[pos].stuNum < studentNumberToLookFor)
            {
                low = pos + 1;
            }
            else
            {
                high = pos - 1;
            }
        }
    }
    // we passed the while loop, didn't return anything
    cout << "Sorry! The index you were looking for was not found." << endl;
    return -1;
}

int main()
{
    studentRecord studentArray[ARRAY_SIZE];
    string names[9] {"Bill", "Joe", "Bob", "Sally", "Janice", "Patrick", "John", "Bruce", "Maria"};
    srand(time(0));
    for (int i = 0; i < ARRAY_SIZE; i++)
    {
        studentArray[i].stuNum = 1 + rand() % 40000;
        studentArray[i].grade = 1 + rand() % 5;
        studentArray[i].name = names[rand() % 9];
    }
    // insertion sort
    for (int j = 1; j < ARRAY_SIZE; j++)
    {
        int key = studentArray[j].stuNum;
        studentRecord objectToSwap = studentArray[j];
        int i = j - 1;
        while ((i >= 0) && (studentArray[i].stuNum > key))
        {
            studentArray[i + 1] = studentArray[i];
            i--;
        }
        studentArray[i + 1] = objectToSwap;
    }
    for (int i = 0; i < ARRAY_SIZE; i++)
    {
        cout << studentArray[i].stuNum << " " << studentArray[i].grade << " " << studentArray[i].name << endl;
    }
    cout << "Which student number are you looking for?" << endl;
    int studentNumber;
    cin >> studentNumber;
    cout << "Your student number is at position " <<
    interpolationSearch(studentArray, studentNumber, 0, (ARRAY_SIZE - 1)) << "." << endl;;
    return 0;
}
