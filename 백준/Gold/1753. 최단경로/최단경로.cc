#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int V{ 0 }, E{ 0 }, K{ 0 }, sum{ 0 }, findNode{ 0 }, intMax{ 2147483647 };
vector<vector<pair<int, int>>> vec;
vector<int> vecDistance;

void Dijkstra()
{
    priority_queue<pair<int, int>> pq;
    pq.push({ 0, K });

    while (false == pq.empty())
    {
        int cost = -pq.top().first;
        int current = pq.top().second;
        pq.pop();

        size_t size = vec[current].size();
        for (size_t i = 0; i < size; i++)
        {
            int next = vec[current][i].first;
            int nextCost = vec[current][i].second;

            if (vecDistance[next] > cost + nextCost)
            {
                vecDistance[next] = cost + nextCost;
                pq.push({ -vecDistance[next], next });
            }
        }
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> V >> E >> K;
    vec.resize(V + 1);
    vecDistance.resize(V + 1, intMax);

    int u{ 0 }, v{ 0 }, w{ 0 };

    for (int i = 0; i < E; i++)
    {
        cin >> u >> v >> w;
        vec[u].push_back({ v, w });
    }

    Dijkstra();
    vecDistance[K] = 0;

    for (int i = 1; i <= V; i++)
    {
        if (intMax == vecDistance[i])
        {
            cout << "INF" << '\n';
            continue;
        }

        cout << vecDistance[i] << '\n';
    }

    return 0;
}