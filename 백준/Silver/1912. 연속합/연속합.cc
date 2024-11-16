#include <iostream>
#include <algorithm>
using namespace std;

int arr[100000];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int N = 0;
    cin >> N;

    int Input = 0;
    cin >> Input;

    int Max = Input, Sum = Input;
    for (int i = 1; i < N; ++i)
    {
        cin >> Input;
        Sum = max(Input, Sum + Input);
        Max = max(Max, Sum);
    }
    cout << Max;

    return 0;
}