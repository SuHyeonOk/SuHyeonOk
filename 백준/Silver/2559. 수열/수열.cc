#include <iostream>
#include <algorithm>
using namespace std;

int arr[100000];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int N = 0, K = 0;
    cin >> N >> K;

    for (int i = 0; i < N; ++i)
    {
        cin >> arr[i];
    }

    int Sum = 0;
    for (int i = 0; i < K; ++i)
    {
        Sum += arr[i];
    }

    int Max = Sum;
    int Start = 0, End = K;
    while (N > End)
    {
        Sum -= arr[Start];
        Sum += arr[End];
        ++Start;
        ++End;

        Max = max(Max, Sum);
    }

    cout << Max;

    return 0;
}