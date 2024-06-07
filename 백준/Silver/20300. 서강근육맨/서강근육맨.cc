#include <iostream>
#include <algorithm>
using namespace std;

long long N, Min;
long long t[10000];

void Comparison()
{
	for (int i = 0; i < N / 2; i++)
	{
		long long M = t[i] + t[(N - 1) - i];

		if (M > Min)
		{
			Min = M;
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
		cin >> t[i];
	}
	sort(t, t + N);

	if (N % 2 == 1) // 홀수
	{
		Min = t[N - 1];	// 마지막 가장 큰 값을 따로 저장
		N--;

		Comparison();
	}
	else // 짝수
	{
		Comparison();
	}

	cout << Min;

	return 0;
}