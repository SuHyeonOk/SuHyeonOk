#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int arr[3];
    cin >> arr[0] >> arr[1] >> arr[2];
    
    sort(arr, arr + 3);

    if (arr[0] + arr[1] > arr[2])
    {
        cout << arr[0] + arr[1] + arr[2];
    }
    else
    {
        cout << arr[0] + arr[1] + (arr[0] + arr[1] - 1);
    }

    return 0;
}