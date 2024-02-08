#include <iostream>
#include <queue>
#define MAX 101
using namespace std;

/*
-1~6 숫자는 자유롭게 이동
- 뱀은 무조건 안 밟는게 좋을까
*/

int N, M;
int map[MAX];
bool visited[MAX];

int BFS()
{
    queue<pair<int, int>>q;
    q.push({ 1, 0 });
    visited[1] = true;

    while (false == q.empty())
    {
        int X = q.front().first;
        int Count = q.front().second + 1;
        q.pop();

        for (int i = 1; i <= 6; i++)
        {
            int NX = X + i;

            if (NX == 100)
            {
                return Count;
            }
            else if (NX < 100)
            {
                if (0 != map[NX])
                { 
                    NX = map[NX];
                }

                if (false == visited[NX])
                {
                    q.push({ NX, Count });
                    visited[NX] = true;
                }
            }
        }
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> N >> M;

    int x = 0, y = 0;
    for (int i = 0; i < N + M; i++)
    {
        cin >> x >> y;
        map[x] = y;
    }

    cout << BFS();

    return 0;
}