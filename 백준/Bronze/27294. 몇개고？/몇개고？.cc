#include <iostream>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int T = 0, S = 0;
	cin >> T >> S;

	if (12 <= T && T <= 16 && S == 0)
	{
		cout << 320;
	}
	else
	{
		cout << 280;
	}

	return 0;
}