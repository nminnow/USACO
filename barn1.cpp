/*
ID: -
LANG: C++11
PROB: barn1
*/
#include <fstream>
#include <algorithm>

int main()
{
    std::ifstream fin("barn1.in");
    std::ofstream fout("barn1.out");

    int M, S, C;
    fin >> M >> S >> C;

    bool stalls[200] = {};
    for (int c = 0; c < C; ++c)
    {
        int n;
        fin >> n;
        stalls[n - 1] = true;
    }

    int first = 0;
    for (int s = 0; s < S; ++s)
    {
        if (stalls[s])
        {
            first = s;
            break;
        }
    }

    int last = first;
    for (int s = S - 1; s > first; --s)
    {
        if (stalls[s])
        {
            last = s;
            break;
        }
    }

    int gaps[200] = {}, gap = 0, n = 0, b = 1;
    bool on_board = true;
    for (int s = first + 1; s <= last; ++s)
    {
        if (stalls[s])
        {
            if (!on_board)
            {
                on_board = true;
                ++b;
                gaps[n] = gap;
                ++n;
                gap = 0;
            }
        }
        else
        {
            ++gap;
            if (on_board)
            {
                on_board = false;
            }
        }
    }

    int blocked = C;
    std::sort(gaps, gaps + n);
    for (int g = 0; g < b - M; ++g)
    {
        blocked += gaps[g];
    }

    fout << blocked << std::endl;
    return 0;
}
