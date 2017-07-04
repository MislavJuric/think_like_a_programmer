#include <iostream>

using namespace std;

//Write a function that is passed an array of integers and a “target” number and that returns the number of occurrences of
// the target in the array. Solve the problem first using iteration, then recursion.

int targetCountRecursive(int arr[], int target, int size)
{
    if (size == 0)
    {
        return 0;
    }
    int count = targetCountRecursive(arr, target, (size - 1));
    if (arr[size-1] == target)
    {
        count++;
    }
    return count;
}

int targetCountIterative(int arr[], int target, int size)
{
    int count = 0;
    for (int i = 0; i < size; i++)
    {
        if (arr[i] == target)
        {
            count++;
        }
    }
    return count;
}

int main()
{
    int array[6] {3, 1, 3, 2, 1, 3};
    int count = targetCountRecursive(array, 3, 6);
    cout << count << endl;
    return 0;
}
