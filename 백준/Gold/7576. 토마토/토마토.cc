#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int M{ 0 }, N{ 0 }, iDday{ 0 };
vector<vector<int>> vec;
vector<int> dx{ 0, 0, -1, 1 };
vector<int> dy{ -1, 1, 0, 0 };

typedef struct tagInfo
{
	int x{ 0 };
	int y{ 0 };
	int Dday{ 0 };

}INFO;
queue<INFO> q;

void BFS()
{
	while (false == q.empty())
	{
		int qX{ q.front().x };
		int qY{ q.front().y };
		int qDday{ q.front().Dday };
		q.pop();

		if (iDday == qDday)
		{
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

			if (vec[nextX][nextY] == 0)
			{
				vec[nextX][nextY] = iDday;
				q.push({ nextX , nextY, qDday + 1 });
			}
		}
	}

}

int main()
{
	cin >> M >> N;

	vec.resize(N, vector<int>(M, 0));

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			cin >> vec[i][j];

			if (vec[i][j] == 1)
			{
				q.push({ i, j, 0 });
			}
		}
	}

	BFS();

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			if (vec[i][j] == 0)
			{
				cout << -1;
				return 0;
			}
		}
	}
	
	cout << iDday - 1;

	return 0;
}