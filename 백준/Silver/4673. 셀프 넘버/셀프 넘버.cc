#include <iostream>
#include <array>

using namespace std;

#define MAX 10001
array<bool, MAX> arr{false};

void d(int num)
{
	int result{ num };
	while (num)
	{
		result += num % 10;
		num /= 10;
	}

	if (result < MAX)
	{
		arr[result] = true;
	}
}

int main()
{
	for (int i = 1; i < MAX; i++)
	{
		d(i);
	}

	for (int i = 1; i < MAX; i++)
	{
		if (false == arr[i])
		{
			cout << i << '\n';
		}
	}
	

	return 0;
}