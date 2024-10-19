#include <iostream>
#include <map>
#include <string>

using namespace std;
map<string, int> m;

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cout << fixed;
	cout.precision(4);

	string str;
	int N = 0;

	while (getline(cin, str))
	{
		N++;
		m[str]++;
	}
	for (auto it = m.begin(); it != m.end(); it++)
	{
		cout << it->first << " " << (double)it->second / N * 100 << "\n";
	}

	return 0;
}