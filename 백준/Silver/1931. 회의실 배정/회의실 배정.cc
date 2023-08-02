#include <iostream>
#include <vector>
#include <algorithm>
#include <array>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int N{ 0 }, iStart{ 0 }, iEnd{ 0 }, iTime{ 0 }, iCount{ 1 };
	cin >> N;

	vector<pair<int, int>> vec; // 끝시간, 시작시간
	for (int i = 0; i < N; i++)
	{
		cin >> iStart >> iEnd;
		vec.push_back({ iEnd, iStart });
	}

	sort(vec.begin(), vec.end());

	iTime = vec[0].first;

	for (int i = 1; i < N; i++)
	{
		if (iTime <= vec[i].second)
		{
			iTime = vec[i].first;
			iCount++;
		}
	}

	cout << iCount;

	return 0;
}