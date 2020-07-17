/*
ID: audrey.6
LANG: C++11
PROB: frac1
*/
#include <algorithm>
#include <fstream>

struct Frac
{
    int n, d;
    double q;
};

bool compare(Frac a, Frac b)
{
    return a.q < b.q;
}

int main()
{
    std::ifstream fin("frac1.in");
    std::ofstream fout("frac1.out");

    int N;
    fin >> N;

    bool not_frac[161][161] = {};
    int n_fracs = 0;
    Frac fracs[8000];

    for (int d = 2; d <= N; ++d)
    {
        for (int n = 1; n < d; ++n)
        {
            if (!not_frac[d][n])
            {
                fracs[n_fracs++] = {n, d, static_cast<double>(n) / d};
                for (int i = 2; i * d <= N; ++i)
                {
                    not_frac[i * d][i * n] = true;
                }
            }
        }
    }
    std::sort(fracs, fracs + n_fracs, compare);

    fout << 0 << '/' << 1 << std::endl;
    for (int i = 0; i < n_fracs; ++i)
    {
        fout << fracs[i].n << '/' << fracs[i].d << std::endl;
    }
    fout << 1 << '/' << 1 << std::endl;
    return 0;
}
