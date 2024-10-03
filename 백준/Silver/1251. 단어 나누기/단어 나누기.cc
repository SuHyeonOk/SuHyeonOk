#include <iostream>
using namespace std;

int main() 
{
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	string Input;
	cin >> Input;

	string Result = "z";
	int Length = Input.length();
	for (int i = 0; i < Length - 2; i++)
	{
		for (int j = i + 1; j < Length - 1; j++)
		{
			string Temp = "";
			for (int k = i; k >= 0; k--)
			{
				Temp += Input[k];
			}
			for (int k = j; k > i; k--)
			{
				Temp += Input[k];
			}
			for (int k = Length - 1; k > j; k--)
			{
				Temp += Input[k];
			}

			if (Result > Temp) 
			{
				Result = Temp;
			}
		}
	}

	cout << Result;

	return 0;
}