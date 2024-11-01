#include <iostream>
#include <cmath>
#include <string>
#include <vector>
using namespace std;

struct Student
{
  string Name;
  string GroupId;
  vector<unsigned> Ratings;
  vector<string> Subjects;
};

struct Group
{
    string Id;
    vector<Student> Students;
};

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

void SortByName(vector<Student>&vec)
{
    for(int i = 0; i < vec.size(); ++i)
    {
        for(int j = 1; j < vec.size(); ++j)
        {
            if(vec[j].Name < vec[j - 1].Name)
            {
                auto b = vec[j - 1];
                vec[j - 1] = vec[j];
                vec[j] = b;

            }
        }
    }
}

void SortByRating(vector<Student>&vec)
{
    vector<float> means(vec.size());
    for(int i = 0; i < vec.size(); ++i)
    {
        float sum = 0;
        for(int k = 0; k < vec[i].Ratings.size(); ++k)
        {
            sum += vec[i].Ratings[k];
        }
        means[i] = (float) sum / vec[i].Ratings.size();
    }
    for(int a = 0; a < vec.size(); ++a)
    {
        for(int j = 1; j < means.size(); ++j)
        {
            if(means[j - 1] > means[j])
            {
                auto b = vec[j];
                vec[j] = vec[j - 1];
                vec[j - 1] = b;
                auto b1 = means[j];
                means[j] = means[j - 1];
                means[j - 1] = b1;
            }
        }
    }
}

size_t CountTwoness(const vector<Student>&vec)
{
    size_t c = 0;
    for(int i = 0; i < vec.size(); ++i)
    {
        for(int j = 0; j < vec[i].Ratings.size(); ++j)
        {
            if(vec[i].Ratings[j] == 2)
            {
                c++;
                j = vec[i].Ratings.size();
            }
        }
    }
    return c;
}

size_t CountExcellent(const vector<Student>&vec)
{
    size_t c = 0;
    for(int i = 0; i < vec.size(); ++i)
    {
        for(int j = 0; j < vec[i].Ratings.size(); ++j)
        {
            if(vec[i].Ratings[j] != 5) j = vec[i].Ratings.size();
            if(j == vec[i].Ratings.size() - 1) c++;
        }
    }
    return c;
}

vector<Student> VectorMathExcellent(const vector<Student>&vec)
{
    vector<Student> nado;
    for(int i = 0; i < vec.size(); ++i)
    {
        for(int j = 0; j < vec[i].Ratings.size(); ++j)
        {
            if(vec[i].Ratings[j] == 5 and vec[i].Subjects[j] == "Math") nado.push_back(vec[i]);
        }
    }
    return nado;
}

vector<string> GroupsId(const vector<Student>&vec)
{
    vector<string> g;
    for(int i = 0; i < vec.size(); ++i)
    {
        g.push_back(vec[i].GroupId);
        for(int j = 0; j < g.size() - 1; ++j)
        {
            if(g[j] == g[g.size() - 1]) g.pop_back();
        }
    }
    return g;
}

vector<Group> Groups(const vector<Student>&vec)
{
    vector<Group> gr(GroupsId(vec).size());
    for(int i = 0; i < GroupsId(vec).size(); ++i)
    {
        gr[i].Id = GroupsId(vec)[i];
        for(int j = 0; j < vec.size(); ++j)
        {
            if(vec[j].GroupId == gr[i].Id)
            {
                gr[i].Students.push_back(vec[j]);
            }
        }
    }
    return gr;
}

int main()
{
    vector<Student> students(3);
    students[0] = {"Alex", "odin", {3, 4}, {"Math", "Astronomy"}};
    students[1] = {"Sam", "odin", {5, 5}, {"English", "Math"}};
    students[2] = {"Tammy", "odin", {2, 4}, {"Astronomy", "Literature"}};
    vector<Group> grrr = Groups(students);
    for(int i = 0; i < grrr.size(); ++i)
    {
        cout << grrr[i].Id << ":" << endl;
        PrintStudents(grrr[i].Students);
    }
    return 0;
}
