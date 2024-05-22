#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(void)
{
	int N = 0, K = 0;
	cin >> N;
	cin >> K;

	if (K >= N)
	{
		cout << "0";
		return 0;
	}

	vector<int> vec(N);
	for (int i = 0; i < N; i++)
	{
		cin >> vec[i];
	}
	sort(vec.begin(), vec.end());

	vector<int> vec2;
	for (int i = 0; i < N - 1; i++)
	{
		vec2.push_back(vec[i + 1] - vec[i]);
	}
	sort(vec2.begin(), vec2.end());

	int Ans = 0;
	int Size = static_cast<int>(vec2.size()) - (K - 1);
	for (int i = 0; i < Size; i++)
	{
		Ans += vec2[i];
	}
	cout << Ans;

	return 0;
}