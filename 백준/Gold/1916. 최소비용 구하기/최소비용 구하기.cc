#include <iostream>
#include <vector>
#include <queue>

using namespace std;

#define MAX 2147483647

vector<vector<pair<int, int>>> vec;
vector<int> distances;

void Dijkstra(int _start)
{
	distances[_start] = 0;
	queue<pair<int, int>> pq;
	pq.push({ distances[_start], _start });

	while (false == pq.empty())
	{
		int current = pq.front().second;
		int distance = pq.front().first;
		pq.pop();

		if (distances[current] < distance)
		{
			// 이미 distance가 최소로 변경 된 경우
			continue;
		}

		size_t size = vec[current].size();
		for (size_t i = 0; i < size; i++)
		{
			// 현재 도시와 연결된 정점들
			int next = vec[current][i].first;
			// 현재까지 시작에서 current까지 최소 거리와
			// currrent를 지나 next까지 거리를 더한 distance
			int nextdistance = vec[current][i].second + distance;

			if (nextdistance < distances[next])
			{
				// 만약 현재 도시를 지나가는 것이 더 가깝다면
				distances[next] = nextdistance;
				pq.push({ nextdistance, next });
			}
		}
	}

}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int N{ 0 }, M{ 0 }, startCity{ 0 }, endCity{ 0 }, cost{ 0 };
	cin >> N >> M;

	vec.resize(N + 1);
	distances.resize(N + 1, MAX);
	
	for (int i = 0; i < M; i++)
	{
		cin >> startCity >> endCity >> cost;
		vec[startCity].push_back({ endCity, cost });
	}
	cin >> startCity >> endCity;

	Dijkstra(startCity);

	cout << distances[endCity];

	return 0;
}