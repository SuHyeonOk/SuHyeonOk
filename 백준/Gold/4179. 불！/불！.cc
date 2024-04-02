#include <iostream>
#include <queue>
#include <string>
#include <vector>
#define MAX 1002
using namespace std;

int R, C, Result;
int JX, JY;
char map[MAX][MAX];
vector<pair<int, int>> Fvec;

bool visited[MAX][MAX];
int dx[4]{ 0, 0, -1, 1 };
int dy[4]{ -1, 1, 0, 0 };

struct INFO
{
    int X = 0;
    int Y = 0;
    int Count = 0;
};

string BFS()
{
    queue<INFO> q;

    // 불은 여러개가 될 수 있다.
    size_t Size = Fvec.size();
    if (0 != Size)
    {
        for (size_t i = 0; i < Size; i++)
        {
            q.push({ Fvec[i].first, Fvec[i].second, -1});
            visited[Fvec[i].second][Fvec[i].first] = true;
        }
    }

    // 지훈
    q.push({ JX, JY, 0 });
    visited[JY][JX] = true;

    while (false == q.empty())
    {
        int X = q.front().X;
        int Y = q.front().Y;
        int Count = q.front().Count;
        q.pop();
        
        // 탈출을 성공한 경우
        if (0 >= X || X > C || 0 >= Y || Y > R)
        {
            if (Count != -1) // 불이 아니라는 예외처리
            {
                return to_string(Count);
            }
        }

        for (size_t i = 0; i < 4; i++)
        {
            int NX = X + dx[i];
            int NY = Y + dy[i];

            if (-1 == Count) // 불인 경우 탈출 경로를 벗어나면 안 된다.
            {
                if (NX <= 0 || NX > C || NY <= 0 || NY > R)
                {
                    continue;
                }
            }
            else // 지훈의 경우 탈출 경로를 저장하기 위해서 더 범위 넓게 탐색
            {
                if (NX < 0 || NX > C + 1 || NY < 0 || NY > R + 1)
                {
                    continue;
                }
            }

            if ('#' == map[NY][NX] || true == visited[NY][NX])
            {
                continue;
            }

            visited[NY][NX] = true;

            if (-1 == Count) // 불
            {
                q.push({ NX, NY, -1 });
            }
            else // 지훈
            {
                q.push({ NX, NY, Count + 1 });
            }
        }
    }

    return "IMPOSSIBLE";
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> R >> C;

    for (int y = 1; y <= R; y++)
    {
        for (int x = 1; x <= C; x++)
        {
            cin >> map[y][x];

            if ('J' == map[y][x]) // 지훈이 위치
            {
                JX = x;
                JY = y;
            }
            else if ('F' == map[y][x]) // 불 위치
            {
                Fvec.push_back({ x, y });
            }
        }
    }

    cout << BFS();

    return 0;
}