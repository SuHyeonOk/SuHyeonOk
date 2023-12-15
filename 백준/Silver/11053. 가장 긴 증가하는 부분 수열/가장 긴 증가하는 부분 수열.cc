#include <iostream>
using namespace std;
#define MAX 1001

int arr[MAX];
int dp[MAX];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int n{ 0 };
    cin >> n;

    for (int i = 1; i <= n; i++)
    {
        cin >> arr[i];
    }

    int result{ 0 };
    for (int i = 1; i <= n; i++)
    {
        for (int j = 0; j < i; j++)
        {
            if (arr[i] > arr[j] && dp[i] <= dp[j])
            {
                dp[i] = dp[j] + 1;
                if (dp[i] > result)
                {
                    result = dp[i];
                }
            }
        }
    }

    cout << result;

    return 0;
}