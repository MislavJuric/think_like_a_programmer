#include <iostream>
#include <string>

using namespace std;

//Let’s try implementing a class using the basic framework. Consider a class to store the data for an automobile.
// We’ll have three pieces of data: a manufacturer name and model name, both strings, and a model year, an integer.
// Create a class with get/set methods for each data member. Make sure you make good decisions concerning details like
// member names. It’s not important that you follow my particular naming convention. What’s important is that you think
// about the choices you make and are consistent in your decisions.

//For our automobile class from the previous exercise, add a support method that returns a complete description of the
// automobile object as a formatted string, such as, '1957 Chevrolet Impala'. Add a second support method that returns
// the age of the automobile in years.

class Automobile
{
    public:
        int getAge() const;
        string getName() const;
        string getModel() const;
        Automobile(int newAge, string newName, string newModel);
    private:
        int age;
        string name;
        string model;
};

Automobile::Automobile(int newAge, string newName, string newModel)
{
    age = newAge;
    name = newName;
    model = newModel;
}

string description(const Automobile& a)
{
    string toReturn = to_string(a.getAge()) + " " + a.getName() + " " + a.getModel(); // compiler error here
    return toReturn;
}

int automobileAge(const Automobile& a, int current_year)
{
    return current_year - a.getAge();
}

int main()
{
    Automobile a{1957, "Chervolet", "Impala"};
    return 0;
}
