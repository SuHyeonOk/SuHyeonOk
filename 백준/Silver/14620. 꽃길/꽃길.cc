#include <iostream>
#include <algorithm>
#include <climits>
#define MAX 10
using namespace std;

int N;
int Result = INT_MAX;
int map[MAX][MAX];
bool visited[MAX][MAX];

int dx[4] = { 0,0,-1,1 };
int dy[4] = { -1,1,0,0 };

void DFS(int _Sum, int _Depth) 
{
	if (_Depth == 3) 
	{
		Result = min(Result, _Sum); 
		return;
	}

	for (int i = 1; i < N; i++) 
	{
		for (int j = 1; j < N; j++) 
		{
			int check = 0;
			int nx = 0, ny = 0;

			for (int k = 0; k < 4; k++) // 4개의 꽃잎이 필 수 있는 경우인지 확인
			{
				nx = j + dx[k];
				ny = i + dy[k];

				if (nx < 0 || nx >= N || ny < 0 || ny >= N)
				{
					break;
				}

				if (true == visited[ny][nx])
				{
					break;
				}

				check++;
			}

			if (check == 4) 
			{
				int Temp = map[i][j];
				visited[i][j] = true; // 꽃잎이 겹치는지 확인하기 위해
				for (int k = 0; k < 4; k++) 
				{
					nx = j + dx[k];
					ny = i + dy[k];
					visited[ny][nx] = true;
					Temp += map[ny][nx];
				}

				_Depth++;
				_Sum += Temp;
				DFS(_Sum, _Depth);
				_Sum -= Temp;
				_Depth--;

				visited[i][j] = false; // DFS를 나오면서 꽃 하나 제거
				for (int k = 0; k < 4; k++) 
				{
					nx = j + dx[k];
					ny = i + dy[k];
					visited[ny][nx] = false;
				}
			}
		}
	}

}

int main() 
{
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> N;
	for (int i = 0; i < N; i++) 
	{
		for (int j = 0; j < N; j++) 
		{
			cin >> map[i][j];
		}
	}

	DFS(0, 0);

	cout << Result;

	return 0;
}