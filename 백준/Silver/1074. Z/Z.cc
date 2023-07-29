#include <cstdio>
#include <iostream>
#include <cmath>

using namespace std;

int N{ 0 }, r{ 0 }, c{ 0 }, ans{ 0 };

void Z(int y, int x, int size)
{
	if (y == r && x == c)
	{
		cout << ans << '\n';
		return;
	}

	// r, c가 현재 사분면에 존재한다면
	if (r < y + size && r >= y && c < x + size && c >= x)
	{
		Z(y, x, size / 2); // 1사분면 탐색
		Z(y, x + size / 2, size / 2); // 2사분면 탐색
		Z(y + size / 2, x, size / 2); // 3사분면 탐색
		Z(y + size / 2, x + size / 2, size / 2); // 4사분면 탐색
	}
	else
	{
		ans += size * size;
	}
}

int main() 
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N >> r >> c;
	Z(0, 0, pow(2, N));

	return 0;
}