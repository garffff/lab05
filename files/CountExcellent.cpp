#include "header.h"

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
