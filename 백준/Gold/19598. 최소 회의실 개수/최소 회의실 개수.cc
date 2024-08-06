#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;


int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int N = 0;
	cin >> N;

	vector<pair<int, int>> vec(N);
	for (int i = 0; i < N; i++)
	{
		cin >> vec[i].first >> vec[i].second;
	}
	sort(vec.begin(), vec.end());

	priority_queue<int, vector<int>, greater<int>> pq;
	pq.push(vec[0].second);

	int Count = 1;
	for (int i = 1; i < N; i++)
	{
		while (false == pq.empty() && pq.top() <= vec[i].first)
		{
			pq.pop();
		}

		pq.push(vec[i].second);
		Count = max(Count, (int)pq.size());
	}

	cout << Count;

	return 0;
}