#include <iostream>
#include <algorithm>
#define MAX 1001
using namespace std;

int arr[MAX][MAX];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int N = 0;
    cin >> N;

    int A = 0, B = 0, C = 0, D = 0;
    int Count = 1;
    int AMax = 0, BMax = 0;
    for (int i = 0; i < N; ++i)
    {
        cin >> A >> B >> C >> D;
        AMax = max(AMax, A + C);
        BMax = max(BMax, B + D);

        for (int y = B; y < B + D; ++y)
        {
            for (int x = A; x < A + C; ++x)
            {
                arr[y][x] = Count;
            }
        }

        ++Count;
    }

    for (int i = 1; i <= N; ++i)
    {
        Count = 0;
        for (int y = 0; y < BMax; ++y)
        {
            for (int x = 0; x < AMax; ++x)
            {
                if (i == arr[y][x])
                {
                    ++Count;
                }
            }
        }
        cout << Count << '\n';
    }

    return 0;
}