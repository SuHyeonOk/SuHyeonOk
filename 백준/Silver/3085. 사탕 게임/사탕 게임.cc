#include <iostream>
#include <algorithm>
using namespace std;

int N;
char candy[50][50];

int CountFunction()
{
    int Max = 0, Count = 1;
    
    // 행
    int Index = 0;
    for (int y = 0; y < N; ++y)
    {
        for (int x = 0; x < N - 1; ++x)
        {
            if (0 == Index)
            {
                Index = x;
            }

            if (candy[y][Index] == candy[y][x + 1])
            {
                ++Count;
            }
            else
            {
                Max = max(Max, Count);
                Index = 0;
                Count = 1;
                continue;
            }
        }

        Max = max(Max, Count);
        Count = 1;
        Index = 0;
    }

    // 열
    for (int y = 0; y < N; ++y)
    {
        for (int x = 0; x < N - 1; ++x)
        {
            if (candy[x][y] == candy[x + 1][y])
            {
                ++Count;
            }
            else
            {
                Max = max(Max, Count);
                Count = 1;
                continue;
            }
        }

        Max = max(Max, Count);
        Count = 1;
    }

    return Max;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> N;

    for (int y = 0; y < N; ++y)
    {
        for (int x = 0; x < N; ++x)
        {
            cin >> candy[y][x];
        }
    }

    int Max = 0;
    Max = max(Max, CountFunction());

    char Temp = ' ';
    for (int y = 0; y < N; ++y)
    {
        for (int x = 0; x < N - 1; ++x)
        {
            // 행
            Temp = candy[y][x];
            candy[y][x] = candy[y][x + 1];
            candy[y][x + 1] = Temp;
            Max = max(Max, CountFunction());
            Temp = candy[y][x];
            candy[y][x] = candy[y][x + 1];
            candy[y][x + 1] = Temp;

            // 열
            Temp = candy[x][y];
            candy[x][y] = candy[x + 1][y];
            candy[x + 1][y] = Temp;
            Max = max(Max, CountFunction());
            Temp = candy[x][y];
            candy[x][y] = candy[x + 1][y];
            candy[x + 1][y] = Temp;

            if (Max == 4)
            {
                int a = 0;
            }
        }
    }
    
    cout << Max;

    return 0;
}