#include "header.h"

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
