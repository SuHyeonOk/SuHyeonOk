#include <iostream>
#include <queue>
#include<cstring>
#define MAX 400
using namespace std;

int arr[MAX][MAX];
bool visited[MAX][MAX];

int dx[8]{ 1, 2, 2, 1, -1, -2, -2, -1 };
int dy[8]{ -2, -1, 1, 2, 2, 1, -1, -2 };

typedef struct tafInfo
{
    int X = 0;
    int Y = 0;
    int Count = 0;
}INFO;

int BFS(int _I, int _StartX, int _StartY, int _EndX, int _EndY)
{
    queue<INFO> q;
    q.push({ _StartX, _StartY, 0 });

    while (false == q.empty())
    {
        int x = q.front().X;
        int y = q.front().Y;
        int Count = q.front().Count;
        q.pop();

        if (x == _EndX && y == _EndY)
        {
            return Count;
        }

        for (size_t i = 0; i < 8; i++)
        {
            int nx = x + dx[i];
            int ny = y + dy[i];

            if (nx < 0 || nx >= _I || ny < 0 || ny >= _I)
            {
                continue;
            }

            if (true == visited[ny][nx])
            {
                continue;
            }

            visited[ny][nx] = true;
            q.push({ nx, ny, Count + 1 });
        }
    }

    return -1;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int T = 0;
    cin >> T;

    int I = 0;
    int StartX = 0, StartY = 0;
    int EndX = 0, EndY = 0;

    while (T--)
    {
        cin >> I >> StartX >> StartY >> EndX >> EndY;

        if (StartX == EndX && StartY == EndY)
        {
            cout << 0 << '\n';
            continue;
        }

        cout << BFS(I, StartX, StartY, EndX, EndY) << '\n';
        memset(arr, 0, sizeof(arr));
        memset(visited, false, sizeof(visited));
    }

    return 0;
}