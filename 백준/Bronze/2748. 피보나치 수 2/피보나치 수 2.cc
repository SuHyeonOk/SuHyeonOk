#include <iostream>
#include <array>
using namespace std;

#define MAX 91

int main()
{
	int n{ 0 };
	cin >> n;

	array<long long, MAX> arr;
	arr[0] = 0;
	arr[1] = 1;

	for (int i = 2; i <= n; i++)
	{
		arr[i] = arr[i - 1] + arr[i - 2];
	}

	cout << arr[n];

	return 0;
}