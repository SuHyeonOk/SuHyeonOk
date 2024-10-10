#include <iostream>
using namespace std;

long long DP[1000001];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int N = 0;
    cin >> N;

    DP[1] = 1;
    DP[2] = 2;

    for (int i = 3; i <= N; ++i)
    {
        DP[i] = (DP[i - 1] + DP[i - 2]) % 15746;
    }

    cout << DP[N];

    return 0;
}