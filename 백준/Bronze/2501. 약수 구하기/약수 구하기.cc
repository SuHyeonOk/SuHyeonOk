#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() 
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int N{ 0 }, K{ 0 };
	cin >> N >> K;
	
	vector<int> vec;
	for (int i = 1; i <= N; i++)
	{
		if (0 == N % i)
		{
			vec.push_back(i);
		}
	}

	sort(vec.begin(), vec.end());

	if (vec.size() < K)
	{
		cout << 0 << '\n';
	}
	else
	{
		cout << vec[K - 1] << '\n';
	}

	return 0;
}