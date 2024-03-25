#include <iostream>
#include <cmath>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int M = 0, N = 0;
    cin >> M >> N;

    int Temp = 0, Sum = 0, Min = 0;
    for (int i = M; i <= N; i++)
    {
        Temp = sqrt(i);

        if (Temp * Temp == i)
        {
            Sum += i;
            if (Min == 0)
            {
                Min = i;
            }
        }
    }

    if (0 == Sum)
    {
        cout << -1;
    }
    else
    {
        cout << Sum << '\n' << Min;
    }

    return 0;
}