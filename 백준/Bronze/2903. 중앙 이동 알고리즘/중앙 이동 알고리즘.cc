#include<iostream>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int Repeat = 0;
	cin >> Repeat;

	int Result = 2;
	while (Repeat--)
	{
		Result = (Result * 2) - 1;
	}

	cout << Result * Result;

	return 0;
}