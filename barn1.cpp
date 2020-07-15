/*
ID: -
LANG: C++11
PROB: barn1
*/
#include <fstream>

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

    int boards = C, blocked = C;
    int min_beg = 0, min_end = 0;
    while (boards > M)
    {
        for (int t = min_beg; t < min_end; ++t)
        {
            stalls[t] = true;
        }

        blocked = 0;
        boards = 0;
        bool on_board = false;
        int min_gap = S, gap = 0, beg = 0;

        for (int s = 0; s < S; ++s)
        {
            if (stalls[s])
            {
                ++blocked;
                if (!on_board)
                {
                    on_board = true;
                    ++boards;
                    if (min_gap > gap && gap != 0 && (stalls[0] ? true : beg))
                    {
                        min_gap = gap;
                        min_beg = beg;
                        min_end = s;
                    }
                    gap = 0;
                }
            }
            else
            {
                ++gap;
                if (on_board)
                {
                    on_board = false;
                    beg = s;
                }
            }
        }
    }

    fout << blocked << std::endl;
    return 0;
}
