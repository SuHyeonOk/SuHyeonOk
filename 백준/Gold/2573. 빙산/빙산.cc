#include <iostream>
#include <list>
#include <queue>
#include <vector>
#include <cstring>
#define MAX 300
using namespace std;

typedef struct tagIcebergInfo
{
    int x{ 0 }, y{ 0 }, ocean{ 0 };
}INFO;

int N, M;
list<INFO> iceberg;
int map[MAX][MAX];
bool visited[MAX][MAX];
int dx[4]{ 0, 0, -1, 1 };
int dy[4]{ -1, 1, 0, 0 };

int OceanCount(int _x, int _y)
{
    int oceancount{ 0 };

    for (size_t i = 0; i < 4; i++)
    {
        int nx{ _x + dx[i] };
        int ny{ _y + dy[i] };

        if (nx < 0 || nx >= M || ny < 0 || ny >= N)
        {
            continue;
        }

        if (0 != map[ny][nx]) // 빙산이 아닌경우
        {
            continue;
        }

        ++oceancount;
    }

    return oceancount;
}

void OneYearLater()
{
    vector<list<INFO>::iterator> vec;
    for (list<INFO>::iterator it = iceberg.begin(); it != iceberg.end(); it++)
    {
        map[it->y][it->x] -= it->ocean;

        if (0 >= map[it->y][it->x])
        {
            map[it->y][it->x] = 0; // 안 해줘도 되긴 함
            vec.push_back(it);
        }
    }

    size_t size = vec.size();
    for (size_t i = 0; i < size; i++)
    {
        iceberg.erase(vec[i]); // 빙산 → 바다가 되면서 list에서 제외
    }
}

void BFS(int _x, int _y)
{
    queue<pair<int, int>> q;
    q.push({ _x, _y });
    visited[_y][_x] = true;

    while (false == q.empty())
    {
        int x{ q.front().first };
        int y{ q.front().second };
        q.pop();

        for (size_t i = 0; i < 4; i++)
        {
            int nx{ x + dx[i] };
            int ny{ y + dy[i] };

            if (nx < 0 || nx >= M || ny < 0 || ny >= N)
            {
                continue;
            }

            if (0 == map[ny][nx] || true == visited[ny][nx])
            {
                continue;
            }

            visited[ny][nx] = true;
            q.push({ nx, ny });
        }
    }
}

int IcebergCount()
{
    int sum{ 0 };
    for (int y = 0; y < N; y++)
    {
        for (int x = 0; x < M; x++)
        {
            if (0 == map[y][x] || true == visited[y][x])
            {
                continue;
            }

            BFS(x, y);
            ++sum;
        }
    }

    return sum;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> N >> M;

    for (int y = 0; y < N; y++)
    {
        for (int x = 0; x < M; x++)
        {
            cin >> map[y][x];

            if (0 != map[y][x])
            {
                iceberg.push_back({ x, y, 0 });
            }
        }
    }

    // 빙산 근처의 바다(0)의 개수를 센다.
    for (list<INFO>::iterator it = iceberg.begin(); it != iceberg.end(); it++)
    {
        it->ocean = OceanCount(it->x, it->y);
    }

    // 빙산이 나눠질 때까지 또는 빙산이 없어질 때까지 반복한다.
    int result{ 0 };
    while (true)
    {
        // 빙산 개수 세기
        int sum = IcebergCount();
        if (1 < sum)
        {
            break;
        }

        memset(visited, false, sizeof(visited));
        OneYearLater(); // 1년 후 즉, 빙산 근처의 바다 수 만큼 빙산 높이 감소
        ++result;

        // 만일 전부 다 녹을 때까지 두 덩어리 이상으로 분리되지 않으면 프로그램은 0을 출력
        if (true == iceberg.empty())
        {
            result = 0;
            break;
        }

        // 빙산 근처의 바다(0)의 개수를 센다.
        for (list<INFO>::iterator it = iceberg.begin(); it != iceberg.end(); it++)
        {
            it->ocean = OceanCount(it->x, it->y);
        }
    }

    cout << result;

    return 0;
}