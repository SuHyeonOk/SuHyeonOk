#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

#define MAX 300001

int N{ 0 }, M{ 0 }, K{ 0 }, X{ 0 };
vector<vector<int>> vec;
vector<int> dis;

void Dijkstra(int _start)
{
    dis[_start] = 0; // 시작위치에서 시작위치로 가는 비용은 0
    queue<int> q;
    q.push(_start);

    while (false == q.empty())
    {
        int current = q.front();
        q.pop();

        size_t size = vec[current].size();
        for (size_t i = 0; i < size; i++)
        {
            int next = vec[current][i];
            if (dis[next] > dis[current] + 1)
            {
                dis[next] = dis[current] + 1;
                q.push(next);
            }
        }
    }

}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> N >> M >> K >> X;
    vec.resize(N + 1);
    dis.resize(N + 1, MAX);

    int A{ 0 }, B{ 0 };
    for (int i = 0; i < M; i++)
    {
        cin >> A >> B;
        vec[A].push_back(B);
    }

    Dijkstra(X);

    bool check{ false };
    for (int i = 1; i <= N; i++)
    {
        if (dis[i] == K)
        {
            check = true;
            cout << i << '\n';
        }
    }

    if (false == check)
    {
        cout << -1;
    }

    return 0;
}