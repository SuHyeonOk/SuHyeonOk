#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	int N{ 0 };
	cin >> N;

	vector<int> vec;
	vec.resize(N + 1, 0);

	for (int i = 2; i <= N; i++)
	{
		vec[i] = vec[i - 1] + 1;
		if (i % 3 == 0)
		{
			vec[i] = min(vec[i], vec[i / 3] + 1);
		}
		if (i % 2 == 0)
		{
			vec[i] = min(vec[i], vec[i / 2] + 1);
		}
	}

	cout << vec[N] << '\n';

	return 0;
}