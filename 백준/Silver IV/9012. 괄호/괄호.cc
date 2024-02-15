#include <iostream>
#include<string>
#include<stack>
using namespace std;

int main()
{
	short T{ 0 };
	string str{ "" };

	cin >> T;
	while (T--)
	{
		cin >> str;
		stack<char> sta;

		for (size_t i = 0; i < str.length(); i++)
		{
			if (str[i] == '(') sta.push('(');

			if (str[i] == ')')
			{
				if (!sta.empty()) sta.pop();
				else { cout << "NO" << "\n"; str = "NO";  break; }
			}
		}

		if (str == "NO") continue;
		if (sta.empty()) cout << "YES" << "\n";
		else cout << "NO" << "\n";
	}

	return 0;
}