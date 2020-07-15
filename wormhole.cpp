/*
ID: audrey.6
LANG: C++11
PROB: wormhole
*/
#include <algorithm>
#include <fstream>

struct Hole
{
    int x, y, next = -1;
    Hole *pair = nullptr;
};

inline bool compare(const Hole &h1, const Hole &h2)
{
    return h1.x < h2.x;
}

int N;
Hole holes[12];

bool start_has_cycle(int start)
{
    bool route[12] = {};
    int i = start;
    while (!route[i])
    {
        route[i] = true;
        i = holes[i].pair->next;
        if (i == -1)
        {
            return false;
        }
    }
    return true;
}

bool pairing_has_cycle()
{
    for (int start = 0; start < N; ++start)
    {
        if (start_has_cycle(start))
        {
            return true;
        }
    }
    return false;
}

int solve()
{
    int i = 0, total = 0;
    for (; i < N; ++i)
    {
        if (!holes[i].pair)
        {
            break;
        }
    }

    if (i == N)
    {
        if (pairing_has_cycle())
        {
            return 1;
        }
        else
        {
            return 0;
        }
    }

    for (int j = i + 1; j < N; ++j)
    {
        if (!holes[j].pair)
        {
            holes[i].pair = &holes[j];
            holes[j].pair = &holes[i];
            total += solve();
            holes[i].pair = nullptr;
            holes[j].pair = nullptr;
        }
    }
    return total;
}

int main()
{
    std::ifstream fin("wormhole.in");
    std::ofstream fout("wormhole.out");

    fin >> N;
    for (int h = 0; h < N; ++h)
    {
        fin >> holes[h].x >> holes[h].y;
    }
    std::sort(holes, holes + N, compare);

    for (int h = 0; h < N; ++h)
    {
        for (int i = h + 1; i < N; ++i)
        {
            if (holes[i].y == holes[h].y)
            {
                holes[h].next = i;
                break;
            }
        }
    }

    fout << solve() << std::endl;
    return 0;
}
