#include <iostream>
#include <algorithm>
using namespace std;

int arr[300000];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int N = 0, K = 0;
    cin >> N >> K;

    for (int i = 0; i < N; ++i)
    {
        cin >> arr[i];
    }
    sort(arr, arr + N);
    
    int Result = arr[N - 1] - arr[0];
    for (int i = N - 1; i >= 1; --i)
    {
        arr[i] = arr[i] - arr[i - 1];
    }
    arr[0] = 0;
    sort(arr, arr + N);

    for (int i = N - 1; K > 1; --K, --i)
    {
        Result -= arr[i];
    }
    cout << Result;

    return 0;
}