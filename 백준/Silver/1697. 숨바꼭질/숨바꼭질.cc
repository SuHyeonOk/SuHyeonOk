#include <iostream>
#include <array>
#include <queue>

using namespace std;

#define MAX 100001

int N{ 0 }, K{ 0 };
array<bool, MAX> visited{ false };

void DFS(int node)
{
	queue<pair<int, int>> q;
	q.push({ node, 0 });

	while (false == q.empty()) // q가 비지 비어있지 않으면 반복
	{
		int x = q.front().first;
		int cnt = q.front().second;
		q.pop();

		if (x == K)
		{
			cout << cnt;
			break;
		}

		if (x + 1 >= 0 && x + 1 < MAX)
		{
			if (false == visited[x + 1])
			{
				visited[x + 1] = true;
				q.push({ x + 1, cnt + 1 });
			}
		}

		if (x - 1 >= 0 && x - 1 < MAX)
		{
			if (false == visited[x - 1])
			{
				visited[x - 1] = true;
				q.push({ x - 1, cnt + 1 });
			}
		}

		if (x * 2 >= 0 && x * 2 < MAX)
		{
			if (false == visited[x * 2])
			{
				visited[x * 2] = true;
				q.push({ x * 2, cnt + 1 });
			}
		}
	}

}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> N >> K;

	visited[N] = true;

	DFS(N);

	return 0;
}