/*
ID: audrey.6
LANG: C++11
PROB: holstein
*/
#include <fstream>
#include <vector>

struct State
{
    bool scoops[15] = {};
    int vitamins[25] = {};
};

int V, G;
int reqs[25], feeds[15][25];
std::vector<State> states, prv_states = {{}};
int min_n = 15;

bool is_healthy(int n, const State & prv_state, int g)
{
    State state = prv_state;
    state.scoops[g] = true;
    for (int v = 0; v < V; ++v)
        state.vitamins[v] += feeds[g][v];
    states.push_back(state);

    for (int v = 0; v < V; ++v)
        if (state.vitamins[v] < reqs[v])
            return false;

    min_n = n;
    return true;
}

void search()
{
    for (int n = 0; n < G; ++n)
    {
        for (State prv_state : prv_states)
            for (int g = 0; g < G; ++g)
                if (!prv_state.scoops[g] && is_healthy(n, prv_state, g))
                    return;
        prv_states = states;
        states = {};
    }
}

int main()
{
    std::ifstream fin("holstein.in");
    std::ofstream fout("holstein.out");

    fin >> V;
    for (int v = 0; v < V; ++v)
        fin >> reqs[v];
    
    fin >> G;
    for (int i = 0; i < G; ++i)
        for (int v = 0; v < V; ++v)
            fin >> feeds[i][v];

    search();

    fout << min_n + 1;
    for (int i = 0; i < G; ++i)
        if (states.back().scoops[i])
            fout << ' ' << i + 1;
    fout << std::endl;
    return 0;
}
