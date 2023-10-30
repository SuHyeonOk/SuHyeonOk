#include <iostream>
#include <queue>
#include <string.h>
using namespace std;
#define MAX 101
#define FOUR 4

int N{ 0 }, M{ 0 }, cheese_count{ 0 };
int arr[MAX][MAX];
bool visited[MAX][MAX];

int dx[FOUR]{ 0, 0, -1, 1 };
int dy[FOUR]{ -1, 1, 0, 0 };

bool BFS()
{
	queue<pair<int, int>> q;
	q.push({ 0, 0, });
	visited[0][0] = true;
	int temp_cheese_count{ 0 };

	while (false == q.empty())
	{
		int x{ q.front().first };
		int y{ q.front().second };
		q.pop();

		for (int i = 0; i < FOUR; i++)
		{
			int nx{ x + dx[i] };
			int ny{ y + dy[i] };

			if (0 > nx || M <= nx || 0 > ny || N <= ny)
			{
				continue;
			}

			if (true == visited[ny][nx])
			{
				continue;
			}

			if (0 == arr[ny][nx]) // 공기라면 계속 탐색
			{
				q.push({ nx, ny });
			}
			else // 치즈라면 해당 치즈를 0으로 바꾸고, temp_cheese_count 증가
			{
				arr[ny][nx] = 0;
				++temp_cheese_count;
			}

			visited[ny][nx] = true;
		}
	}

	if (0 == temp_cheese_count) // 더 이상 치즈가 없다면, 이전 BFS에서 나온 치즈의 개수를 출력하고 main의 while문 중단
	{
		return true;
	}
	else // 치즈가 있다면, 해당 time의 치즈 수 갱신
	{
		cheese_count = temp_cheese_count;
		return false;
	}

}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

	cin >> N >> M;

	for (int y = 0; y < N; y++)
	{
		for (int x = 0; x < M; x++)
		{
			cin >> arr[y][x];
		}
	}

	int end_time{ 0 };
	while (false == BFS())
	{
		++end_time;
		memset(visited, false, sizeof(visited));
	}

	cout << end_time << "\n" << cheese_count;

    return 0;
}