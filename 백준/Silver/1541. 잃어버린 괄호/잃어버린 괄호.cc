#include <iostream>
#include <string.h>

using namespace std;

int main()
{
	int lenght{ 0 }, temp{ 0 }, sum{ 0 };
	bool flag{ false };
	char str[51];

	cin >> str;
	lenght = strlen(str);

	for (int i = 0; i <= lenght; i++)
	{
		if (str[i] == '+' || str[i] == '-' || i == lenght)
		{
			if (flag == false)
			{
				sum += temp;
				temp = 0;
			}
			else
			{
				sum -= temp;
				temp = 0;
			}

			if (str[i] == '-')
			{
				flag = true;
			}
		}
		else
		{
			temp *= 10;
			temp += str[i] - '0';
		}
	}

	cout << sum;

	return 0;
}