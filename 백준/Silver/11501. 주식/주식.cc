#include <iostream>
using namespace std;

int arr[1000000];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int T = 0;
    cin >> T;

    int N = 0; 
    while (T--)
    {
        cin >> N;

        for (int i = 0; i < N; ++i)
        {
            cin >> arr[i];
        }

        int Max = 0;
        long Sum = 0;
        for (int i = N - 1; i >= 0; --i)
        {
            Max = max(Max, arr[i]);
            Sum += Max - arr[i];
        }

        cout << Sum << '\n';
    }

    return 0;
}