#include <iostream>
#include <vector>
#include <algorithm>
#include <string.h>
using namespace std;

int N, M;
int arr[500][500];
int dir[4][2] = { {0,1} ,{0,-1},{1,0},{-1,0} };
bool visited[500][500];
int Result;

bool isInside(int r, int c) 
{
	if (r < 0 || r >= N || c < 0 || c >= M)
	{
		return false;
	}
	return true;
}

void DFS(int r, int c, int depth, int sum) 
{
	if (depth == 3) 
	{
		Result = max(Result, sum);
		return;
	}

	for (int i = 0; i < 4; i++) 
	{
		int nR = r + dir[i][0];
		int nC = c + dir[i][1];

		if (false == isInside(nR, nC))
		{
			continue;
		}
		if (visited[nR][nC])
		{
			continue;
		}

		visited[nR][nC] = true;
		DFS(nR, nC, depth + 1, sum + arr[nR][nC]);
		visited[nR][nC] = false;
	}
}

void Case1(int r, int c)
{
	int sum = 0;
	sum = arr[r][c] + arr[r][c + 1] + arr[r][c + 2] + arr[r - 1][c + 1];
	Result = max(Result, sum);
}

void Case2(int r, int c)
{
	int sum = 0;
	sum = arr[r][c] + arr[r][c + 1] + arr[r][c + 2] + arr[r + 1][c + 1];
	Result = max(Result, sum);
}

void Case3(int r, int c)
{
	int sum = 0;
	sum = arr[r][c] + arr[r + 1][c] + arr[r + 2][c] + arr[r + 1][c + 1];
	Result = max(Result, sum);
}

void case4(int r, int c)
{
	int sum = 0;
	sum = arr[r][c] + arr[r - 1][c + 1] + arr[r][c + 1] + arr[r + 1][c + 1];
	Result = max(Result, sum);
}

int main() 
{
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> N >> M;
	for (int i = 0; i < N; i++) 
	{
		for (int j = 0; j < M; j++) 
		{
			cin >> arr[i][j];
		}
	}

	for (int i = 0; i < N; i++) 
	{
		for (int j = 0; j < M; j++) 
		{
			visited[i][j] = true;
			DFS(i, j, 0, arr[i][j]);
			visited[i][j] = false;

			if (i - 1 >= 0 && j + 2 < M)
			{
				Case1(i, j);
			}
			if (j + 2 < M && i + 1 < N)
			{
				Case2(i, j);
			}
			if (i + 2 < N && j + 1 < M)
			{
				Case3(i, j);
			}
			if (i + 1 < N && i - 1 >= 0 && j + 1 < M)
			{
				case4(i, j);
			}
		}
	}

	cout << Result;

	return 0;
}