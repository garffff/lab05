#include "header.h"

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
