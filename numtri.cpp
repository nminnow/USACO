/*
ID: audrey.6
LANG: C++11
PROB: numtri
*/
#include <fstream>

inline int max(int a, int b)
{
    return (a > b) ? a : b;
}

int main()
{
    std::ifstream fin("numtri.in");
    std::ofstream fout("numtri.out");

    int R;
    fin >> R;

    int nums[500500];
    for (int t = 0; t < R * (R + 1) / 2; ++t)
    {
        fin >> nums[t];
    }

    for (int row = R - 2; row >= 0; --row)
    {
        for (int col = 0; col <= row; ++col)
        {
            nums[row * (row + 1) / 2 + col] += max(
                nums[(row + 1) * (row + 2) / 2 + col], 
                nums[(row + 1) * (row + 2) / 2 + col + 1]);
        }
    }

    fout << nums[0] << std::endl;
    return 0;
}
