/*
ID: audrey.6
LANG: C++11
PROB: sprime
*/
#include <fstream>

std::ifstream fin("sprime.in");
std::ofstream fout("sprime.out");
int N;

bool is_prime(int x)
{
    for (int i = 2; i * i <= x; ++i)
    {
        if (!(x % i))
        {
            return false;
        }
    }
    return true;
}

void solve(int n, int b)
{
    if (n == N)
    {
        fout << b << std::endl;
        return;
    }

    for (int c : {1, 3, 7, 9})
    {
        if (is_prime(b * 10 + c))
        {
            solve(n + 1, b * 10 + c);
        }
    }
}

int main()
{
    fin >> N;

    solve(1, 2);
    solve(1, 3);
    solve(1, 5);
    solve(1, 7);

    return 0;
}
