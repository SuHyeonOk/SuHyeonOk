#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#define MAX 25
using namespace std;

int N;
char arr[MAX][MAX];
bool visited[MAX][MAX];
vector<int> result;

int dx[4]{ 0, 0, -1, 1 };
int dy[4]{ -1, 1, 0, 0 };

void BFS(int _x, int _y)
{
    queue<pair<int, int>> q;
    q.push({_x, _y});

    int Move = 1;
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

            if ('0' == arr[NY][NX])
            {
                continue;
            }

            visited[NY][NX] = true;
            q.push({ NX, NY });
            ++Move;
        }
    }

    result.push_back(Move);
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

    for (int y = 0; y < N; ++y)
    {
        for (int x = 0; x < N; ++x)
        {
            if (false == visited[y][x] && '1' == arr[y][x])
            {
                BFS(x, y);
            }
        }
    }

    sort(result.begin(), result.end());
    size_t Size = result.size();
    cout << Size << '\n';
    for (int i = 0; i < Size; ++i)
    {
        cout << result[i] << '\n';
    }

    return 0;
}