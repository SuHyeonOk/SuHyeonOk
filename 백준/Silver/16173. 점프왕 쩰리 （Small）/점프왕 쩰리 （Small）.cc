#include <iostream>
#include <queue>
using namespace std;
#define MAX 3

int g_N{ 0 };
int g_arr[MAX][MAX];
int g_visited[MAX][MAX];

bool BFS()
{
    queue<pair<int, int>> q;
    q.push({ 0, 0 });

    while (false == q.empty())
    {
        int x{ q.front().first };
        int y{ q.front().second };
        q.pop();

        int move{ g_arr[y][x] };
        int dx[2]{ 0, move };
        int dy[2]{ move, 0 };

        for (int i = 0; i < 2; i++)
        {
            int nx{ dx[i] + x };
            int ny{ dy[i] + y };

            if (nx >= g_N || nx < 0 || ny >= g_N || ny < 0)
            {
                continue;
            }

            if (true == g_visited[ny][nx])
            {
                continue;
            }

            if (-1 == g_arr[ny][nx])
            {
                return true;
            }

            g_visited[ny][nx] = true;
            q.push({ nx, ny });
        }
    }

    return false;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> g_N;

    for (int i = 0; i < g_N; i++)
    {
        for (int j = 0; j < g_N; j++)
        {
            cin >> g_arr[i][j];
        }
    }

    if (true == BFS())
    {
        cout << "HaruHaru";
    }
    else
    {
        cout << "Hing";
    }

    return 0;
}