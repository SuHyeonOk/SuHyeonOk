#include <iostream>
#include <map>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	int N{ 0 }, M{ 0 };
	cin >> N >> M;

	string strInput{ "" };
	map<string, int> name;
	vector<string> result;
	for (int i = 0; i < N; i++)
	{
		cin >> strInput;
		name.emplace(strInput, i);
	}

	for (int i = 0; i < M; i++)
	{
		cin >> strInput;

		if (name.end() == name.find(strInput))
		{
			continue;
		}
		result.push_back(strInput);
	}

	sort(result.begin(), result.end());

	int size = result.size();
	cout << size << '\n';
	for (int i = 0; i < size; i++)
	{
		cout << result[i] << '\n';
	}

	return 0;
}