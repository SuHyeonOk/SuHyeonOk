#include <iostream>
using namespace std;

int main() 
{
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int dp[11] = { 0, };
	int n; 
    cin >> n;
	
	dp[1] = 0;
	dp[2] = 1;
	
	for (int i = 3; i <= n; i++) 
    {
		int div = i / 2;
		dp[i] = (div * (i - div)) + dp[div] + dp[i - div];
	}

	cout << dp[n] << '\n';
    
    return 0;
}