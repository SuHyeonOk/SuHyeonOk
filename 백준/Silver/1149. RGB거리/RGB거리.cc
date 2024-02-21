#include <iostream>
#include <algorithm>
using namespace std;

int house[1001][3]; // 초기화를 위해 전역으로 선언

int main()
{
    int N = 0;
    int cost[3];

    cin >> N;

    for (int i = 1; i <= N; ++i)
    {
        cin >> cost[0] >> cost[1] >> cost[2];

        house[i][0] = min(house[i - 1][1], house[i - 1][2]) + cost[0];
        house[i][1] = min(house[i - 1][0], house[i - 1][2]) + cost[1];
        house[i][2] = min(house[i - 1][1], house[i - 1][0]) + cost[2];
    }

    cout << min({ house[N][2], house[N][0], house[N][1] });

    return 0;
}