#include<iostream> 
#include<stack>
using namespace std;

int main()
{
	string Str;
	cin >> Str;

	stack<char> s;
	int Result = 0, Score = 1;

	size_t Lenght = Str.length();
	for (size_t i = 0; i < Lenght; i++)
	{
		if (Str[i] == '(')
		{
			Score *= 2;
			s.push('(');
		}
		else if (Str[i] == '[')
		{
			Score *= 3;
			s.push('[');
		}
		else if (Str[i] == ')')
		{
			// 스택이 비어있거나, 이전 값이 '('가 아닌데 ')' 가 들어왔다? 잘못된 괄호열
			if (true == s.empty() || s.top() != '(') 
			{
				Result = 0;
				break;
			}

			if (Str[i - 1] == '(')
			{
				Result += Score; // 연결된 괄호
			}

			Score /= 2; // 띄어진 괄호
			s.pop();
		}
		else if (Str[i] == ']')
		{
			if (true == s.empty() || s.top() != '[')
			{
				Result = 0;
				break;
			}

			if (Str[i - 1] == '[')
			{
				Result += Score;
			}

			Score /= 3;
			s.pop();
		}
	}

	if (false == s.empty())
	{
		Result = 0;
	}
	cout << Result;

	return 0;
}
