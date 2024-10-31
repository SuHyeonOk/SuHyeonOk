#include <iostream>
using namespace std;

int arr[999][999];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int N = 0, Point = 0;
    cin >> N >> Point;

    int Number = N * N;
    int Count = N;
    for (int i = 0; i < N; ++i)
    {
        // 왼쪽줄
        for (int j = i; j < Count; ++j)
        {
            arr[j][i] = Number;

            if (1 == Number)
            {
                break;
            }

            --Number;
        }

        if (1 == Number)
        {
            break;
        }

        // 아랫줄
        --Count;
        for (int j = i + 1; j < Count; ++j)
        {
            arr[Count][j] = Number;
            --Number;
        }

        // 오른쪽 줄
        for (int j = Count; j >= i; --j)
        {
            arr[j][Count] = Number;
            --Number;
        }

        // 윗줄
        for (int j = Count - 1; j > i; --j)
        {
            arr[i][j] = Number;
            --Number;
        }
    }

    int X = 0, Y = 0;
    for (int y = 0; y < N; ++y)
    {
        for (int x = 0; x < N; ++x)
        {
            if (Point == arr[y][x])
            {
                X = x;
                Y = y;
            }

            cout << arr[y][x] << ' ';
        }
        cout << '\n';
    }

    cout << Y + 1 << ' ' << X + 1;

    return 0;
}