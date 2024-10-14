#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int K = 0;
    cin >> K;

    int arr[100]{ 0 };
    int N = 0;
    for (int i = 0; i < K; ++i)
    {
        cin >> N;

        for (int j = 0; j < N; ++j)
        {
            cin >> arr[j];
        }

        sort(arr, arr + N, greater<int>());

        int Max = 0;
        for (int j = 1; j < N; ++j)
        {
            Max = max(Max, arr[j - 1] - arr[j]);
        }

        cout << "Class " << i + 1 << '\n';
        cout << "Max " << arr[0] << ", Min " << arr[N  -  1]<< ", Largest gap " << Max << '\n';
    }

    return 0;
}