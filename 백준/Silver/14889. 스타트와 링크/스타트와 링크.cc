#include<iostream>
using namespace std;

int N, Min = 101;
int arr[21][21];
bool visited[22];

void DFS(int _Depth, int _Next) // _Depth는 카운트 수, _Next는 다음 값
{
	if (_Depth == N / 2) // 카운트수가 정원의 1/2이 됐을 때 능력치합 계산
	{
		int Start = 0, Link = 0;

		for (int i = 1; i <= N; i++)
		{
			for (int j = 1; j <= N; j++)
			{
				if (visited[i] == true && visited[j] == true)
				{
					Start += arr[i][j];
				}
				if (visited[i] == false && visited[j] == false)
				{
					Link += arr[i][j];
				}
			}
		}

		int Temp = abs(Start - Link);
		if (Min > Temp)
		{
			Min = Temp;
		}

		return;
	}

	for (int i = _Next; i < N; i++)
	{
		visited[i] = true;
		DFS(_Depth + 1, i + 1);
		visited[i] = false;
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> N;

	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= N; j++)
		{
			cin >> arr[i][j];
		}
	}

	DFS(0, 1); // 카운트 0회부터 숫자는 1부터 시작
	cout << Min;

	return 0;
}