#include <iostream>
#include <vector>
using namespace std;

int main()
{
	int T{ 0 }, H{ 0 }, W{ 0 }, N{ 0 }, h{ 0 }, w{ 0 };
	cin >> T;

	while (T--)
	{
		cin >> H >> W >> N;


		h = N % H; // 층
		w = N / H; // 호
		
		h > 0 ? w++ : h = H;

		cout << h * 100 + w << '\n';
 	}

	return 0;
}