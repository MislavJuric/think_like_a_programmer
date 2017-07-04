#include <iostream>

using namespace std;

//Change the implementation of our strings such that location[0] in the array stores the size of the array (and therefore
// location[1] stores the first actual character in the string), rather than using a null-character terminator. Implement each
// of the three functions, append, concatenate, and charactertAt, taking advantage of the stored size information whenever
// possible. Because we’ll no longer be using the null-termination convention expected by the standard output stream,
// you’ll need to write your own output function that loops through its string parameter, displaying the characters.

typedef char* arrayString;

char characterAt(arrayString s, int position)
{
    if (position == 0)
    {
        cout << "At 0 position there's only the string length." << endl;
        return 0;
    }
    if (position > s[0]) // mogu se i throwati exceptioni
    {
        cout << "Your position is out of range" << endl;
        return 0;
    }
    return s[position];
}

void append(arrayString& s, char c)
{
    /*
    int oldLength = length(s);
    arrayString newS = new char[oldLength + 2];
    for (int i = 0; i < oldLength; i++)
    {
        newS[i] = s[i];
    }
    newS[oldLength] = c;
    newS[oldLength + 1] = 0;
    delete[] s;
    s = newS;
    */
    arrayString newS = new char[s[0] + 2];
    newS[0] = s[0] + 1;
    for (int i = 0; i < s[0]; i++)
    {
        newS[i + 1] = s[1 + i];
    }
    newS[s[0] + 1] = c; // why no * here?
    delete[] s;
    s = newS;
}

void concatenate(arrayString& s1, arrayString s2)
{
    int s1Length = s1[0];
    int s2Length = s2[0];
    arrayString newS = new char[s1Length + s2Length + 1];
    newS[0] = s1Length + s2Length;
    for (int i = 0; i < s1Length; i++)
    {
        newS[1 + i] = s1[1 + i];
    }
    for (int i = 0; i < s2Length; i++)
    {
        newS[s1Length + i + 1] = s2[i + 1];
    }
    delete[] s1;
    s1 = newS;
}

void output(arrayString s)
{
    int length = s[0];
    for (int i = 1; i <= length; i++)
    {
        cout << s[i];
    }
    cout << endl;
}

/* void concatenate(arrayString& s1, arrayString s2)
{
    int s1Length = length(s1);
    int s2Length = length(s2);
    arrayString newS = new char[s1Length + s2Length + 1];
    for (int i = 0; i < s1Length; i++)
    {
        newS[i] = s1[i];
    }
    for (int i = 0; i < s2Length; i++) // obratiti pozornost na ovo
    {
        newS[s1Length + i] = s2[i];
    }
    newS[s1Length + s2Length + 1] = 0;
    delete[] s1;
    s1 = newS;
} */

int main()
{
    // append test
    /*
    arrayString a = new char[5];
    a[0] = 't';
    a[1] = 'e';
    a[2] = 's';
    a[3] = 't';
    a[4] = 0;
    append(a, '!');
    cout << a << endl;
    */
    /*
    arrayString a = new char[5];
    a[0] = 4; a[1] = 't'; a[2] = 'e'; a[3] = 's'; a[4] = 't';
    append(a, '!');
    cout << a << endl;
    */
    arrayString a = new char[5];
    a[0] = 4; a[1] = 't'; a[2] = 'e'; a[3] = 's'; a[4] = 't';
    arrayString b = new char[4];
    b[0] = 3; b[1] = 'b'; b[2] = 'e'; b[3] = 'd';
    concatenate(a, b);
    output(a);
    append(a, '!');
    output(a);
    return 0;
}
