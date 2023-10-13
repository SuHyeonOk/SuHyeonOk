#include <iostream>
#include <vector>
#include <queue>
#include <tuple>
using namespace std;
#define MAX 50

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int N{ 0 }, M{ 0 }; // N가로 M세로
    cin >> N >> M;

    vector<vector<bool>> vec(M, vector<bool>(N));

    char input{ ' ' };
    for (int i = 0; i < M; i++)
    {
        for (int j = 0; j < N; j++)
        {
            cin >> input;

            if ('1' == input)
            {
                vec[i][j] = true;
            }
        }
    }

    int dx[4]{ 0, 0, -1, 1 };
    int dy[4]{ -1, 1, 0, 0 };

    priority_queue<tuple<int, int, int>> pq; // 내림차순
    //priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, greater<tuple<int, int, int>>> pq;
    vector<vector<bool>> visited(M, vector<bool>(N));
    pq.push({ 0, 0, 0 });

    while (false == pq.empty())
    {
        int cost = get<0>(pq.top());
        int x = get<1>(pq.top());
        int y = get<2>(pq.top());
        pq.pop();

        if (x == N - 1 && y == M - 1)
        {
            cout << cost * -1;
            return 0;
        }

        for (int i = 0; i < 4; i++)
        {
            int nx = x + dx[i];
            int ny = y + dy[i];

            if (0 > nx || N <= nx || 0 > ny || M <= ny)
            {
                continue;
            }

            if (true == visited[ny][nx])
            {
                continue;
            }

            visited[ny][nx] = true;

            if (vec[ny][nx] == 0)
            {
                pq.push({ cost, nx, ny });
            }
            else // vec[nx][ny] == 1
            {
                pq.push({ cost - 1, nx, ny });
            }
        }
    }



    return 0;
}