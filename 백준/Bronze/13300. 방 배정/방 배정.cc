#include <iostream>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int N = 0, K = 0;
    cin >> N >> K;

    int arr[2][7] { 0, };
    int S = 0, Y = 0;
    for (int i = 0; i < N; i++)
    {
        cin >> S >> Y;
        ++arr[S][Y];
    }

    int result = 0;
    for (int y = 0; y < 2; y++)
    {
        for (int x = 1; x < 7;)
        {
            if (0 == arr[y][x])
            {
                x++;
                continue;
            }
            
            if (K < arr[y][x])
            {
                arr[y][x] -= K;
            }
            else
            {
                x++;
            }

            ++result;
        }
    }

    cout << result;

    return 0;
}