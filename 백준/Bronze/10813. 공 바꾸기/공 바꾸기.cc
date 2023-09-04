#include <iostream>
#include <vector>
using namespace std;

int main()
{
	int N{ 0 }, M{ 0 };
	cin >> N >> M;

	vector<int>  ns(N + 1);
	for (int i = 1; i <= N; i++)
	{
		ns[i] = i;
	}

	int a{ 0 }, b{ 0 }, c{ 0 };
	for (int i = 0; i < M; i++)
	{
		cin >> a >> b;

		c = ns[a];
		ns[a] = ns[b];
		ns[b] = c;
	}

	for (int i = 1; i <= N; i++)
	{
		cout << ns[i] << " ";
	}

	return 0;
}