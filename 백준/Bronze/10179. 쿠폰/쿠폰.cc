#include <iostream>
#include <cmath>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int TestCase = 0;
	cin >> TestCase;

	cout << fixed;
	cout.precision(2);
	
	double N = 0;
	while (TestCase--)
	{
		cin >> N;

		cout << "$" << N * 0.8 << '\n';
	}

	return 0;
}