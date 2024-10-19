#include <iostream>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int w = 0, h = 0, p = 0, q = 0, t = 0;
	cin >> w >> h >> p >> q >> t;

	p += t;
	q += t;

	p %= (2 * w);
	q %= (2 * h);

	if (p > w)
	{
		p = 2 * w - p;
	}
	if (q > h)
	{
		q = 2 * h - q;
	}

	cout << p << ' ' << q;

	return 0;
}