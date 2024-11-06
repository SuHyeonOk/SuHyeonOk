#include <iostream>
using namespace std;

int main()
{
    for (int T = 0; T < 3; ++T)
    {
        int N = 0;
        cin >> N;

        long long Sum = 0, Flow = 0, Input = 0;
        for (int i = 0; i < N; ++i)
        {
            cin >> Input;

            long long Temp = Sum;
            Sum += Input;

            // 양수 && 양수 && 음수 → 오버플로우
            if (Input > 0 && Temp > 0 && Sum < 0)
            {
                Flow++;
            }
            // 음수 && 음수 && 양수 → 언더플로우
            if (Input < 0 && Temp < 0 && Sum > 0)
            {
                Flow--;
            }
        }

        if (Flow == 0)
        {
            if (Sum == 0)
            {
                cout << '0' << '\n';
            }
            else
            {
                cout << (Sum > 0 ? '+' : '-') << '\n';
            }
        }
        else
        {
            cout << (Flow > 0 ? '+' : '-') << '\n';
        }
    }

    return 0;
}