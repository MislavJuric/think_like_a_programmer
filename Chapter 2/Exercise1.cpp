#include <iostream>

using namespace std;

/*
Using the same rule as the shapes programs from earlier in the chapter (only two output statements—one that outputs
the hash mark and one that outputs an end-of-line), write a program that produces the following shape:

########
 ######
  ####
   ##

*/

int main()
{
    int lower = 0;
    int upper = 8;
    int numSpaces = 0;
    for (int i = 0; i < 4; i++)
    {
        lower = i;
        upper = 8 - i;
        numSpaces = i;
        for (int i = 0; i < numSpaces; i++)
        {
            cout << " ";
        }
        for (int i = lower; i < upper; i++)
        {
            cout << "#";
        }
        cout << "\n";
    }
    cin.get();
    return 0;
}
