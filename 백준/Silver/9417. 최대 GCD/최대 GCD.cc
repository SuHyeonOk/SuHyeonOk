#include <iostream>
#include <algorithm>
using namespace std;

int GCD(int a, int b)
{
    if (b == 0)
    {
        return a;
    }

    return GCD(b, a % b);
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int N = 0;
    cin >> N;

    int arr[100]{ 0 };
    int M = 0, Index = 0, Max = 0;
    while (N--)
    {
        while (cin >> M)
        {
            arr[Index] = M;
            ++Index;

            if (cin.get() == '\n') 
            {
                break;  // '\n'을 만나면 다음 줄로 이동
            }
        }
        
        for (int i = 0; i < Index; ++i)
        {
            for (int j = i + 1; j < Index; ++j)
            {
                Max = max(Max, GCD(arr[i], arr[j]));
            }
        }

        cout << Max << '\n';
        Max = 0;
        Index = 0;
    }

    return 0;
}