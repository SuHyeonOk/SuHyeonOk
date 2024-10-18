#include <iostream>
#include <algorithm>
using namespace std;

char anipang[51][51];

//이미 한 번 바꿨을 경우와, 한 번도 안 바꿨을 경우를 고려해준다.
int arr[2];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int N;
	cin >> N;

	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= N; j++)
		{
			char c;
			cin >> c;
			anipang[i][j] = c;
		}
	}

	int M = 1;

	//가로에 대해서 먼저 조사

	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= N; j++)
		{
			arr[0] = 1;
			arr[1] = 1;
			char basicWord = anipang[i][j];
			for (int k = j + 1; k <= N; k++)
			{
				if (basicWord == anipang[i][k])
				{
					arr[0]++;
					arr[1]++;
				}
				else if (basicWord == anipang[i + 1][k] || basicWord == anipang[i - 1][k])
				{
					arr[1] = arr[0] + 1;
					arr[0] = 0;
				}
				else if (basicWord == anipang[i][k - 1] && anipang[i][k - 1] == anipang[i][k + 1])
				{
					arr[1] = arr[0] + 1;
					M = max({ M,arr[0], arr[1] });
					arr[1] = 1;
					arr[0] = 0;
				}
				else
				{
					//p p p c p p p p
					//c c p c c p
					arr[1] = 0;
					arr[0] = 0;
				}
				M = max({ M,arr[0], arr[1] });
			}
		}
	}

	//세로에 대한 조사
	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= N; j++)
		{
			arr[0] = 1;
			arr[1] = 1;
			char basicWord = anipang[j][i];
			for (int k = j + 1; k <= N; k++)
			{
				if (basicWord == anipang[k][i])
				{
					arr[0]++;
					arr[1]++;
				}
				else if (basicWord == anipang[k][i + 1] || basicWord == anipang[k][i - 1])
				{
					arr[1] = arr[0] + 1;
					arr[0] = 0;
				}
				else if (basicWord == anipang[k + 1][i] && anipang[k + 1][i] == anipang[k - 1][i])
				{
					arr[1] = arr[0] + 1;
					M = max({ M,arr[0], arr[1] });
					arr[1] = 1;
					arr[0] = 0;
				}
				else
				{
					arr[1] = 0;
					arr[0] = 0;
				}

				M = max({ M,arr[0], arr[1] });
			}
		}
	}

	cout << M;


	return 0;
}