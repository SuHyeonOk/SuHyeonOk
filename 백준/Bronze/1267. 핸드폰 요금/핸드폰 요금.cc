#include <iostream>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int N = 0;
	cin >> N;

	int temp = 0, m = 0, y = 0;
	for (int i = 0; i < N; i++) 
	{
		cin >> temp;
		y += (temp / 30 + 1) * 10;
		m += (temp / 60 + 1) * 15;
	}

	if (m < y)
	{
		cout << "M " << m;
	}
	else if (m > y)
	{
		cout << "Y " << y;
	}
	else if (m == y)
	{
		cout << "Y M " << m;
	}

	return 0;
}