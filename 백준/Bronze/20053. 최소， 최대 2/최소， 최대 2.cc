#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int  T = 0;
    cin >> T;

    int N = 0;
    while (T--)
    {
        cin >> N;

        int Min = 1000001;
        int Max = -1000001;
        int Input = 0;
        while (N--)
        {
            cin >> Input;
            Min = min(Min, Input);
            Max = max(Max, Input);
        }
        cout << Min << ' ' << Max << '\n';
    }

    return 0;
}