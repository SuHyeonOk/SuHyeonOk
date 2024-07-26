#include <iostream>
#include <queue>
#include <cstring>
#define MAX 50
using namespace std;

int N, M, K;
int arr[MAX][MAX];
bool visited[MAX][MAX];

int dx[4]{ 0, 0, -1, 1 };
int dy[4]{ -1, 1, 0, 0 };

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

            if (0 > NX || M <= NX || 0 > NY || N <= NY)
            {
                continue;
            }

            if (true == visited[NY][NX] || 0 == arr[NY][NX])
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

    int TestCase = 0;
    cin >> TestCase;

    int X = 0, Y = 0;
    while (TestCase--)
    {
        cin >> M >> N >> K;

        for (int k = 0; k < K; ++k)
        {
            cin >> X >> Y;
            arr[Y][X] = 1;
        }

        int Count = 0;
        for (int y = 0; y < N; ++y)
        {
            for (int x = 0; x < M; ++x)
            {
                if (1 == arr[y][x] && false == visited[y][x])
                {
                    BFS(x, y);
                    ++Count;
                }
            }
        }

        cout << Count << '\n';
        memset(arr, 0, sizeof(arr));
        memset(visited, false, sizeof(visited));
    }

    return 0;
}