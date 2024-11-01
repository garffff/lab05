#include "header.h"

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
