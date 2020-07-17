/*
ID: audrey.6
LANG: C++
PROB: castle
*/
#include <fstream>

struct Unit
{
    bool south = false;
    bool east = false;
    bool north = false;
    bool west = false;

    int in_room = -2;
};

int M, N;
Unit units[50][50];
int n_rooms, max_room_size;
int rooms_size[50 * 50];

int optimal_size;
int optimal_n, optimal_m;
char optimal_direction;

void get_room()
{
    int n_visited, room_size = 0;
    do
    {
        n_visited = 0;
        for (int n = 0; n < N; ++n)
        {
            for (int m = 0; m < M; ++m)
            {
                if (units[n][m].in_room == -1)
                {
                    units[n][m].in_room = n_rooms - 1;
                    ++n_visited;
                    ++room_size;

                    if (n != N - 1 && !units[n][m].south && units[n + 1][m].in_room == -2)
                    {
                        units[n + 1][m].in_room = -1;
                    }
                    if (m != M - 1 && !units[n][m].east && units[n][m + 1].in_room == -2)
                    {
                        units[n][m + 1].in_room = -1;
                    }
                    if (n && !units[n][m].north && units[n - 1][m].in_room == -2)
                    {
                        units[n - 1][m].in_room = -1;
                    }
                    if (m && !units[n][m].west && units[n][m - 1].in_room == -2)
                    {
                        units[n][m - 1].in_room = -1;
                    }
                }
            }
        }
    }
    while (n_visited);

    if (room_size > max_room_size)
    {
        max_room_size = room_size;
    }
    rooms_size[n_rooms - 1] = room_size;
}

void get_rooms()
{
    for (int n = 0; n < N; ++n)
    {
        for (int m = 0; m < M; ++m)
        {
            if (units[n][m].in_room == -2)
            {
                ++n_rooms;
                units[n][m].in_room = -1;
                get_room();
            }
        }
    }
}

void get_optimal()
{
    for (int m = M - 1; m >= 0; --m)
    {
        for (int n = 0; n < N; ++n)
        {
            if (m != M - 1 && units[n][m].east && units[n][m].in_room != units[n][m + 1].in_room)
            {
                int size = rooms_size[units[n][m].in_room] + rooms_size[units[n][m + 1].in_room];
                if (size >= optimal_size)
                {
                    optimal_size = size;
                    optimal_n = n + 1;
                    optimal_m = m + 1;
                    optimal_direction = 'E';
                }
            }
            if (n && units[n][m].north && units[n][m].in_room != units[n - 1][m].in_room)
            {
                int size = rooms_size[units[n][m].in_room] + rooms_size[units[n - 1][m].in_room];
                if (size >= optimal_size)
                {
                    optimal_size = size;
                    optimal_n = n + 1;
                    optimal_m = m + 1;
                    optimal_direction = 'N';
                }
            }
        }
    }
}

int main()
{
    std::ifstream fin("castle.in");
    std::ofstream fout("castle.out");

    fin >> M >> N;
    for (int n = 0; n < N; ++n)
    {
        for (int m = 0; m < M; ++m)
        {
            int val;
            fin >> val;
            if (val >= 8)
            {
                units[n][m].south = true;
                val -= 8;
            }
            if (val >= 4)
            {
                units[n][m].east = true;
                val -= 4;
            }
            if (val >= 2)
            {
                units[n][m].north = true;
                val -= 2;
            }
            if (val == 1)
            {
                units[n][m].west = true;
            }
        }
    }

    get_rooms();
    fout << n_rooms << std::endl;
    fout << max_room_size << std::endl;

    get_optimal();
    fout << optimal_size << std::endl;
    fout << optimal_n << ' ' << optimal_m << ' ' << optimal_direction << std::endl;

    return 0;
}
