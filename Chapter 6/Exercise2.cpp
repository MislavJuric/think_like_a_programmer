#include <iostream>

using namespace std;

//Consider an array representing a binary string, where every element’s data value is 0 or 1. Write a bool function to
// determine whether the binary string has odd parity (an odd number of 1 bits). Hint: Remember that the recursive function
// is going to return true (odd) or false (even), not the count of 1 bits. Solve the problem first using iteration, then
// recursion.

bool odd_parity_recursive(int arr[], int size)
{
    // special case when size == 0 could be checked
    if (size == 1)
    {
        if (arr[size - 1] == 0)
        {
            return false;
        }
        else
        {
            return true;
        }
    }
    bool odd = odd_parity_recursive(arr, (size - 1));
    if (arr[size - 1] == 1)
    {
        odd = !odd;
    }
    return odd;
}

int main()
{
    int zeroesAndOnes[5] {1, 1, 0, 0, 1};
    cout << odd_parity_recursive(zeroesAndOnes, 5) << endl;
    return 0;
}
