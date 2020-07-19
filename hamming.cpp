/*
ID: audrey.6
LANG: C++11
PROB: hamming
*/
#include <bitset>
#include <fstream>
#include <iostream>

std::ifstream fin("hamming.in");
std::ofstream fout("hamming.out");
int N, B, D;
int words[64];

int get_dist(int a, int b)
{
    std::bitset<8> diff(a ^ b);
    int dist = 0;
    for (int b = 0; b < B; ++b)
        if (diff[b])
            ++dist;
    return dist;
}

int main()
{
    fin >> N >> B >> D;

    int n = 1;
    while (n < N)
    {
        int i = words[n - 1] + 1;
        while (true)
        {
            bool valid = true;
            for (int w = 0; w < n; ++w)
                if (get_dist(i, words[w]) < D)
                {
                    valid = false;
                    break;
                }
            if (valid)
            {
                words[n] = i;
                break;
            }
            ++i;
        }
        ++n;
    }

    int l = 0;
    for (int i = 0; i < N; ++i)
    {
        fout << words[i];
        if (!(++l % 10))
            fout << std::endl;
        else if (i != N - 1)
            fout << ' ';
    }
    if (l % 10)
        fout << std::endl;
    return 0;
}
