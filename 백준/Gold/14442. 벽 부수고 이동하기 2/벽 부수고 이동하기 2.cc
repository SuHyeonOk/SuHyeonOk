#include<iostream>
#include<vector>
#include<queue>
#define MAX 1000
using namespace std;

int N, M, K;
bool map[1003][1003];
bool visited[1003][1003][11];

int dx[4] = { 0, 0, -1, 1 };
int dy[4] = { -1, 1, 0, 0 };

struct Node 
{
    int X = 0;
    int Y = 0;
    int Z = 0;
    int D = 0;
};

int BFS()
{
    queue<Node> q;
    visited[1][1][0] = true;
    q.push({ 1,1,0 ,1 });

    while (false == q.empty())
    {
        int x = q.front().X;
        int y = q.front().Y;
        int z = q.front().Z;
        int d = q.front().D;
        q.pop();

        if (x == N && y == M)
        {
            return d;
        }

        for (int i = 0; i < 4; i++) 
        {
            int nx = x + dx[i];
            int ny = y + dy[i];

            if (nx <= 0 || nx > N || ny <= 0 || ny > M)
            {
                continue;
            }

            if (map[nx][ny] == 1) 
            {
                if (z < K && visited[nx][ny][z + 1] == false) 
                {
                    visited[nx][ny][z + 1] = 1;
                    q.push({ nx,ny,z + 1,d + 1 });
                }
            }
            else 
            {
                if (visited[nx][ny][z] == false) 
                {
                    visited[nx][ny][z] = 1;
                    q.push({ nx,ny,z,d + 1 });
                }
            }
        }
    }

    return -1;
}

int main() 
{
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> N >> M >> K;

    char input = ' ';
    for (int y = 1; y <= N; y++) 
    {
        for (int x = 1; x <= M; x++) 
        {
            cin >> input;
            map[y][x] = static_cast<bool>(input - '0');
        }
    }

    cout << BFS();

    return 0;
}