#include <iostream>
#include <array>
using namespace std;
#define MAX 100

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int n{ 0 }, x{ 0 }, y{ 0 }, ans{ 0 };
    array<array<bool, MAX>, MAX> arr { {false} };
    cin >> n;

    while (n--)
    {
        cin >> x >> y;

        for (int i = y; i < y + 10; i++)
        {
            for (int j = x; j < x + 10; j++)
            {
                if (false == arr[i][j])
                {
                    ++ans;
                    arr[i][j] = true;
                }
            }
        }
    }

    cout << ans;

    return 0;
}