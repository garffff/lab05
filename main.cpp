#include "header.h"
#include <vector>
#include <string>
#include<iostream>
using namespace std;

void PrintStudents(vector<Student>&students)
{
    for(int i = 0; i < students.size(); ++i)
    {
        cout << students[i].Name << ", " << students[i].GroupId << ", ";
        for(int j = 0; j < students[i].Ratings.size(); ++j)
        {
            cout << students[i].Ratings[j] << " ";
        }
        for(int k = 0; k < students[i].Subjects.size(); ++k)
        {
            cout << students[i].Subjects[k] << " ";
        }
        cout << endl;
    }
}

int main()
{
    vector<Student> students(3);
    students[0] = {"Alex", "odin", {3, 4}, {"Math", "Astronomy"}};
    students[1] = {"Sam", "dva", {5, 5}, {"English", "Math"}};
    students[2] = {"Tammy", "odin", {2, 4}, {"Astronomy", "Literature"}};
    SortByName(students);
    PrintStudents(students);
    return 0;
}
