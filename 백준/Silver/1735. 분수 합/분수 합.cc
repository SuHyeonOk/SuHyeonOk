#include<iostream>
using namespace std;

int GCD(int a, int b)
{
	if (b == 0)
	{
		return a;
	}

	return GCD(b, a % b);
}

int main() 
{
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int A = 0, B = 0, C = 0, D = 0;
	cin >> A >> B;
	cin >> C >> D;

	int All = (A * D) + (B * C);
	int Denominator = (B * D);
	int Result = GCD(All, Denominator);

	cout << All / Result << " " << Denominator / Result;

	return 0;
}