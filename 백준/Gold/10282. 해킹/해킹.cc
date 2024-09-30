#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
using namespace std;

struct INFO
{
    int Dependence = 0;
    int Second = 0;
};

vector<INFO> graph[10001];
int minTime[10001];

void Dijkstra(int start)
{
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({ 0, start });
    minTime[start] = 0;

    while (!pq.empty())
    {
        int currentTime = pq.top().first;
        int currentNode = pq.top().second;
        pq.pop();

        if (currentTime > minTime[currentNode])
        {
            continue;
        }

        for (const auto& next : graph[currentNode])
        {
            int nextNode = next.Dependence;
            int travelTime = currentTime + next.Second;

            if (travelTime < minTime[nextNode])
            {
                minTime[nextNode] = travelTime;
                pq.push({ travelTime, nextNode });
            }
        }
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int T;
    cin >> T;

    while (T--)
    {
        int n, d, c;
        cin >> n >> d >> c;

        for (int i = 1; i <= n; ++i)
        {
            graph[i].clear();
            minTime[i] = 1e9;
        }

        for (int i = 0; i < d; ++i)
        {
            int a, b, s;
            cin >> a >> b >> s;
            graph[b].push_back({ a, s });
        }

        Dijkstra(c);

        int count = 0, maxTime = 0;

        for (int i = 1; i <= n; ++i)
        {
            if (minTime[i] != 1e9)
            {
                count++;
                maxTime = max(maxTime, minTime[i]);
            }
        }

        cout << count << ' ' << maxTime << '\n';
    }

    return 0;
}
