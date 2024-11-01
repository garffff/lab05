#include "header.h"

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
