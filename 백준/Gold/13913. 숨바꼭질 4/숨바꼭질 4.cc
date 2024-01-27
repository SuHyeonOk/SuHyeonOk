#include <iostream>
#include <queue>
#include <vector>
#include <cstring>
#define MAX 100001
using namespace std;

int N{ 0 }, K{ 0 };
int visited[MAX];

void BFS()
{
	memset(visited, -1, sizeof(visited));
	queue<pair<int, int>> q;
	q.push({ N, 0 });
	visited[N] = N;

	while (false == q.empty())
	{
		int X = q.front().first;
		int Time = q.front().second;
		q.pop();

		if (X == K)
		{
			cout << Time << '\n';

			vector<int> vec;
			while (X != N)
			{
				vec.push_back(X);
				X = visited[X];
			}
			vec.push_back(X);

			int size = vec.size() - 1;
			for (int i = size; i >= 0; i--)
			{
				cout << vec[i] << " ";
			}

			break;
		}

		if (X * 2 <= MAX && visited[X * 2] == -1)
		{
			visited[X * 2] = X;
			q.push({ X * 2, Time + 1 });
		}
		if (X + 1 <= MAX && visited[X + 1] == -1)
		{
			visited[X + 1] = X;
			q.push({ X + 1, Time + 1 });
		}
		if (X - 1 >= 0 && visited[X - 1] == -1)
		{
			visited[X - 1] = X;
			q.push({ X - 1, Time + 1 });
		}
	}

}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> N >> K;

	BFS();

	return 0;
}