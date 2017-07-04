#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

// If you’ve learned about binary numbers and how to convert from decimal to binary and the reverse, try writing programs to do
// those conversions with unlimited length numbers (but you can assume the numbers are small enough to be stored in a
// standard C++ int).

int main()
{
    char choice;
    cout << "Enter d to convert from decimal to binary and b to convert from binary to decimal: ";
    cin >> choice;
    int number;
    switch (choice)
    {
           case 'd':
           {
               vector<int> digits;
               cout << "Enter a decimal number: " << endl;
               cin >> number;
               while (number > 0)
               {
                   digits.push_back(number % 2);
                   number /= 2;
               }
               for (int i = (digits.size() - 1); i >= 0; i--)
               {
                   cout << digits[i];
               }
               cout << endl;
           }
               break;
           case 'b':
           {
               cout << "Enter a binary number: " << endl;
               cin >> number;
               int decimal_equivalent = 0;
               double position = 0.0;
               while (number != 0)
               {
                   decimal_equivalent += (number % 10) * pow(2, position);
                   position++;
                   number /= 10;
               }
               cout << "Decimal equivalent is: " << decimal_equivalent << endl;
           }
               break;
           default:
               cout << "I don't know how to handle that input." << endl;
               break;
    }
    system("pause");
    return 0;
}
