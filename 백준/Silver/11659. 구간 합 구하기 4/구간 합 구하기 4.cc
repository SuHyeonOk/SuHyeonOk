#include <iostream>
#include <vector>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);	cout.tie(NULL);

	int N{ 0 }, M{ 0 };
	cin >> N >> M;

	vector<int> vec;
	vec.resize(N + 1);
	
	for (size_t i = 1; i <= N; i++)
	{
		cin >> vec[i];
		vec[i] += vec[i - 1];
	}

	int i{ 0 }, j{ 0 };
	for (int x = 0; x < M; x++)
	{
		cin >> i >> j;
		cout << vec[j] - vec[i - 1] << '\n';
	}

	return 0;
}