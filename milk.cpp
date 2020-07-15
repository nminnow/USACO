/*
ID: -
LANG: C++11
PROB: milk
*/
#include <fstream>

int main()
{
    std::ifstream fin("milk.in");
    std::ofstream fout("milk.out");

    int N, M;
    fin >> N >> M;

    int amounts[1001] = {};
    for (int i = 0; i < M; ++i)
    {
        int price, amount;
        fin >> price >> amount;
        amounts[price] += amount;
    }

    int cost = 0, remaining = N;
    for (int price = 0; price < 1001; ++price)
    {
        if (amounts[price] <= remaining)
        {
            cost += price * amounts[price];
            remaining -= amounts[price];
        }
        else
        {
            cost += price * remaining;
            break;
        }
    }

    fout << cost << std::endl;
    return 0;
}
