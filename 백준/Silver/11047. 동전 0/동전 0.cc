#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N{ 0 }, K{ 0 }, iCount{ 0 };
vector<int> vec;

void Calculate()
{
	for (int i = 0; i < N; i++)
	{
		if (K >= vec[i])
		{
			iCount++;
			K -= vec[i];
			return;
		}
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	cin >> N >> K;

	vec.resize(N);
	for (int i = 0; i < N; i++)
	{
		cin >> vec[i];
	}

	sort(vec.rbegin(), vec.rend());

	while (K != 0)
	{
		Calculate();
	}

	cout << iCount;

	return 0;
}