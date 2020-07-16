/*
ID: audrey.6
LANG: C++11
PROB: ariprog
*/
#include <algorithm>
#include <fstream>

int main()
{
    std::ifstream fin("ariprog.in");
    std::ofstream fout("ariprog.out");
    int N, M;
    fin >> N >> M;

    int bisquares[21047] = {}, n_bisquares = 0;
    bool is_bisquare[125001] = {};
    for (int p = 0; p <= M; ++p)
    {
        for (int q = p; q <= M; ++q)
        {
            if (!is_bisquare[p * p + q * q])
            {
                bisquares[n_bisquares++] = p * p + q * q;
                is_bisquare[p * p + q * q] = true;
            }
        }
    }
    std::sort(bisquares, bisquares + n_bisquares);

    bool has_sequence = false;
    for (int b = 1; b <= 2 * M * M / (N - 1); ++b)
    {
        for (int i = 0; i < n_bisquares; ++i)
        {
            int a = bisquares[i];
            bool valid = true;
            int t = a;
            for (int n = 1; n < N; ++n)
            {
                t += b;
                if (t > 2 * M * M || (t <= 2 * M * M && !is_bisquare[t]))
                {
                    valid = false;
                    break;
                }
            }
            if (valid)
            {
                fout << a << ' ' << b << std::endl;
                has_sequence = true;
            }
        }
    }
    if (!has_sequence)
    {
        fout << "NONE" << std::endl;
    }
    return 0;
}
