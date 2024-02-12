#include <iostream>
#include <string>

using namespace std;

int main()
{
	std::ios::sync_with_stdio(false);
	std::cin.tie(NULL);

	string str{ "" };
	getline(cin, str);	// getline() 함수를 이용해 공백까지 받는다.

	int i{ 0 }, iCount{ 0 };

	while (str[i] != '\0')
	{
		if (str[i] != ' ' && (i == 0 || str[i - 1] == ' '))
		{
			iCount++;
		}
		i++;
	}

	cout << iCount << '\n';

	return 0;
}