#include <iostream>
using namespace std;

int main() 
{
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int arr[3];
	int Ans = 1;
	bool Even = false;

	for (int i = 0; i < 3; i++) 
	{
		cin >> arr[i];

		if (arr[i] % 2 != 0) // 홀수 일 때만 계산
		{
			Ans *= arr[i];
			Even = true;
		}
	}

	if (Even == true) // 홀수가 하나라도 있다면 홀수를 계산한 결과
	{
		cout << Ans;
	}
	else // 모두가 짝수일 때만 다음으로 계산
	{
		cout << arr[0] * arr[1] * arr[2];
	}

	return 0;
}