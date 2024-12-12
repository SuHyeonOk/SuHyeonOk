#include <iostream>
#include <stack>
using namespace std;

stack<int> S;
int N, T, cnt = 1;

int main() 
{
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> N; 
	while (N--) 
	{
		cin >> T;

		if (T == cnt)
		{
			cnt++;
		}
		else
		{
			S.push(T);
		}

		while (!S.empty() && S.top() == cnt) 
		{
			S.pop(); 
			cnt++;
		}
	}

	if (true == S.empty())
	{
		cout << "Nice";
	}
	else
	{
		cout << "Sad";
	}

	return 0;
}