#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
    int t;
    cin >> t;

    int arr[3];
    int a;
    for (int i = 0; i < t; i++) {
        for (int j = 0; j < 3; j++)
        {
            cin >> a;
            arr[j] = a;
        }

        sort(begin(arr), end(arr));

        cout << "Case #" << i + 1 << ": ";

        if (arr[0] + arr[1] <= arr[2])
        {
            cout << "invalid!\n";
        }
        else if (arr[0] == arr[1] && arr[1] == arr[2])
        {
            cout << "equilateral\n";
        }
        else if (arr[0] == arr[1] || arr[1] == arr[2])
        {
            cout << "isosceles\n";
        }
        else if (arr[0] != arr[1] && arr[1] != arr[2])
        {
            cout << "scalene\n";
        }
    }

    return 0;
}