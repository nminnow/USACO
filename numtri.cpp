/*
ID: audrey.6
LANG: C++11
PROB: numtri
*/
#include <fstream>

int R;
int max_sum;
int nums[500500];

void step(int sum, int row, int col)
{
    if (row == R)
    {
        if (sum > max_sum)
        {
            max_sum = sum;
        }
        return;
    }

    sum += nums[row * (row + 1) / 2 + col];

    step(sum, row + 1, col);
    step(sum, row + 1, col + 1);
}

int main()
{
    std::ifstream fin("numtri.in");
    std::ofstream fout("numtri.out");
    fin >> R;
    for (int t = 0; t < R * (R + 1) / 2; ++t)
    {
        fin >> nums[t];
    }

    step(0, 0, 0);

    fout << max_sum << std::endl;
    return 0;
}
