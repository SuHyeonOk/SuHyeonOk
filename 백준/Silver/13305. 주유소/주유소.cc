#include <iostream>
#include <algorithm>
using namespace std;

pair<long, long> arr[100000];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int N = 0;
    cin >> N;

    for (int i = 0; i < N - 1; ++i)
    {
        cin >> arr[i].first;
    }

    for (int i = 0; i < N; ++i)
    {
        cin >> arr[i].second;
    }

    long Total = 0, Min = 1000000000;
    for (int i = 0; i < N - 1; ++i)
    {
        Min = min(Min, arr[i].second);
        Total += arr[i].first * Min;
    }

    cout << Total;
    
    return 0;
}