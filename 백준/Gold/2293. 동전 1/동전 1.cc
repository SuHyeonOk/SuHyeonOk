#include <iostream>
#include <algorithm>
using namespace std;

int arr[101];
long dp[10001];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int N = 0, K = 0;
	cin >> N >> K;

	for (int i = 1; i <= N; i++)
	{
		cin >> arr[i];
	}

	dp[0] = 1;
	for (int i = 1; i <= N; i++) 
	{
		for (int j = arr[i]; j <= K; j++) 
		{
			dp[j] = dp[j] + dp[j - arr[i]];
		}
	}
	cout << dp[K];

	return 0;
}