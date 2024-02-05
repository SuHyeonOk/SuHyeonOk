#include<iostream>
#include<vector>
#include<queue>
#define MAX 1000
using namespace std;

int map[MAX][MAX][2];

int dx[4] = { -1, 1, 0, 0 };
int dy[4] = { 0, 0, -1, 1 };

int BFS(int N, int M)
{
    queue<pair<int, pair<int, int>>> q;
    q.push({ 0, { 0, 0 } });

    while (false == q.empty())
    {
        int broken = q.front().first;
        int x = q.front().second.first;
        int y = q.front().second.second;
        q.pop();

        if (x == N - 1 && y == M - 1)
        {
            return map[N - 1][M - 1][broken] + 1;
        }

        for (size_t i = 0; i < 4; i++)
        {
            int nx = x + dx[i];
            int ny = y + dy[i];

            if (nx < 0 || nx >= N || ny < 0 || ny >= M)
            {
                continue;
            }

            if (map[nx][ny][0] == 1)
            {
                if (false == broken)
                {
                    map[nx][ny][broken + 1] = map[x][y][broken] + 1;
                    q.push({ 1, { nx, ny } });
                }
            }
            else if (map[nx][ny][0] == 0)
            {
                if (broken == 1 && map[nx][ny][broken])
                {
                    continue;
                }

                map[nx][ny][broken] = map[x][y][broken] + 1;
                q.push({ broken, { nx, ny } });
            }
        }
    }

    return -1;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int N, M;
    cin >> N >> M;

    char input;
    for (int y = 0; y < N; y++)
    {
        for (int x = 0; x < M; x++)
        {
            cin >> input;
            map[y][x][0] = input - '0';
        }
    }

    cout << BFS(N, M);

    return 0;
}