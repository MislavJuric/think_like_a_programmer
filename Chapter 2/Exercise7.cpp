#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

// Have you learned about hexadecimal? Try writing a program that lets the user specify an input in binary, decimal, or
// hexadecimal, and output in any of the three.

int ConvertToDecimal(vector<int> &number, int base)
{
    int convertedNumber = 0;
    float exponent = 0;
    for (int i = (number.size() - 1); i >= 0; i--)
    {
        convertedNumber += (number[i] * pow(base, exponent));
        exponent++;
    }
    return convertedNumber;
}

vector<int> ConvertToBase(int number, int base)
{
    vector<int> final_number;
    while (number != 0)
    {
        final_number.push_back(number % base);
        number = number / base;
    }
    return final_number;
}

int main()
{
    char digit;
    vector<int> number;
    int digit_base = 0;
    int number_base = 0;
    cout << "Enter the number: ";
    digit = cin.get();
    while (digit != 10)
    {
        if (digit < 57)
        {
            number.push_back(digit - 48);
        }
        if ((digit >= 65) && (digit <= 70))
        {
            number.push_back(digit - 55);
        }
        if ((digit == '0') || (digit == '1'))
        {
            digit_base = 2;
            if (digit_base > number_base)
            {
                number_base = digit_base;
            }
        }
        if ((digit >= '2') && (digit <= '9'))
        {
            digit_base = 10;
            if (digit_base > number_base)
            {
                number_base = digit_base;
            }
        }
        if ((digit >= 'A') && (digit <= 'F'))
        {
            digit_base = 16;
            if (digit_base > number_base)
            {
                number_base = digit_base;
            }
        }
        digit = cin.get();
    }
    int converted_number = ConvertToDecimal(number, number_base);
    int base_to_convert_to;
    cout << "Input which base you want to convert to: ";
    cin >> base_to_convert_to;
    cout << endl;
    vector<int> final_number = ConvertToBase(converted_number, base_to_convert_to);
    cout << "Your final number is: ";
    for (int i = (final_number.size() - 1); i >= 0; i--)
    {
        if (final_number[i] == 10)
        {
            cout << 'A';
            continue;
        }
        if (final_number[i] == 11)
        {
            cout << 'A';
            continue;
        }
        if (final_number[i] == 12)
        {
            cout << 'B';
            continue;
        }
        if (final_number[i] == 13)
        {
            cout << 'C';
            continue;
        }
        if (final_number[i] == 14)
        {
            cout << 'D';
            continue;
        }
        if (final_number[i] == 15)
        {
            cout << 'E';
            continue;
        }
        cout << final_number[i];
    }
    cout << endl;
    return 0;
}
