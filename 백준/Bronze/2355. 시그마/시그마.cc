#include <iostream>
using namespace std;

int main() 
{
	long A = 0, B = 0;
	cin >> A >> B;

	long Temp = 0;
	if (A < B)
	{
		Temp = B;
		B = A;
		A = Temp;
	}

	cout << (A + B) * (A - B + 1) / 2;

	return 0;
}