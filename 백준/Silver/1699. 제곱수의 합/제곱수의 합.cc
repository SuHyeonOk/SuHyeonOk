#pragma once
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int n{ 0 };
    cin >> n;

    vector<int> DP(n + 1);
    DP[1] = 1;

    for (int i = 1; i <= n; i++)
    {
        DP[i] = DP[1] + DP[i - 1];
        for (int j = 2; j * j <= i; j++)
        {
            DP[i] = min(DP[i], 1 + DP[i - j * j]);
        }
    }

    cout << DP[n];

    return 0;
}