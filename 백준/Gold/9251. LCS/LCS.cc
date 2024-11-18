#include <iostream>
#include <algorithm>
using namespace std;

int dp[1001][1001];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    string A = "", B = "";
    cin >> A >> B;

    int LengthA = A.length();
    int LengthB = B.length();
    for (int i = 0; i < LengthA; i++)
    {
        for (int j = 0; j < LengthB; j++)
        {
            if (A[i] == B[j])
            {
                dp[i + 1][j + 1] = dp[i][j] + 1;
            }
            else
            {
                dp[i + 1][j + 1] = max(dp[i][j + 1], dp[i + 1][j]);
            }
        }
    }
    cout << dp[LengthA][LengthB];

    return 0;
}