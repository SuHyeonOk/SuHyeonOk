#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);	cout.tie(NULL);

	int N{ 0 }, Time{ 0 };
	cin >> N;

	vector<pair<int, int>> vec;
	vec.reserve(N + 1);
	
	for (int i = 1; i <= N; i++)
	{
		cin >> Time;
		vec.push_back({ Time, i });
	}

	sort(vec.begin(), vec.end());

	int Temp{ 0 }, Result{ 0 };
	for (int i = 0; i < N; i++)
	{
		Temp += vec[i].first;
		Result += Temp;
	}

	cout << Result;

	return 0;
}