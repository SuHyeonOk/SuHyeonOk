#include <iostream>
using namespace std;

int main() 
{
	long A = 0, B = 0;
	cin >> A >> B;

	if (A < B)
	{
		cout << (B + A) * (B - A + 1) / 2;
		return 0;
	}

	cout << (A + B) * (A - B + 1) / 2;

	return 0;
}