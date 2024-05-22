#include <iostream>
using namespace std;

int gcd(int a, int b) // 최대공약수 (유클리드 호제법)
{
	int r = a % b;
	if (r == 0) 
	{
		return b;
	}
	else 
	{
		return gcd(b, r);
	}
}

int main() 
{
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int T = 0;
	cin >> T;

	int Ans = 0;
	int A = 0, B = 0;
	for (int i = 0; i < T; i++) 
	{
		cin >> A >> B;

		// 최소공배수 = (A x B) / 최대공약수
		Ans = (A * B) / (gcd(A, B));
		cout << Ans << '\n';
	}

	return 0;
}