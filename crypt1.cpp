/*
ID: -
LANG: C++11
PROB: crypt1
*/
#include <fstream>

bool digits[10];

bool is_good(int i)
{
    while (i)
    {
        if (!digits[i % 10])
        {
            return false;
        }
        i /= 10;
    }
    return true;
}

bool is_good(int i, int d)
{
    while (i)
    {
        if (!digits[i % 10])
        {
            return false;
        }
        i /= 10;
        --d;
    }

    if (d)
    {
        return false;
    }
    else
    {
        return true;
    }
}

int main()
{
    std::ifstream fin("crypt1.in");
    std::ofstream fout("crypt1.out");

    int N;
    fin >> N;
    for (int d = 0; d < N; ++d)
    {
        int digit;
        fin >> digit;
        digits[digit] = true;
    }

    int sol = 0;
    for (int p = 100; p < 1000; ++p)
    {
        if (is_good(p))
        {
            for (int q = 10; q < 100; ++q)
            {
                if (is_good(q))
                {
                    int a = q / 10, b = q % 10;
                    if (is_good(a * p, 3) && is_good(b * p, 3) && is_good(q * p, 4))
                    {
                        ++sol;
                    }
                }
            }
        }
    }

    fout << sol << std::endl;
    return 0;
}
