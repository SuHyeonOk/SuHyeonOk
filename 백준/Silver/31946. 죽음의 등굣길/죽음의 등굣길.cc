#include <iostream>
#include <queue>
#define MAX 101
using namespace std;

int N, M, Jump;
int MAP[MAX][MAX];
bool Visited[MAX][MAX];
int MoveY[4] = { -1,0,1,0 };
int MoveX[4] = { 0,-1,0,1 };
int ManhattanY[4] = { 1,1,-1,-1 };
int ManhattanX[4] = { -1,1,1,-1 };

bool BFS() {
    queue<pair<int, int> > Q;
    Q.push(make_pair(0, 0));
    Visited[0][0] = true;

    while (!Q.empty()) 
    {
        int X = Q.front().first;
        int Y = Q.front().second;
        Q.pop();

        if ((X == (N - 1)) && (Y == (M - 1)))
        {
            return true;
        }

        for (int i = 1; i <= Jump; i++)
        {
            for (int j = 0; j < 4; j++) 
            {
                int NX = X + (MoveY[j] * i);
                int NY = Y + (MoveX[j] * i);

                for (int k = 0; k < i; k++) 
                {
                    int NNX = NX + (ManhattanY[j] * k);
                    int NNY = NY + (ManhattanX[j] * k);

                    if ((NNX >= 0) && (NNX < N) && 
                        (NNY >= 0) && (NNY < M) && 
                        !Visited[NNX][NNY] &&
                        (MAP[NNX][NNY] == MAP[X][Y])) 
                    {
                        Visited[NNX][NNY] = true;
                        Q.push({ NNX, NNY });
                    }
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
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> MAP[i][j];
        }
    }
    cin >> Jump;

    if (true == BFS()) 
    {
        cout << "ALIVE\n";
    }
    else 
    {
        cout << "DEAD\n";
    }

    return 0;
}