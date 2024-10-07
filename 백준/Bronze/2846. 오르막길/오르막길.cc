#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int N = 0;
    cin >> N;

    int Input = 0, Temp = 0, Result = 0;
    int Min = 0;

    cin >> Temp;
    Min = Temp;

    for (int i = 1; i < N; ++i)
    {
        cin >> Input;

        if (Temp < Input)
        {
            Result = max(Result, Input - Min);
        }
        else
        {
            Min = Input;  // 새로운 구간 시작
        }

        Temp = Input;
    }

    cout << Result;

    return 0;
}
