#include <iostream>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    string Str = "";
    cin >> Str;

    int Zero = 0;
    int One = 0;

    size_t Length = Str.length();
    for (size_t i = 0; i < Length; i++)
    {
        if ('0' == Str[i])
        {
            ++Zero;
        }
        else
        {
            ++One;
        }
    }

    Zero /= 2;
    One /= 2;

    int checkErase[501]{ 0, };

    int zeroCnt = 0;
    for (int i = Length - 1; i >= 0; i--)
    {
        if (zeroCnt == Zero)
        {
            break;
        }

        if (Str[i] == '0')
        {
            checkErase[i] = true;
            zeroCnt++;
        }
    }


    int oneCnt = 0;
    for (int i = 0; i < Length; i++)
    {
        if (oneCnt == One)
        {
            break;
        }

        if (Str[i] == '1')
        {
            checkErase[i] = true;
            oneCnt++;
        }
    }

    string ans = "";
    for (int i = 0; i < Length; i++)
    {
        if (checkErase[i])
        {
            continue;
        }

        ans += Str[i];
    }

    cout << ans;

    return 0;
}