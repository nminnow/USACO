/*
ID: -
LANG: C++11
PROB: combo
*/
#include <fstream>

int N;

inline bool int_tol(int i, int k)
{
    return abs(i - k) < 3 || abs(i - k) > N - 3;
}

inline bool all_int_tol(int a, int b, int c, int (& key)[3])
{
    return int_tol(a, key[0]) && int_tol(b, key[1]) && int_tol(c, key[2]);
}

int main()
{
    std::ifstream fin("combo.in");
    std::ofstream fout("combo.out");

    fin >> N;
    int fkey[3], mkey[3];
    for (int i = 0; i < 3; ++i)
    {
        fin >> fkey[i];
    }
    for (int i = 0; i < 3; ++i)
    {
        fin >> mkey[i];
    }

    int combos = 0;
    for (int a = 1; a <= N; ++a)
    {
        for (int b = 1; b <= N; ++b)
        {
            for (int c = 1; c <= N; ++c)
            {
                if (all_int_tol(a, b, c, fkey) || all_int_tol(a, b, c, mkey))
                {
                    ++combos;
                }
            }
        }
    }

    fout << combos << std::endl;
    return 0;
}
