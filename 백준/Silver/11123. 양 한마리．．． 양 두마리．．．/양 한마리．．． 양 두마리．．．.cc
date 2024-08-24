#include <iostream>
#include <queue>
using namespace std;

int T, H, W;
const int MAX = 101;
int map[MAX][MAX];
bool visited[MAX][MAX];
int dy[] = { 0,0,-1,1 };
int dx[] = { -1,1,0,0 };
queue<pair<int, int>> q;
int ans[MAX];
int cnt = 0;

void BFS(int y, int x) 
{
    visited[y][x] = true;
    q.push(make_pair(y, x));

    while (false == q.empty()) 
    {
        y = q.front().first;
        x = q.front().second;
        q.pop();

        for (int i = 0; i < 4; i++)
        {
            int ny = y + dy[i];
            int nx = x + dx[i];

            if (ny < 0 || nx < 0 || ny >= H || nx >= W)
            {
                continue;
            }

            if (map[ny][nx] == 1 && visited[ny][nx] == 0)
            {
                visited[ny][nx] = true;
                q.push(make_pair(ny, nx));
            }
        }
    }
}

void reset() 
{
    for (int i = 0; i < MAX; i++) 
    {
        for (int j = 0; j < MAX; j++) 
        {
            map[i][j] = 0;
            visited[i][j] = 0;
        }
    }
    cnt = 0;
}

int main() 
{
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> T;

    for (int t = 0; t < T; t++) 
    {
        cin >> H >> W;
        char input[MAX][MAX];

        for (int i = 0; i < H; i++)
        {
            for (int j = 0; j < W; j++)
            {
                cin >> input[i][j];
            }
        }

        for (int i = 0; i < H; i++) 
        {
            for (int j = 0; j < W; j++) 
            {
                if (input[i][j] == '.')
                {
                    map[i][j] = 0;
                }
                if (input[i][j] == '#')
                {
                    map[i][j] = 1;
                }
            }
        }

        for (int i = 0; i < H; i++) 
        {
            for (int j = 0; j < W; j++) 
            {
                if (map[i][j] == 1 && visited[i][j] == 0)
                {
                    BFS(i, j);
                    cnt++;
                }
            }
        }
        ans[t] = cnt;

        reset();
    }

    for (int i = 0; i < T; i++) 
    {
        cout << ans[i] << '\n';
    }

    return 0;
}