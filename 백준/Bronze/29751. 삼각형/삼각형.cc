#include <iostream>
#include <cmath>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    float W = 0.0f, H = 0.0f;
    cin >> W >> H;

    cout << fixed;
    cout.precision(1);
    cout << (W * H) / 2.0f;

    return 0;
}