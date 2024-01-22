#include <iostream>
using namespace std;

int main() 
{
	int N = 0;
	int F = 0;
	cin >> N >> F;

	N = N - (N % 100);

	int temp = N;
	while (true)
	{
		if (temp % F == 0)
		{
			if (temp % 100 < 10) // 뒤 두자리 값이 10보다 작은지 확인
			{
				cout << '0'; // 10보다 작다면 앞에 '0'을 붙여줘야함
			}

			cout << temp % 100;
			break;
		}
		
		++temp;
	}

	return 0;
}