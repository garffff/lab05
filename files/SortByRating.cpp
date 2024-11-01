#include "header.h"

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
