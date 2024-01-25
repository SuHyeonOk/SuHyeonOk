#include <iostream>
#include <algorithm>
#include <limits.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int N = 0;
    cin >> N;

    int Min = INT_MAX, Max = 0, Input = 0;
    for (int i = 0; i < N; i++)
    {
        cin >> Input;
        Min = min(Min, Input);
        Max = max(Max, Input);
    }

    cout << Min * Max;

    return 0;
}