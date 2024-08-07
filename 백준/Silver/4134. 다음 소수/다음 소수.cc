#include <iostream>
#include <cmath>
using namespace std;

bool IsDecimal(unsigned int N)
{
	if (N < 2)
	{
		return false; // 2보다 작은 경우 소수 아님
	}

	int SqrtN = sqrt(N);
	for (unsigned int i = 2; i <= SqrtN; i++)
	{
		if (0 == N % i)
		{
			return false; // 나눠지면 소수 아님
		}
	}

	return true; // 소수
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int TestCase = 0;
	cin >> TestCase;

	unsigned int N = 0;
	while (TestCase--)
	{
		cin >> N;

		while (false == IsDecimal(N))
		{
			++N; // 소수가 아닌 경우 ++을 통해 다음 수를 계산
		}
		cout << N << '\n';
	}

	return 0;
}