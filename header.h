#include<string>
#include<vector>
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

void SortByName(std::vector<Student>&);
void SortByRating(std::vector<Student>&);
size_t CountTwoness(const std::vector<Student>&);
size_t CountExcellent(const std::vector<Student>&);
std::vector<Student> VectorMathExcellent(const std::vector<Student>&);
std::vector<std::string> GroupsId(const std::vector<Student>&);
std::vector<Group> Groups(const std::vector<Student>&);
