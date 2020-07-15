/*
ID: -
LANG: C++11
PROB: skidesign
*/
#include <fstream>

int main()
{
    std::ifstream fin("skidesign.in");
    std::ofstream fout("skidesign.out");

    int n;
    fin >> n;
    int hills[1000];
    for (int i = 0; i < n; ++i)
    {
        fin >> hills[i];
    }

    int min_cost = 10000000;
    for (int i = 0; i <= 100 - 17; ++i)
    {
        int cost = 0;
        for (int h = 0; h < n; ++h)
        {
            if (hills[h] < i)
            {
                cost += (i - hills[h]) * (i - hills[h]);
            }
            else if (hills[h] > i + 17)
            {
                cost += (hills[h] - (i + 17)) * (hills[h] - (i + 17));
            }
        }
        if (cost < min_cost)
        {
            min_cost = cost;
        }
    }

    fout << min_cost << std::endl;
    return 0;
}
