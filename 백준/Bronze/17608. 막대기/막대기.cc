#include <iostream>
#define MAX 100001
using namespace std;

int arr[MAX];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int N = 0;
    cin >> N;
    
    int h = 0;
    for (int i = 0; i < N; i++)
    {
        cin >> h;
        arr[i] = h;
    }

    int Result = 1;
    for (int i = N; i >= 0; --i)
    {
        if (h < arr[i])
        {
            h = arr[i];
            ++Result;
        }
    }

    cout << Result;

    return 0;
}