#include <iostream>
#include <cstdlib>
#include <cmath>

/*
    Here’s an especially tricky one:

    #            #
     ##        ##
      ###    ###
       ########
       ########
      ###    ###
     ##        ##
    #            #
*/

using namespace std;

int main()
{
    int leading_spaces;
    int number_of_symbols_left;
    int spaces_in_the_middle;
    int number_of_symbols_right;
    for (int i = 0; i < 8; i++)
    {
        int output_row = 3 - abs(3 - i + (i / 4));
        leading_spaces = output_row;
        number_of_symbols_left = 1 + output_row;
        spaces_in_the_middle = 12 - (output_row * 4);
        number_of_symbols_right = 1 + output_row;
        for (int i = 0; i < leading_spaces; i++)
        {
            cout << " ";
        }
        for (int i = 0; i < number_of_symbols_left; i++)
        {
            cout << "#";
        }
        for (int i = 0; i < spaces_in_the_middle; i++)
        {
            cout << " ";
        }
        for (int i = 0; i < number_of_symbols_right; i++)
        {
            cout << "#";
        }
        for (int i = 0; i < leading_spaces; i++)
        {
            cout << " ";
        }
        cout << "\n";
    }
    /* for (int i = 0; i < 4; i++)
    {
        leading_spaces = 0 + i;
        number_of_symbols_left = 1 + i;
        spaces_in_the_middle = 12 - (i * 4);
        number_of_symbols_right = 1 + i;
        for (int i = 0; i < leading_spaces; i++)
        {
            cout << " ";
        }
        for (int i = 0; i < number_of_symbols_left; i++)
        {
            cout << "#";
        }
        for (int i = 0; i < spaces_in_the_middle; i++)
        {
            cout << " ";
        }
        for (int i = 0; i < number_of_symbols_right; i++)
        {
            cout << "#";
        }
        for (int i = 0; i < leading_spaces; i++)
        {
            cout << " ";
        }
        cout << "\n";
    }
    for (int i = 3; i >= 0; i--)
    {
        leading_spaces = i;
        number_of_symbols_left = 1 + i;
        spaces_in_the_middle = 12 - (i * 4);
        number_of_symbols_right = 1 + i;
        for (int i = 0; i < leading_spaces; i++)
        {
            cout << " ";
        }
        for (int i = 0; i < number_of_symbols_left; i++)
        {
            cout << "#";
        }
        for (int i = 0; i < spaces_in_the_middle; i++)
        {
            cout << " ";
        }
        for (int i = 0; i < number_of_symbols_right; i++)
        {
            cout << "#";
        }
        for (int i = 0; i < leading_spaces; i++)
        {
            cout << " ";
        }
        cout << "\n";
    } */
    system("pause");
    return 0;
}
