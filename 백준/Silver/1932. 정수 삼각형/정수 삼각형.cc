#include <iostream>
#include <algorithm>
using namespace std;

int main() 
{
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	int N = 0;
	cin >> N;

	int arr[505][505];
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < i + 1; j++)
		{
			cin >> arr[i][j];
		}
	}

	for (int i = N - 1; i >= 1; i--)
	{
		for (int j = 0; j < i; j++)
		{
			arr[i - 1][j] += max(arr[i][j], arr[i][j + 1]);
		}
	}

	cout << arr[0][0];

	return 0;
}