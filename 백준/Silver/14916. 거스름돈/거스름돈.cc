#include <iostream>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int n = 0;
    cin >> n;

    int arr[5] = { 0, -1, 1, -1, 2 };
    if (n < 5)
    {
        cout << arr[n];
        return 0;
    }

    int temp = n % 5;
    if (temp % 2 != 0)
    {
        int a = (n / 5) - 1;
        int b = (n % 5) + 5;
        int c = b / 2;
        cout << a + c;
        return 0;
    }

    int a = n / 5;
    int b = n % 5;
    int c = b / 2;
    cout << a + c;

    return 0;
}