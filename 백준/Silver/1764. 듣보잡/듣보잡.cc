#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	int N{ 0 }, M{ 0 };
	cin >> N >> M;

	string strInput{ "" };
	vector<string> vec, result;

	for (int i = 0; i < N; i++)
	{
		cin >> strInput;
		vec.push_back(strInput);
	}

	sort(vec.begin(), vec.end());
	for (int i = 0; i < M; i++)
	{
		cin >> strInput;
		if (binary_search(vec.begin(), vec.end(), strInput))
		{
			result.push_back(strInput);
		}
	}

	sort(result.begin(), result.end());
	cout << result.size() << '\n';
	for (auto it : result)
	{
		cout << it << '\n';
	}

	return 0;
}