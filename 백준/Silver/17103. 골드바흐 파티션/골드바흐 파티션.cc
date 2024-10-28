#include <iostream>
#define MAX 1000001
using namespace std;

bool arr[MAX];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	// 1. 소수 판별 배열 초기화
	for (int i = 0; i < MAX; i++)
	{
		arr[i] = true;
	}
	arr[0] = arr[1] = false; // 0과 1은 소수가 아님

	// 2. 에라토스테네스의 체: 소수를 판별하여 arr에 저장
	for (int i = 2; i * i < MAX; i++)
	{
		if (false == arr[i])
		{
			continue; // i가 소수가 아니면 다음으로
		}
		for (int j = i * 2; j < MAX; j += i)
		{
			arr[j] = false; // i의 배수는 소수가 아님
		}
	}

	// 3. 입력 및 골드바흐 파티션 계산
	int T = 0;
	cin >> T;
	while (T--)
	{
		int N = 0;
		cin >> N;

		int Count = 0;
		// N = a + b를 만족하는 소수 쌍 (a, b) 찾기
		for (int i = 2; i <= N / 2; i++)
		{
			if (arr[i] && arr[N - i]) // i와 N - i가 모두 소수이면
			{
				Count++;
			}
		}
		cout << Count << '\n';
	}

	return 0;
}