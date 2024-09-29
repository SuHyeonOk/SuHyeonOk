#include <iostream>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int n = 0;
    cin >> n;

    int x = 0, y = 0;
    int arr[5]{ 0 };
    while (n--)
    {
        cin >> x >> y;

        if (x == 0 || y == 0)
        {
            ++arr[4];
        }
        else if (x > 0 && y > 0)
        {
            ++arr[0];
        }
        else if (x < 0 && y > 0)
        {
            ++arr[1];
        }
        else if (x < 0 && y < 0)
        {
            ++arr[2];
        }
        else
        {
            ++arr[3];
        }
    }

    cout << "Q1: " << arr[0] << '\n' <<
        "Q2: " << arr[1] << '\n' <<
        "Q3: " << arr[2] << '\n' <<
        "Q4: " << arr[3] << '\n' <<
        "AXIS: " << arr[4];

    return 0;
}