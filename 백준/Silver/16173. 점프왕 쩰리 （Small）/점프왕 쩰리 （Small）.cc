#include <iostream>
using namespace std;
#define MAX 3

int g_N{ 0 };
int g_arr[MAX][MAX];
bool g_visited[MAX][MAX];
bool g_end{ false };

void DFS(int _x, int _y)
{
    int move{ g_arr[_y][_x] };
    int dx[2]{ 0, move };
    int dy[2]{ move, 0 };

    for (int i = 0; i < 2; i++)
    {
        int nx{ dx[i] + _x };
        int ny{ dy[i] + _y };

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
            g_end = true;
        }

        g_visited[ny][nx] = true;
        DFS(nx, ny);
        g_visited[ny][nx] = false;
    }

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

    DFS(0, 0);

    if (true == g_end)
    {
        cout << "HaruHaru";
    }
    else
    {
        cout << "Hing";
    }

    return 0;
}