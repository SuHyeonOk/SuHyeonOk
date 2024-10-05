#include <iostream>
#include <queue>
#include <string.h>
#define MAX 100
using namespace std;

int H, W;
char arr[MAX][MAX];
bool visited[MAX][MAX];
int dx[4]{ 0, 0, -1, 1 };
int dy[4]{ -1, 1, 0 , 0 };

void BFS(int _x, int _y)
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

            if (NX < 0 || NX >= W || NY < 0 || NY >= H)
            {
                continue;
            }

            if (true == visited[NY][NX] || '.' == arr[NY][NX])
            {
                continue;
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

    int T = 0;
    cin >> T;

    while (T--)
    {
        cin >> H >> W;

        for (int y = 0; y < H; ++y)
        {
            for (int x = 0; x < W; ++x)
            {
                cin >> arr[y][x];
            }
        }

        int Count = 0;
        for (int y = 0; y < H; ++y)
        {
            for (int x = 0; x < W; ++x)
            {
                if ('#' == arr[y][x] && false == visited[y][x])
                {
                    BFS(x, y);
                    ++Count;
                }
            }
        }
        cout << Count << '\n';
        
        memset(arr, ' ', sizeof(arr));
        memset(visited, false, sizeof(visited));
    }

    return 0;
}