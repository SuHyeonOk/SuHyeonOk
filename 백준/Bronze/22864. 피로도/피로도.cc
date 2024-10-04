#include <iostream>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int A = 0, B = 0, C = 0, M = 0;
    cin >> A >> B >> C >> M;

    int Fatigue = 0, Work = 0;
    for(int i = 0; i < 24; ++i)
    {
        if (Fatigue + A > M)
        {
            Fatigue -= C;
            if (Fatigue < 0)
            {
                Fatigue = 0;
            }
            continue;
        }

        Work += B;
        Fatigue += A;
    }

    cout << Work;

    return 0;
}