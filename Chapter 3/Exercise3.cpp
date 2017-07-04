#include <iostream>

using namespace std;

//Write a bool function that is passed an array and the number of elements in that array and determines whether the data in
// the array is sorted. This should require only one pass

bool isSorted (int arrayToCheck[], int ARRAY_SIZE) // checks for ascending order
{
    for (int i = 0; i < (ARRAY_SIZE - 1); i++)
    {
        if (arrayToCheck[i] > arrayToCheck[i + 1])
        {
            return false;
        }
    }
    return true;
}

int main()
{
    const int ARRAY_SIZE = 10;
    int integerArray[ARRAY_SIZE] = {1, 2, 3, 4, 6, 7, 9, 19, 89, 39};
    bool sorted = isSorted(integerArray, ARRAY_SIZE);
    if (sorted)
    {
        cout << "Array is sorted." << endl;
    }
    else
    {
        cout << "Array is not sorted" << endl;
    }
    return 0;
}
