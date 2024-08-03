#include <iostream>
#include <cmath>
using namespace std;

int main() 
{
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    long long TestCase = 0;
    cin >> TestCase;

    long long N = 0, M = 0, Ans = 0;
    for (int t = 0; t < TestCase; t++) 
    {
        cin >> N;

        bool Temp = (N < 3) ? 1 : 0;
        Ans = (N < 3) ? 2 : N;

        while (false == Temp) 
        {
            M = sqrt(N) + 1;

            for (int i = 2; i <= M; i++) 
            {
                if (N % i == 0)
                {
                    break;
                }

                if (i == M) 
                {
                    Ans = N;
                    Temp = true;
                }
            }
            N++;
        }

        cout << Ans << '\n';
    }

    return 0;
}