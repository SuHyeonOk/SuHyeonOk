#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;

#define MAX 100000
int nodeStart{ 0 }, nodeEnd{ 0 };
int visited[MAX + 1];
vector<int> vec;

int BFS()
{
	fill(visited, visited + MAX + 1, -1);

	queue<pair<int, int>> q;
	q.push({ nodeStart, 0 });
	visited[nodeStart] = 1;

	while (false == q.empty())
	{
		int node = q.front().first;
		int time = q.front().second;
		q.pop();

		if (node == nodeEnd)
		{
			while (node != nodeStart)
			{
				vec.push_back(node);
				node = visited[node];
			}
			vec.push_back(nodeStart);

			return time;
		}

		if (node * 2 <= MAX && visited[node * 2] == -1)
		{
			q.push({ node * 2, time + 1 });
			visited[node * 2] = node;
		}
		if (node + 1 <= MAX && visited[node + 1] == -1)
		{
			q.push({ node + 1, time + 1 });
			visited[node + 1] = node;
		}
		if (node - 1 >= 0 && visited[node - 1] == -1)
		{
			q.push({ node - 1, time + 1 });
			visited[node - 1] = node;
		}
	}

}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> nodeStart >> nodeEnd;

	cout << BFS() << '\n';

	int size = vec.size() - 1;
	for (int i = size; i >= 0; i--) // 역으로 출력
	{
		cout << vec[i] << " ";
	}

	return 0;
}