#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int M{ 0 }, N{ 0 }, iDday{ 0 };
vector<vector<int>> vec;
vector<vector<int>> visited;
vector<pair<int, int>> OnePos;
vector<int> dx{ 0, 0, -1, 1 };
vector<int> dy { -1, 1, 0, 0 };

typedef struct tagInfo
{
	int x{ 0 };
	int y{ 0 };
	int Dday{ 0 };

}INFO;

void BFS()
{
	queue<tagInfo> q;

	size_t size = OnePos.size();
	for (size_t i = 0; i < size; i++)
	{
		q.push({ OnePos[i].first, OnePos[i].second, iDday });
	}

	while (false == q.empty())
	{
		int qX{ q.front().x };
		int qY{ q.front().y };
		int qDday{ q.front().Dday };
		q.pop();

		if (iDday == qDday)
		{
			//for (int i = 0; i < N; i++)
			//{
			//	for (int j = 0; j < M; j++)
			//	{
			//		cout << visited[i][j] << " ";
			//	}
			//	cout << '\n';
			//}
			//cout << "***************************************" << iDday << '\n';

			++iDday;
		}

		for (int i = 0; i < 4; i++)
		{
			int nextX{ qX + dx[i] };
			int nextY{ qY + dy[i] };

			if (nextX >= N || nextX < 0 || nextY >= M || nextY < 0)
			{
				continue;
			}

			if (vec[nextX][nextY] == -1 || visited[nextX][nextY] != 0)
			{
				continue;
			}

			visited[nextX][nextY] = iDday;
			vec[nextX][nextY] = iDday;
			q.push({ nextX , nextY, qDday + 1 });
		}
	}

}

bool ZeroFine()
{
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			if (vec[i][j] == 0)
			{
				return true;
			}
		}
	}
	return false;
}

int main()
{
	cin >> M >> N;

	vec.resize(N, vector<int>(M, 0));
	visited.resize(N, vector<int>(M, 0));

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			cin >> vec[i][j];

			if (vec[i][j] == 1)
			{
				OnePos.push_back({ i, j });
				visited[i][j] = true;
			}
		}
	}

	BFS();

	if (true == ZeroFine())
	{
		// 토마토를 다 익히지 못했을때
		cout << -1;
	}
	else
	{
		cout << iDday - 1;
	}

	return 0;
}