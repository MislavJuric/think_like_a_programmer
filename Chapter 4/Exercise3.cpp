#include <iostream>

using namespace std;

//For our dynamically allocated strings, create a function replaceString that takes three parameters, each of type arrayString:
// source, target, and replaceText. The function replaces every occurrence of target in source with replaceText. For example,
// if source points to an array containing abcdabee, target points to ab, and replaceText points to xyz, then when the function
// ends, source should point to an array containing xyzcdxyzee.

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

void replaceString (arrayString& source, arrayString target, arrayString replaceText) // only works for 1 character
{
    int i = 0;
    while (source[i] != 0)
    {
        if (source[i] == target[0])
        {
            source[i] = replaceText[0];
        }
        i++;
    }
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
    arrayString target = new char[1];
    target[0] = 't';
    arrayString replaceText = new char[1];
    replaceText[0] = 'o';
    replaceString(a, target, replaceText);
    cout << a << endl;
}
