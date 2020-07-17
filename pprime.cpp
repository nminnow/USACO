/*
ID: audrey.6
LANG: C++11
PROB: pprime
*/
#include <fstream>

bool is_prime(int n)
{
    for (int i = 3; i * i <= n; ++i)
    {
        if (!(n % i))
        {
            return false;
        }
    }
    return true;
}

int main()
{
    std::ifstream fin("pprime.in");
    std::ofstream fout("pprime.out");

    int A, B;
    fin >> A >> B;

    for (int a = 1; a < 10; a += 2)
    {
        const int n = a;
        if (is_prime(n) && n >= A && n <= B)
        {
            fout << n << std::endl;
        }
    }

    for (int a = 1; a < 10; a += 2)
    {
        const int n = a * 10 + a;
        if (is_prime(n) && n >= A && n <= B)
        {
            fout << n << std::endl;
        }
    }

    for (int a = 1; a < 10; a += 2)
    {
        for (int b = 0; b < 10; ++b)
        {
            const int n = a * 100 + b * 10 + a;
            if (is_prime(n) && n >= A && n <= B)
            {
                fout << n << std::endl;
            }
        }
    }

    for (int a = 1; a < 10; a += 2)
    {
        for (int b = 0; b < 10; ++b)
        {
            const int n = a * 1000 + b * 100 + b * 10 + a;
            if (is_prime(n) && n >= A && n <= B)
            {
                fout << n << std::endl;
            }
        }
    }

    for (int a = 1; a < 10; a += 2)
    {
        for (int b = 0; b < 10; ++b)
        {
            for (int c = 0; c < 10; ++c)
            {
                const int n = a * 10000 + b * 1000 + c * 100 + b * 10 + a;
                if (is_prime(n) && n >= A && n <= B)
                {
                    fout << n << std::endl;
                }
            }
        }
    }

    for (int a = 1; a < 10; a += 2)
    {
        for (int b = 0; b < 10; ++b)
        {
            for (int c = 0; c < 10; ++c)
            {
                const int n = a * 100000 + b * 10000 + c * 1000 + c * 100 + b * 10 + a;
                if (is_prime(n) && n >= A && n <= B)
                {
                    fout << n << std::endl;
                }
            }
        }
    }

    for (int a = 1; a < 10; a += 2)
    {
        for (int b = 0; b < 10; ++b)
        {
            for (int c = 0; c < 10; ++c)
            {
                for (int d = 0; d < 10; ++d)
                {
                    const int n = a * 1000000 + b * 100000 + c * 10000 + d * 1000 + c * 100 + b * 10 + a;
                    if (is_prime(n) && n >= A && n <= B)
                    {
                        fout << n << std::endl;
                    }
                }
            }
        }
    }

    for (int a = 1; a < 10; a += 2)
    {
        for (int b = 0; b < 10; ++b)
        {
            for (int c = 0; c < 10; ++c)
            {
                for (int d = 0; d < 10; ++d)
                {
                    const int n = a * 10000000 + b * 1000000 + c * 100000 + d * 10000 + d * 1000 + c * 100 + b * 10 + a;
                    if (is_prime(n) && n >= A && n <= B)
                    {
                        fout << n << std::endl;
                    }
                }
            }
        }
    }

    return 0;
}
