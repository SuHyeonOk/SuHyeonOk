#include <iostream>
#include <queue>
#define MAX 51
using namespace std;

int N, M;
char arr[MAX][MAX];
bool visited[MAX][MAX];

void BFS(char _Floor, int _X, int _Y)
{
    queue<pair<int, int>> q;
    q.push({ _X, _Y });

    while (false == q.empty())
    {
        int X = q.front().first;
        int Y = q.front().second;
        q.pop();

        if (true == visited[Y][X])
        {
            continue;
        }
        
        visited[Y][X] = true;

        if ('-' == _Floor)
        {
            if (_Floor == arr[Y][X + 1])
            {
                q.push({ X + 1, Y });
            }
        }
        else
        {
            if (_Floor == arr[Y + 1][X])
            {
                q.push({ X, Y + 1});
            }
        }
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> N >> M;

    for (int y = 0; y < N; y++)
    {
        for (int x = 0; x < M; x++)
        {
            cin >> arr[y][x];
        }
    }

    int Count = 0;
    for (int y = 0; y < N; y++)
    {
        for (int x = 0; x < M; x++)
        {
            if (visited[y][x] == false)
            {
                BFS(arr[y][x], x, y);
                ++Count;
            }
        }
    }

    cout << Count;

    return 0;
}