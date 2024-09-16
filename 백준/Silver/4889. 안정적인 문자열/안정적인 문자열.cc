#include <iostream>
#include <stack>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

	string Input;
	int Num = 0, Count = 0;

	while (true) 
	{
		cin >> Input;
		if (Input[0] == '-')
		{
			break;
		}

		Count = 0;
		size_t Length = Input.length();
		stack<char> s;
		for (size_t i = 0; i < Length; i++)
		{
			char c = Input[i];
			if (c == '}' && false == s.empty() && s.top() == '{')
			{
				s.pop();
			}
			else
			{
				s.push(c);
			}
		}

		while (false == s.empty()) 
		{
			char c1 = s.top();
			s.pop();
			char c2 = s.top();
			s.pop();

			if (c1 == c2)
			{
				Count++;
			}
			else
			{
				Count += 2;
			}
		}

		Num++;
		cout << Num << ". " << Count << '\n';
	}

    return 0;
}