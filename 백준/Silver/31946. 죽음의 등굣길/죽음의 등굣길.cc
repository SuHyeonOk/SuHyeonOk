#include <iostream>
#include <queue>
#define MAX 100
using namespace std;

int N, M, Jump;
int arr[MAX][MAX];
bool visited[MAX][MAX];

int dy[4] = { -1, 0, 1, 0 };
int dx[4] = { 0, -1, 0, 1 };
int manhattanY[4] = { 1, 1, -1, -1 };
int manhattanX[4] = { -1, 1, 1, -1 };

bool BFS() 
{
    queue<pair<int, int> > q;
    q.push(make_pair(0, 0));
    visited[0][0] = true;

    while (false == q.empty()) 
    {
        int X = q.front().first;
        int Y = q.front().second;
        q.pop();

        if ((X == (N - 1)) && (Y == (M - 1)))
        {
            return true;
        }

        for (int i = 1; i <= Jump; i++)
        {
            for (int j = 0; j < 4; j++) 
            {
                int NX = X + (dy[j] * i);
                int NY = Y + (dx[j] * i);

                for (int k = 0; k < i; k++) 
                {
                    int NNX = NX + (manhattanY[j] * k);
                    int NNY = NY + (manhattanX[j] * k);

                    if (NNX < 0 || NNX >= N || NNY < 0 || NNY >= M)
                    {
                        continue;
                    }

                    if(true == visited[NNX][NNY] || arr[NNX][NNY] != arr[X][Y])
                    {
                        continue;
                    }

                    visited[NNX][NNY] = true;
                    q.push({ NNX, NNY });
                }
            }
        }
    }

    return false;
}

int main() 
{
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> N;
    cin >> M;
    for (int i = 0; i < N; i++) 
    {
        for (int j = 0; j < M; j++) 
        {
            cin >> arr[i][j];
        }
    }
    cin >> Jump;

    if (true == BFS()) 
    {
        cout << "ALIVE";
    }
    else 
    {
        cout << "DEAD";
    }

    return 0;
}