#include <iostream>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int A = 0, B = 0, C = 0, M = 0;
    cin >> A >> B >> C >> M;

    if (A > M) 
    {
        cout << 0 << endl;
        return 0;
    }

    int Time = 0, Sum = 0, Result = 0;
    while (Time < 24) 
    {
        if (Sum + A > M) 
        {
            Sum -= C;
            if (Sum < 0)
            {
                Sum = 0;
            }
        }
        else
        {
            Sum += A;
            Result += B;
        }
        Time++;
    }
    cout << Result << endl;

    return 0;
}