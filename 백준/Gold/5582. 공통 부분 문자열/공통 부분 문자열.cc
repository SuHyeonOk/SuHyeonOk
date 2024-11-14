#include <iostream>
#include <algorithm>
using namespace std;

int dp[4000][4000];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    string A = "", B = "";
    cin >> A >> B;

    int Max = 0;
    int LengthA = A.length();
    int LengthB = B.length();
    for (int i = 0; i < LengthA; i++)
    {
        for (int j = 0; j < LengthB; j++)
        {
            if (A[i] == B[j])
            {
                dp[i][j] = 1;
                if (i >= 1 && j >= 1)
                {
                    dp[i][j] += dp[i - 1][j - 1];
                }
                Max = max(Max, dp[i][j]);
            }
        }
    }
    cout << Max;

    return 0;
}