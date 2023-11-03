#include <iostream>
#include <algorithm>
using namespace std;
#define MAX 100000

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int N{ 0 };
    cin >> N;

    int arr[MAX];
    for (int i = 0; i < N; i++)
    {
        cin >> arr[i];
    }

    sort(arr, arr + N);

    int result{ 0 };
    for (int i = 0; i < N; i++)
    {
        result = max(result, (N - i) * arr[i]);
    }

    cout << result;

    return 0;
}