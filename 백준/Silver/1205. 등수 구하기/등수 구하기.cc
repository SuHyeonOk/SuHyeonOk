#include <iostream>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int N = 0, New = 0, Count = 0;
    cin >> N >> New >> Count;

    int arr[50]{ 0, };
    for (int i = 0; i < N; i++)
    {
        cin >> arr[i];
    }

    int Rank = 1, Check = 0;
    for (int i = 0; i < N; i++)
    {
        if (arr[i] > New)
        {
            ++Rank;
        }
        else if (arr[i] == New)
        {
            ++Check;
        }
        else if (arr[i] < New)
        {
            break;
        }
    }

    if (Count < Rank + Check)
    {
        cout << -1;
    }
    else
    {
        cout << Rank;
    }

    return 0;
}