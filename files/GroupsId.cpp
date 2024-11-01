#include "header.h"

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
