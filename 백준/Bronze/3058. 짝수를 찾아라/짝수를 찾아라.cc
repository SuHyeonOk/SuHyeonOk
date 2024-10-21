#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int T = 0;
    cin >> T;

    int Input = 0, Sum = 0, Min = 101;
    while (T--)
    {
        for (int i = 0; i < 7; ++i)
        {
            cin >> Input;

            if (Input % 2 == 0)
            {
                Sum += Input;
                Min = min(Min, Input);
            }
        }

        cout << Sum << ' ' << Min << '\n';
        Sum = 0;
        Min = 101;
    }

    return 0;
}