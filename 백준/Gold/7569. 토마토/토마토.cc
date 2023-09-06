#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int M{ 0 }, N{ 0 }, H{ 0 }, iDday{ 0 };
vector<vector<vector<int>>> vec;
vector<int> dx{ 0, 0, -1, 1 };
vector<int> dy{ -1, 1, 0, 0 };

typedef struct tagInfo
{
	int h{ 0 };
	int x{ 0 };
	int y{ 0 };
	int Dday{ 0 };

}INFO;
queue<INFO> q;

void BFS()
{
	while (false == q.empty())
	{
		int qH{ q.front().h };
		int qX{ q.front().x };
		int qY{ q.front().y };
		int qDday{ q.front().Dday };
		q.pop();

		if (iDday == qDday)
		{
			++iDday;
		}

		for (size_t i = 0; i < 2; i++)
		{
			int nextH{ qH + dy[i] };
			
			if (nextH < 0 || nextH >= H)
			{
				continue;
			}

			if (vec[nextH][qX][qY] == 0)
			{
				vec[nextH][qX][qY] = iDday;
				q.push({ nextH, qX , qY, qDday + 1 });
			}
		}

		for (size_t i = 0; i < 4; i++)
		{
			int nextX{ qX + dx[i] };
			int nextY{ qY + dy[i] };

			if (nextX >= N || nextX < 0 || nextY >= M || nextY < 0)
			{
				continue;
			}

			if (vec[qH][nextX][nextY] == 0)
			{
				vec[qH][nextX][nextY] = iDday;
				q.push({ qH, nextX , nextY, qDday + 1 });
			}
		}
	}

}

int main()
{
	cin >> M >> N >> H;

	vec.resize(H, vector<vector<int>>(N, vector<int>(M)));

	for (int k = 0; k < H; k++)
	{
		for (int i = 0; i < N; i++)
		{
			for (int j = 0; j < M; j++)
			{
				cin >> vec[k][i][j];

				if (vec[k][i][j] == 1)
				{
					q.push({ k, i, j, 0 });
				}
			}
		}
	}

	BFS();

	for (int k = 0; k < H; k++) 
	{
		for (int i = 0; i < N; i++)
		{
			for (int j = 0; j < M; j++)
			{
				if (vec[k][i][j] == 0)
				{
					cout << -1;
					return 0;
				}
			}
		}
	}

	cout << iDday - 1;

	return 0;
}