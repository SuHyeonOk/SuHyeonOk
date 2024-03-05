#include <iostream>
#include <vector>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    int M = 0;
    cin >> M;

    int arr[4] = { 0, 1, 0, 0 };
    int X = 0, Y = 0;
    for (int i = 0; i < M; i++)
    {
        cin >> X >> Y;
        int Temp = arr[X];
        arr[X] = arr[Y];
        arr[Y] = Temp;
    }

    for (int i = 1; i <= 3; i++)
    {
        if (1 == arr[i])
        {
            cout << i;
            break;
        }
    }

    return 0;
}