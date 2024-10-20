#include <iostream>
#include <map>
#include <string>
using namespace std;


int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cout << fixed;
	cout.precision(4);

	float N = 0;
	string Input = "";
	map<string, float> m;

	while (getline(cin, Input))
	{
		++N;
		++m[Input];
	}

	for (map<string, float>::iterator it = m.begin(); it != m.end(); it++)
	{
		cout << it->first << " " << it->second / N * 100.0f << '\n';
	}

	return 0;
}