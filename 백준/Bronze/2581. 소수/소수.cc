#include <iostream>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int M = 0, N = 0;
    cin >> M >> N;

    int min = 0, sum = 0;
    for (int i = M; i <= N; i++)
    {
        if (i <= 1)
        {
            continue;
        }

        bool find = false;
        for (int j = 2; j < i; j++)
        {
            if (i % j == 0)
            {
                find = true;
                break; // 소수가 아니다!
            }
        }

        if(false == find)
        {
            sum += i;

            if (min == 0)
            {
                min = i;
            }
        }
    }

    if (sum == 0)
    {
        cout << "-1";
    }
    else
    {
        cout << sum << '\n' << min;
    }

    return 0;
}