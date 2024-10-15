#include <iostream>
#define MAX 1000000000
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int N = 0;
    cin >> N;

    int DP[101][10]{ 0 };

    for (int y = 1; y <= 9; y++)
    {
        DP[1][y] = 1;
    }

    for (int y = 2; y <= N; y++) 
    {
        for (int x = 0; x <= 9; x++)
        {
            if (x == 0)
            {
                DP[y][x] = DP[y - 1][1] % MAX;
            }
            else if (x == 9)
            {
                DP[y][x] = DP[y - 1][8] % MAX;
            }
            else
            {
                DP[y][x] = (DP[y - 1][x - 1] + DP[y - 1][x + 1]) % MAX;
            }          
        }
    }

    long long Answer = 0;
    for (int y = 0; y <= 9; y++)
    {
        Answer += DP[N][y];
    }

    cout << Answer % MAX;

    return 0;
}