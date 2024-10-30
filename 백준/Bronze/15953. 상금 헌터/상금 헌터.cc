#include <iostream>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int T = 0;
    cin >> T;

    int a = 0, b = 0;
    while (T--)
    {
        cin >> a >> b;

        int Sum = 0;
        if (0 == a)
        {
            Sum += 0;
        }
        else if (1 >= a)
        {
            Sum += 5000000;
        }
        else if (3 >= a)
        {
            Sum += 3000000;
        }
        else if (6 >= a)
        {
            Sum += 2000000;
        }
        else if (10 >= a)
        {
            Sum += 500000;
        }
        else if (15 >= a)
        {
            Sum += 300000;
        }
        else if(21 >= a)
        {
            Sum += 100000;
        }

        if (0 == b)
        {
            Sum += 0;
        }
        else if (1 >= b)
        {
            Sum += 5120000;
        }
        else if (3 >= b)
        {
            Sum += 2560000;
        }
        else if (7 >= b)
        {
            Sum += 1280000;
        }
        else if (15 >= b)
        {
            Sum += 640000;
        }
        else if(31 >= b)
        {
            Sum += 320000;
        }

        cout << Sum << '\n';
    }

    return 0;
}