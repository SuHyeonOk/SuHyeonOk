#include <iostream>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int N = 0;
    cin >> N;

    int DP[11]{ 0 };
    DP[1] = 0;
    DP[2] = 1;

    for (int i = 3; i <= N; i++) 
    {
        DP[i] = DP[i - 1] + (i - 1);
    }

    cout << DP[N] << '\n';

    return 0;
}