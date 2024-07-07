#include <iostream>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int w = 0, h = 0, p = 0, q = 0, t = 0;
	cin >> w >> h >> p >> q >> t;

	bool pb = true, qb = true;
	int pt = t % (2 * w);
	int qt = t % (2 * h);

	while (pt--) 
	{
		if (p == w) 
		{
			pb = false;
		}
		else if (p == 0) 
		{
			pb = true;
		}

		if (pb)
		{
			p++;
		}
		else
		{
			p--;
		}
	}

	while (qt--) 
	{
		if (q == h) 
		{
			qb = false;
		}
		else if (q == 0) 
		{
			qb = true;
		}

		if (qb)
		{
			q++;
		}
		else
		{
			q--;
		}
	}

	cout << p << " " << q;

	return 0;
}