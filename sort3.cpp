/*
ID: audrey.6
LANG: C++11
PROB: sort3
*/
#include <fstream>

int main()
{
    std::ifstream fin("sort3.in");
    std::ofstream fout("sort3.out");

    int N;
    fin >> N;

    int nums[1000];
    int a = 0, b = 0;
    for (int i = 0; i < N; ++i)
    {
        fin >> nums[i];
        if (nums[i] == 1)
            ++a;
        else if (nums[i] == 2)
            ++b;
    }

    int n = 0, m = 0, v = 0, w = 0;
    for (int i = 0; i < a; ++i)
        if (nums[i] == 2)
            ++n;
        else if (nums[i] == 3)
            ++m;
    for (int i = a; i < a + b; ++i)
        if (nums[i] == 1)
            ++v;
        else if (nums[i] == 3)
            ++n;
    for (int i = a + b; i < N; ++i)
        if (nums[i] == 1)
            ++w;
        else if (nums[i] == 2)
            ++v;

    int swap = 0;
    while (m && w)
    {
        ++swap;
        --m;
        --w;
    }
    while (n && v)
    {
        ++swap;
        --n;
        --v;
    }
    while (n > 1 && w)
    {
        swap += 2;
        n -= 2;
        --w;
    }
    while (m && v > 1)
    {
        swap += 2;
        --m;
        v -= 2;
    }

    fout << swap << std::endl;
    return 0;
}
