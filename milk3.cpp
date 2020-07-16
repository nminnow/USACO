/*
ID: audrey.6
LANG: C++11
PROB: milk3
*/
#include <fstream>

bool is_rem[21];
int caps[3];
bool is_seen[21][21][21];

void pour(int f, int t, const int (& bkts_ref)[3])
{
    int bkts[3] = {bkts_ref[0], bkts_ref[1], bkts_ref[2]};

    int amt;
    if (bkts[f] + bkts[t] < caps[t])
    {
        amt = bkts[f];
    }
    else
    {
        amt = caps[t] - bkts[t];
    }
    bkts[f] -= amt;
    bkts[t] += amt;

    if (is_seen[bkts[0]][bkts[1]][bkts[2]])
    {
        return;
    }
    is_seen[bkts[0]][bkts[1]][bkts[2]] = true;

    if (!bkts[0])
    {
        is_rem[bkts[2]] = true;
    }

    for (int i = 0; i < 3; ++i)
    {
        if (bkts[i])
        {
            for (int j = 0; j < 3; ++j)
            {
                if (bkts[j] != caps[j])
                {
                    pour(i, j, bkts);
                }
            }
        }
    }
}

int main()
{
    std::ifstream fin("milk3.in");
    std::ofstream fout("milk3.out");
    fin >> caps[0] >> caps[1] >> caps[2];

    pour(2, 0, {0, 0, caps[2]});
    pour(2, 1, {0, 0, caps[2]});

    bool first = true;
    for (int i = 0; i < 21; ++i)
    {
        if (is_rem[i])
        {
            if (first)
            {
                fout << i;
                first = false;
            }
            else
            {
                fout << ' ' << i;
            }
        }
    }
    fout << std::endl;
    return 0;
}
