#include <iostream>
#include <queue>
#include <cstring>
using namespace std;

int n{ 0 };
int arr[125][125];
bool visited[125][125];

int dx[4]{ 0, 0 , -1, 1 };
int dy[4]{ -1, 1, 0, 0 };

struct INFO
{
    int x{ 0 };
    int y{ 0 };
    int amount{ 0 };

};

struct Compare
{
    bool operator()(const INFO& a, const INFO& b) 
    {
        return a.amount > b.amount;  // std::greater를 사용하여 오름차순 정렬
    }
};

int BFS()
{
    priority_queue<INFO, vector<INFO>, Compare> pq;
    pq.push({ 0,0,arr[0][0] });

    memset(visited, false, sizeof(visited));

    while (false == pq.empty())
    {
        int pqx{ pq.top().x };
        int pqy{ pq.top().y };
        int tempAmount{ pq.top().amount };
        pq.pop();

        if (pqx == n - 1 && pqy == n - 1)
        {
            return tempAmount;
        }

        for (size_t i = 0; i < 4; i++)
        {
            int nx{ pqx + dx[i] };
            int ny{ pqy + dy[i] };

            if (nx < 0 || nx >= n || ny < 0 || ny >= n)
            {
                continue;
            }

            if (true == visited[ny][nx])
            {
                continue;
            }

            visited[ny][nx] = true;
            pq.push({ nx, ny, tempAmount + arr[ny][nx] });
        }
    }

    return 0;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int count{ 0 };

    while (true)
    {
        cin >> n;

        if (0 == n)
        {
            break;
        }

        for (int y = 0; y < n; y++)
        {
            for (int x = 0; x < n; x++)
            {
                cin >> arr[y][x];
            }
        }

        cout << "Problem " << ++count << ": " << BFS() << '\n';

    }

    return 0;
}