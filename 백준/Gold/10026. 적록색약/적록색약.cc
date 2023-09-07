#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N{ 0 }, result{ 0 };
vector<vector<char>> vec;
vector<vector<bool>> visited;
vector<int> dx{ 0, 0, -1, 1 };
vector<int> dy{ -1, 1, 0, 0 };
char current{ ' ' };

void DFS(int _x, int _y)
{
	for (int i = 0; i < 4; i++)
	{
		int nx{ _x + dx[i] }, ny{ _y + dy[i] };

		if (nx < 0 || nx >= N || ny < 0 || ny >= N)
		{
			continue;
		}

		if (true == visited[nx][ny] || current != vec[nx][ny])
		{
			continue;
		}

		visited[nx][ny] = true;
		DFS(nx, ny);
	}
}

int main()
{
	cin >> N;

	vec.resize(N, vector<char>(N));
	visited.resize(N, vector<bool>(N));

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			cin >> vec[i][j];
		}
	}

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			if (false == visited[i][j])
			{
				current = vec[i][j];
				++result;
				DFS(i, j);
			}
		}
	}

	cout << result << " ";
	result = 0;

	for (int i = 0; i < N; i++)
	{
		fill(visited[i].begin(), visited[i].end(), false);
	}


	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			if ('G' == vec[i][j])
			{
				vec[i][j] = 'R';
			}
		}
	}

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			if (false == visited[i][j])
			{
				current = vec[i][j];
				++result;
				DFS(i, j);
			}
		}
	}

	cout << result;

	return 0;
}