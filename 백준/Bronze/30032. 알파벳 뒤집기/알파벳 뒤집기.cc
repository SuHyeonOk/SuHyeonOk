#include <iostream>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int N = 0, D = 0;
	cin >> N >> D;

	string Input = "";
	while (N--)
	{
		cin >> Input;
		size_t length = Input.length();

		if (D == 1)
		{
			for (size_t i = 0; i < length; ++i)
			{
				if ('d' == Input[i])
				{
					Input[i] = 'q';
				}
				else if ('b' == Input[i])
				{
					Input[i] = 'p';
				}
				else if ('q' == Input[i])
				{
					Input[i] = 'd';
				}
				else if ('p' == Input[i])
				{
					Input[i] = 'b';
				}
			}
		}
		else if (D == 2)
		{
			for (size_t i = 0; i < length; ++i)
			{
				if ('d' == Input[i])
				{
					Input[i] = 'b';
				}
				else if ('b' == Input[i])
				{
					Input[i] = 'd';
				}
				else if ('q' == Input[i])
				{
					Input[i] = 'p';
				}
				else if ('p' == Input[i])
				{
					Input[i] = 'q';
				}
			}
		}

		cout << Input << '\n';
	}
	return 0;
}