#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int N = 0;
    cin >> N;

    int hp[20], joy[20];
    for (int i = 0; i < N; ++i)
    {
        cin >> hp[i];
    }
    for (int i = 0; i < N; ++i)
    {
        cin >> joy[i];
    }

    // 체력 소모를 최대 100 미만으로 제한
    int dp[100]{ 0 };
    for (int i = 0; i < N; ++i)
    {
        for (int j = 99; j >= hp[i]; --j)
        {
            dp[j] = max(dp[j], dp[j - hp[i]] + joy[i]);
        }
    }

    // dp[0]부터 dp[99]까지 중 가장 큰 기쁨 값
    cout << *max_element(dp, dp + 100) << '\n';

    return 0;
}