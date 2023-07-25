#include <iostream>
#include <vector>
#include <array>
#include <queue>

using namespace std;

#define MAX 1000
#define FOUR 4

int n{ 0 }, m{ 0 };
vector<vector<int>> vec;
vector<vector<bool>> visited;
queue<pair<int, int>> q;

void BFS()
{
	array<int, 4> dx{ 0,0,-1,1 };
	array<int, 4> dy{ -1,1,0,0 };

	while (false == q.empty())
	{
		int x = q.front().second;
		int y = q.front().first;
		q.pop();

		for (int i = 0; i < FOUR; i++)
		{
			int nx = x + dx[i];
			int ny = y + dy[i];

			if (nx < 0 || nx >= m || ny < 0 || ny >= n)
			{
				continue;
			}

			if (0 == vec[ny][nx])
			{
				continue;
			}

			if (false == visited[ny][nx])
			{
				vec[ny][nx] = vec[y][x] + 1;
				visited[ny][nx] = true;
				q.push({ ny, nx });
			}
		}
	}

}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);	cout.tie(NULL);

	cin >> n >> m;

	vec.resize(n, vector<int>(m, 0));
	visited.resize(n, vector<bool>(m, false));

	for (int y = 0; y < n; y++)
	{
		for (int x = 0; x < m; x++)
		{
			cin >> vec[y][x];

			if (2 == vec[y][x])
			{
				q.push({ y, x });
				visited[y][x] = true;
				vec[y][x] = 0;	// target 변수에 값을 저장해 두고, 목표지점을 0으로 시작해서 값이 증가하도록 한다.
			}
		}
	}

	BFS();

	for (int y = 0; y < n; y++)
	{
		for (int x = 0; x < m; x++)
		{
			if (visited[y][x] == false && vec[y][x] == 1)
			{
				cout << -1 << " ";
				continue;
			}

			cout << vec[y][x] << " ";
		}
		cout << '\n';
	}

	return 0;
}

//15 5
//1 1 1 1 1 1 1 1 1 1 1 1 1 1 1
//1 1 1 1 1 1 1 1 1 1 0 0 0 0 0
//1 1 1 1 1 2 1 1 1 1 0 1 1 1 1
//1 1 1 1 1 1 1 1 1 1 0 1 0 0 0
//1 1 1 1 1 1 1 1 1 1 0 1 1 1 1
//1 1 1 1 1 1 1 1 1 1 0 1 1 1 1