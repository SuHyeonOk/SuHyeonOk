#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int T = 0;
    cin >> T;

    int N = 0, X = 0, Min = 100, Max = 0;
    while (T--)
    {
        cin >> N;

        while (N--)
        {
            cin >> X;

            Min = min(Min, X);
            Max = max(Max, X);
        }

        cout << (Max - Min) * 2 << '\n';
        Min = 100;
        Max = 0;
    }

    return 0;
}