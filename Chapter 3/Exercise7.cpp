#include <iostream>
#include <vector>

using namespace std;

//Write a program that is given an array of integers and determines the mode, which is the number that appears most
// frequently in the array.

struct element
{
    int value;
    int count;
};

int main()
{
    const int ARRAY_SIZE = 10;
    int arrayInput[10] = {3, 9, 4, 5, 5, 5, 5, 5, 9, 9};
    vector<element> elements;
    for (int i = 0; i < ARRAY_SIZE; i++)
    {
        element novi;
        for (int j = 0; j < elements.size(); j++)
        {
            if (arrayInput[i] == elements[j].value)
            {
                elements[j].count++;
                break;
            }
        }
        novi.value = arrayInput[i];
        novi.count = 1;
        elements.push_back(novi);
    }
    int highest_frequency = 0;
    int mode = 0;
    for (int i = 0; i < elements.size(); i++)
    {
        if (elements[i].count > highest_frequency)
        {
            highest_frequency = elements[i].count;
            mode = elements[i].value;
        }
    }
    cout << "Mode is " << mode << endl;
    return 0;
}
