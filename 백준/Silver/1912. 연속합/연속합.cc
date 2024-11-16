#include <iostream>
#include <algorithm>
using namespace std;

int arr[100000];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int N = 0;
    cin >> N;

    for (int i = 0; i < N; ++i)
    {
        cin >> arr[i];
    }

    int Max = arr[0], Sum = arr[0];
    for (int i = 1; i < N; ++i)
    {
        Sum = max(arr[i], Sum + arr[i]);
        Max = max(Max, Sum);
    }
    cout << Max;

    return 0;
}