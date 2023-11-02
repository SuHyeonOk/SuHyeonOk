#include <iostream>
#include <algorithm>
using namespace std;
#define MAX 3

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int arr[MAX];

    for (int i = 0; i < MAX; i++)
    {
        cin >> arr[i];
    }

    sort(arr, arr + MAX);

    for (int i = 0; i < MAX; i++)
    {
        cout << arr[i] << " ";
    }

    return 0;
}