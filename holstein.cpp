/*
ID: audrey.6
LANG: C++11
PROB: holstein
*/
#include <fstream>

struct State
{
    bool scoops[15] = {};
    int vitamins[25] = {};
};

std::ifstream fin("holstein.in");
std::ofstream fout("holstein.out");
int V, G;
int reqs[25], feeds[15][25];

bool search(int n, int m, State state, int f)
{
    bool is_healthy = true;
    for (int v = 0; v < V; ++v)
        if (state.vitamins[v] < reqs[v])
        {
            is_healthy = false;
            break;
        }
    if (is_healthy)
    {
        fout << m;
        for (int i = 0; i < G; ++i)
            if (state.scoops[i])
                fout << ' ' << i + 1;
        fout << std::endl;
        return true;
    }

    if (!n)
        return false;

    for (int g = f + 1; g < G; ++g)
        if (!state.scoops[g])
        {
            state.scoops[g] = true;
            for (int v = 0; v < V; ++v)
                state.vitamins[v] += feeds[g][v];

            if (search(n - 1, m, state, g))
                return true;

            state.scoops[g] = false;
            for (int v = 0; v < V; ++v)
                state.vitamins[v] -= feeds[g][v];
        }
    return false;
}

int main()
{
    fin >> V;
    for (int v = 0; v < V; ++v)
        fin >> reqs[v];
    
    fin >> G;
    for (int i = 0; i < G; ++i)
        for (int v = 0; v < V; ++v)
            fin >> feeds[i][v];

    for (int n = 1; n <= G; ++n)
        if (search(n, n, {}, -1))
            return 0;
}
