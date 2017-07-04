#include <iostream>

using namespace std;

//Write a function removeRecord that takes a pointer to a studentCollection and a student number and that removes the
// record with that student number from the collection.

struct listNode
{
    int studentNum;
    int grade;
    listNode* next;
};

typedef listNode* studentCollection;

void addRecord(studentCollection& sc, int stuNum, int gr)
{
    listNode* newNode = new listNode;
    newNode->studentNum = stuNum;
    newNode->grade = gr;
    newNode->next = sc;
    sc = newNode;
}

void removeRecord(studentCollection sc, int stuNum)
{
    studentCollection loopPointer = sc;
    studentCollection trail = NULL;
    while (loopPointer != NULL)
    {
        if ((loopPointer->studentNum) == stuNum)
        {
            studentCollection pointTo = loopPointer->next;
            delete loopPointer;
            loopPointer = NULL;
            trail->next = pointTo;
        }
        trail = loopPointer;
        loopPointer = loopPointer->next;
    }
}

double averageRecord(studentCollection sc)
{
    if (sc == 0) // empty list - could throw an exception though
    {
        return 0;
    }
    int count = 0;
    double sum = 0;
    listNode* loopPtr = sc; // couldn't we have used sc, because we are passing it by value?
    while (loopPtr != NULL)
    {
        count++;
        sum += loopPtr->grade;
        loopPtr = loopPtr->next;
    }
    return (sum / count);
}

void output(studentCollection sc)
{
    studentCollection loopPointer =  sc;
    while (loopPointer != NULL)
    {
        cout << loopPointer->studentNum << endl;
        loopPointer = loopPointer->next;
    }
}

int main()
{
    studentCollection sc;
    listNode* node1 = new listNode;
    node1->studentNum = 1001;
    node1->grade = 78;
    listNode* node2 = new listNode;
    node2->studentNum = 1012;
    node2->grade = 93;
    listNode* node3 = new listNode;
    node3->studentNum = 1076; node3->grade = 85;
    sc = node1;
    node1->next = node2;
    node2->next = node3;
    node3->next = NULL;
    node1 = node2 = node3 = NULL; // to clear things up and avoid potentital cross-linking problems
    addRecord(sc, 1274, 91);
    //double average = averageRecord(sc);
    output(sc);
    cout << "------------------------------" << endl;
    removeRecord(sc, 1001);
    output(sc);
    return 0;
}
