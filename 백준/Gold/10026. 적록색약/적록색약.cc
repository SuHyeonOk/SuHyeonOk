#include <iostream>
#include <queue>
#include <string.h>
#define MAX 101
using namespace std;

int N;
char arr[MAX][MAX];
bool visited[MAX][MAX];
int dx[4]{ 0, 0, -1, 1 };
int dy[4]{ -1, 1, 0, 0 };

void BFS(char _Color, int _x, int _y)
{
    queue<pair<int, int>> q;
    q.push({ _x, _y });
    visited[_y][_x] = true;

    while (false == q.empty())
    {
        int X = q.front().first;
        int Y = q.front().second;
        q.pop();

        for (int i = 0; i < 4; ++i)
        {
            int NX = X + dx[i];
            int NY = Y + dy[i];

            if (0 > NX || N <= NX || 0 > NY || N <= NY)
            {
                continue;
            }

            if (true == visited[NY][NX])
            {
                continue;
            }

            if (_Color != arr[NY][NX])
            {
                continue;
            }

            visited[NY][NX] = true;
            q.push({ NX, NY });
        }
    }
}

void BFS2(char _Color, int _x, int _y)
{
    queue<pair<int, int>> q;
    q.push({ _x, _y });
    visited[_y][_x] = true;

    while (false == q.empty())
    {
        int X = q.front().first;
        int Y = q.front().second;
        q.pop();

        for (int i = 0; i < 4; ++i)
        {
            int NX = X + dx[i];
            int NY = Y + dy[i];

            if (0 > NX || N <= NX || 0 > NY || N <= NY)
            {
                continue;
            }

            if (true == visited[NY][NX])
            {
                continue;
            }

            if (_Color == 'R' || _Color == 'G')
            {
                if (arr[NY][NX] == 'B')
                {
                    continue;
                }
            }

            if (_Color == 'B')
            {
                if (arr[NY][NX] == 'R' || arr[NY][NX] == 'G')
                {
                    continue;
                }
            }

            visited[NY][NX] = true;
            q.push({ NX, NY });
        }
    }
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
            cin >> arr[y][x];
        }
    }

    int Count = 0;
    for (int y = 0; y < N; ++y)
    {
        for (int x = 0; x < N; ++x)
        {
            if (false == visited[y][x])
            {
                ++Count;
                BFS(arr[y][x], x, y);
            }
        }
    }

    cout << Count << ' ';
    memset(visited, false, sizeof(visited));

    Count = 0;
    for (int y = 0; y < N; ++y)
    {
        for (int x = 0; x < N; ++x)
        {
            if (false == visited[y][x])
            {
                ++Count;
                BFS2(arr[y][x], x, y);
            }
        }
    }

    cout << Count;

    return 0;
}