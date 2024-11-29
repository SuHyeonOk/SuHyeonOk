#include <iostream>
using namespace std;

int main() 
{
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	long long A = 0, B = 0;
	cin >> A >> B;

	if (B >= A) 
	{
		if (A == B)
		{
			cout << 0;
		}
		else 
		{
			cout << B - A - 1 << '\n';
			for (long long i = A + 1; i < B; i++) 
			{
				cout << i << ' ';
			}
		}
	}
	else if (A > B) 
	{
		cout << A - B - 1 << '\n';
		for (long long i = B + 1; i < A; i++) 
		{
			cout << i << ' ';
		}
	}
	else 
	{
		cout << 0;
	}

	return 0;
}