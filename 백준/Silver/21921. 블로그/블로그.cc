#include <iostream>
#define MAX 250000
using namespace std;

int arr[MAX];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int N = 0, X = 0;
    cin >> N >> X;

    int Sum = 0;
    for (int i = 0; i < X; i++)
    {
        cin >> arr[i];
        Sum += arr[i];
    }
    
    int Max = Sum;
    int Count = 1;
    for (int i = X; i < N; i++)
    {
        cin >> arr[i];
        Sum += arr[i] - arr[i - X];
        
        if (Max == Sum)
        {
            ++Count;
        }
        else if (Max < Sum)
        {
            Max = Sum;
            Count = 1;
        }
    }

    if (Max == 0)
    {
        cout << "SAD";
    }
    else
    {
        cout << Max << '\n' << Count;
    }

    return 0;
}