#include <iostream>
#include <vector>
#include <array>
#include <algorithm>

using namespace std;

#define FOUR 4

int N{ 0 }, iCount{ 0 }, iMax{ 0 }, iHight{ 0 }, iTargetX{ 0 }, iTargetY{ 0 };
vector<vector<int>> vec;
vector<vector<bool>> visited;

array<int, 4> dx{ 0,0,-1,1 };
array<int, 4> dy{ -1,1,0,0 };

void DFS(const int _x, const int _y)
{
	visited[_x][_y] = true;

	for (int i = 0; i < FOUR; i++)
	{
		int nx = _x + dx[i];
		int ny = _y + dy[i];

		if (nx < 0 || nx >= N || ny < 0 || ny >= N)
		{
			continue;
		}

		if (iHight >= vec[nx][ny])
		{
			continue;
		}

		if (visited[nx][ny] == false)
		{
			visited[nx][ny] = true;
			DFS(nx, ny);
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
			DFS(iTargetX, iTargetY);
		}

	}

	cout << iMax;

	return 0;
}