#include <iostream>
#include <algorithm>
using namespace std;
#define MAX 10

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int t{ 0 };
    cin >> t;

    int arr[MAX]{ 0, };
    while (t--)
    {
        for (int i = 0; i < MAX; i++)
        {
            cin >> arr[i];
        }

        sort(arr, arr + MAX);
        cout << arr[7] << '\n';
    }

    return 0;
}