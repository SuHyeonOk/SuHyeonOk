#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    bool Input = true;
    int Num = 0, Sum = 0;

    for (size_t i = 0; i < 10; i++)
    {
        cin >> Num;

        if (false == Input)
        {
            continue;
        }

        if (100 >= Sum + Num)
        {
            Sum += Num;
        }
        else
        {
            Input = false;

            int Gap1 = abs(Sum - 100);
            int Gap2 = abs((Sum + Num) - 100);

            if (Gap1 < Gap2) // Gap2가 더 크면 Num을 더하지 않고 종료한다.
            {
                continue;
            }

            // Gap1 과 Gap2가 같거나, Gap1이 더 크면 Num을 더한다.
            Sum += Num;
        }
    }

    cout << Sum;

    return 0;
}