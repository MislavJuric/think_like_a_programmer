#include <iostream>
#include <cmath>

using namespace std;

/*

    Or how about:

   ##
  ####
 ######
########
########
 ######
  ####
   ##


*/

int main()
{
    for (int i = 0; i < 8; i++)
    {
        int number_of_spaces = abs(i - 3) - (i / 4);
        int number_of_hash_marks = 8 - (number_of_spaces * 2);
        for (int i = 0; i < number_of_spaces; i++)
        {
            cout << " ";
        }
        for (int i = 0; i < number_of_hash_marks; i++)
        {
            cout << "#";
        }
        cout << "\n";
    }
    cin.get();
    return 0;
}
