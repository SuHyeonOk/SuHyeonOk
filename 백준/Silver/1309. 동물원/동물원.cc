#include <iostream>
using namespace std;

int DP[100001];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int N = 0;
    cin >> N;

    DP[0] = 1;
    DP[1] = 3;

    for (int i = 2; i <= N; i++)
    {
        DP[i] = (DP[i - 1] * 2 + DP[i - 2]) % 9901;
    }

    cout << DP[N];

    return 0;
}