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

void DFS(int sum, int cnt) 
{
	if (cnt == 3) 
	{
		Result = min(Result, sum); 
		return;
	}

	for (int i = 0; i < N; i++) 
	{
		for (int j = 0; j < N; j++) 
		{
			int check = 0;
			int nx = 0, ny = 0;

			for (int k = 0; k < 4; k++) 
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
				int ssum = map[i][j];
				for (int k = 0; k < 4; k++) 
				{
					nx = j + dx[k];
					ny = i + dy[k];
					visited[ny][nx] = true;
					ssum += map[ny][nx];
				}

				visited[i][j] = true;
				sum += ssum;
				cnt++;
				DFS(sum, cnt);
				sum -= ssum;
				cnt--;

				for (int k = 0; k < 4; k++) 
				{
					nx = j + dx[k];
					ny = i + dy[k];
					visited[ny][nx] = 0;
				}

				visited[i][j] = false;
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