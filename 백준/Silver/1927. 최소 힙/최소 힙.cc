#include <iostream>
#include <queue>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	
	int N{ 0 }, x{ 0 };
	cin >> N;

	priority_queue<int, vector<int>, greater<int>> q;

	for (int i = 0; i < N; i++)
	{
		cin >> x;

		if (0 == x)
		{
			if (q.empty() == true)
			{
				cout << 0 << '\n';
			}
			else
			{
				cout << q.top() << '\n';
				q.pop();
			}

			continue;
		}
		
		q.push(x);
	}


	return 0;
}