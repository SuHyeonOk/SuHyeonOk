#include <iostream>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int N = 0;
    cin >> N;

    pair<int, int> DP[46];
    DP[0] = { 1, 0 };
    DP[1] = { 0, 1 };
    DP[2] = { 1, 1 };
    DP[3] = { 1, 2 };

    for (int i = 4; i <= N; i++)
    {
        DP[i] = { DP[i - 1].second, DP[i - 1].first + DP[i - 1].second };
    }

    cout << DP[N].first << " " << DP[N].second;

    return 0;
}