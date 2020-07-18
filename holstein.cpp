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

bool search(int n, int m, State state)
{
    bool is_healthy = true;
    for (int v = 0; v < V; ++v)
        if (state.vitamins[v] < reqs[v])
            is_healthy = false;

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

    for (int g = 0; g < G; ++g)
        if (!state.scoops[g])
        {
            state.scoops[g] = true;
            for (int v = 0; v < V; ++v)
                state.vitamins[v] += feeds[g][v];

            if (search(n - 1, m, state))
                return true;

            state.scoops[g] = false;
            for (int v = 0; v < V; ++v)
                state.vitamins[v] -= feeds[g][v];
        }
    return false;
}

void id_search()
{
    for (int n = 1; n <= G; ++n)
        if (search(n, n, {}))
            return;
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

    id_search();
    return 0;
}
