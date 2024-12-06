#include <iostream>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int N = 0, m = 0, M = 0, T = 0, R = 0;
    cin >> N >> m >> M >> T >> R;

    if (m + T > M)
    {
        cout << -1;
        return 0;
    }

    int Count = 0, Pulse = m;
    while (0 < N)
    {
        if (m <= Pulse && Pulse + T <= M)
        {
            Pulse += T;
            --N;
        }
        else
        {
            Pulse -= R;

            if (m > Pulse)
            {
                Pulse = m;
            }
        }
        ++Count;
    }

    cout << Count;

    return 0;
}