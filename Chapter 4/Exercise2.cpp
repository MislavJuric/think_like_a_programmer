#include <iostream>

using namespace std;

//For our dynamically allocated strings, create a function substring that takes three parameters: an arrayString,
// a starting position integer, and an integer length of characters. The function returns a pointer to a new dynamically
// allocated string array. This string array contains the characters in the original string, starting at the specified
// position for the specified length. The original string is unaffected by the operation. So if the original string was
// abcdefg, the position was 3, and the length was 4, then the new string would contain cdef.

typedef char* arrayString;

char characterAt(arrayString s, int position)
{
    return s[position];
}

int length(arrayString s)
{
    int count = 0;
    while (s[count] != 0)
    {
        count++;
    }
    return count;
}

void append(arrayString& s, char c)
{
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
}

void concatenate(arrayString& s1, arrayString s2)
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
}

arrayString substring(arrayString s, int startPosition, int length)
{

    arrayString subS = new char[length];
    for (int i = 0; i < length; i++)
    {
        subS[i] = s[startPosition + i];
    }
    return subS;
}

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
    arrayString a = new char[5];
    a[0] = 't'; a[1] = 'e'; a[2] = 's'; a[3] = 't'; a[4] =  0;
    arrayString b = substring(a, 1, 2);
    cout << b << endl;
    return 0;
}
