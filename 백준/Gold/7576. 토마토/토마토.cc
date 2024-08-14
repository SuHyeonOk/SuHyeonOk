#include <iostream>
#include <queue>
#include <algorithm>
#define MAX 1000
using namespace std;

typedef struct tagTomatoInfo
{
	int XPos = 0;
	int YPos = 0;
	int Day = 0;
}INFO;

int M, N, Max;
int arr[MAX][MAX];
bool visited[MAX][MAX];
queue<INFO> q;

int dx[4]{ 0, 0, -1, 1 };
int dy[4]{ -1, 1, 0, 0 };

void BFS()
{
	while (false == q.empty())
	{
		int X = q.front().XPos;
		int Y = q.front().YPos;
		int Count = q.front().Day + 1;
		Max = max(Max, Count);
		q.pop();

		for (int i = 0; i < 4; ++i)
		{
			int NX = X + dx[i];
			int NY = Y + dy[i];

			if (0 > NX || M <= NX || 0 > NY || N <= NY)
			{
				continue;
			}

			if (true == visited[NY][NX] || -1 == arr[NY][NX] || 1 == arr[NY][NX])
			{
				continue;
			}

			visited[NY][NX] = true;
			arr[NY][NX] = Count;
			q.push({ NX, NY,  Count});
		}
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> M >> N;

	for (int y = 0; y < N; ++y)
	{
		for (int x = 0; x < M; ++x)
		{
			cin >> arr[y][x];

			if (1 == arr[y][x])
			{
				q.push({ x, y, 0 });
				visited[y][x] = true;
			}
		}
	}

	BFS();

	for (int y = 0; y < N; ++y)
	{
		for (int x = 0; x < M; ++x)
		{
			if (0 == arr[y][x])
			{
				cout << -1;
				return 0;
			}
		}
	}

	cout << Max - 1;

	return 0;
}