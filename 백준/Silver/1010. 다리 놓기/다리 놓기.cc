#include<iostream>
using namespace std;

int main() 
{
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int T = 0;
	cin >> T;

	while(T--)
	{
		int N = 0, M = 0;
		cin >> N >> M;

		long Answer = 1;
		int n = 1;
		for (int i = M; i > M - N; i--) 
		{
			Answer *= i;
			Answer /= n;
			n++;
		}

		cout << Answer << "\n";
	}
	return 0;
}