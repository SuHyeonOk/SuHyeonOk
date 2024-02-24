#include <iostream>
#include <cmath>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

	int D, W, H;
	cin >> D >> H >> W;

	double L = sqrt(W * W + H * H); // 제곱
	double X = W * D / L;
	double Y = H * D / L;
	cout << static_cast<int>(Y) << " " << static_cast<int>(X);

    return 0;
}