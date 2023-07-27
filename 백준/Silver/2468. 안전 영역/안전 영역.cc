#include <iostream>
#include <vector>
#include <array>
#include <queue>
#include <algorithm>

using namespace std;

#define FOUR 4

int N{ 0 }, iCount{ 0 }, iMax{ 0 }, iHight{ 0 }, iTargetX{ 0 }, iTargetY{ 0 };
vector<vector<int>> vec;
vector<vector<bool>> visited;

void BFS(const int _x, const int _y)
{
	array<int, 4> dx{ 0,0,-1,1 };
	array<int, 4> dy{ -1,1,0,0 };

	queue<pair<int, int>> q;
	q.push({ _x, _y });
	visited[_x][_y] = true;

	while (false == q.empty())
	{
		int x = q.front().first;
		int y = q.front().second;
		q.pop();

		for (int i = 0; i < FOUR; i++)
		{
			int nx = x + dx[i];
			int ny = y + dy[i];

			if (nx < 0 || nx >= N || ny < 0 || ny >= N)
			{
				continue;
			}

			if (iHight >= vec[nx][ny])
			{
				continue;
			}

			if (false == visited[nx][ny])
			{
				visited[nx][ny] = true;
				q.push({ nx, ny });
			}
		}

	}

}

bool FIndGround()
{
	for (int x = 0; x < N; x++)
	{
		for (int y = 0; y < N; y++)
		{
			if (false == visited[x][y] && iHight < vec[x][y])
			{
				iTargetX = x;
				iTargetY = y;
				return false;
			}
		}
	}

	return true;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);	cout.tie(NULL);

	cin >> N;

	vec.resize(N, vector<int>(N, 0));
	visited.resize(N, vector<bool>(N, 0));

	for (int x = 0; x < N; x++)
	{
		for (int y = 0; y < N; y++)
		{
			cin >> vec[x][y];
		}
	}

	for (int i = 0; i <= 100;)
	{
		if (true == FIndGround())
		{
			i++;
			iHight = i;
			fill(visited.begin(), visited.end(), vector<bool>(N, false));
			iMax = max(iMax, iCount);
			iCount = 0;
		}
		else
		{
			iCount++;
			BFS(iTargetX, iTargetY);
		}

	}

	cout << iMax;

	return 0;
}
