#include <iostream>
#include <vector>
using namespace std;
#define MAX 101

int N, M, K, TrashCount, MaxTrash;
bool arr[MAX][MAX];
vector<vector<bool>> visited;
int dx[4]{ 0, 0, -1, 1 };
int dy[4]{ -1, 1, 0, 0 };

void DFS(int _y, int _x)
{
    visited[_y][_x] = true;

    for (size_t i = 0; i < 4; i++)
    {
        int nx{ dx[i] + _x };
        int ny{ dy[i] + _y };

        if (nx < 0 || nx > M || ny < 0 || ny > N)
        {
            continue;
        }

        if (true == visited[ny][nx] || false == arr[ny][nx])
        {
            continue;
        }

        visited[ny][nx] = true;
        ++TrashCount;
        DFS(ny, nx);
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> N >> M >> K;

    int r{ 0 }, c{ 0 };
    vector<pair<int, int>> trash(K);
    for (int i = 0; i < K; i++)
    {
        cin >> r >> c;

        arr[r][c] = true; // 쓰레기 위치 표시
        trash[i] = { r, c }; // 쓰레기 좌표 받기
    }

    // 쓰레기 개수 만큼 연결된 모든 쓰레기를 찾는다.
    for (int i = 0; i < K; i++)
    {
        TrashCount = 1;
        visited.clear();
        visited.resize(N + 1, vector<bool>(M + 1));
        DFS(trash[i].first, trash[i].second);

        if (MaxTrash < TrashCount)
        {
            MaxTrash = TrashCount;
        }
    }

    cout << MaxTrash;

    return 0;
}