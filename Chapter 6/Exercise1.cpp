#include <iostream>

using namespace std;

//Write a function to compute the sum of just the positive numbers in an array of integers. First, solve the problem using
// iteration. Then, using the technique shown in this chapter, convert your iterative function to a recursive function.

int sumOfPositiveNumbers(int arr[], int size)
{
    if (size == 0)
    {
        return 0;
    }
    int sum = sumOfPositiveNumbers(arr, (size - 1));
    if (arr[size - 1] > 0)
    {
        sum += arr[size - 1];
    }
    return sum;
}

int main()
{
    int arr[3] {1, 2, 3};
    cout << sumOfPositiveNumbers(arr, 3) << endl;
    return 0;
}
