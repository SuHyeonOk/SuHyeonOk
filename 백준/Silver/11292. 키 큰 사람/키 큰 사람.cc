#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool Descending(pair<string, float> a, pair<string, float> b) 
{
	return a.second > b.second;
}

int main() 
{
	while (true) 
    {
		int N;
		cin >> N;

		if (N == 0) 
        {
			break;
		}

		vector<pair<string, float>> v;
		string name;
		float height;

		for (int i = 0; i < N; ++i) 
        {
			cin >> name >> height;
			v.push_back({ name, height });
		}

		stable_sort(v.begin(), v.end(), Descending);

		for (int i = 0; i < N; ++i) 
        {
			if (v[i].second == v[0].second) 
            {
				cout << v[i].first << ' ';
			}
		}
		cout << '\n';

	}

	return 0;
}
