#include <iostream>
#define MIN -10001
#define MAX 10001
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int N = 0;
    cin >> N;

    int X = 0, Y = 0;
    int MinX = MAX, MaxX = MIN, MinY = MAX, MaxY = MIN;
    for (int i = 0; i < N; i++)
    {
        cin >> X >> Y;
        
        if (MinX > X)
        {
            MinX = X;
        }
        if (MaxX < X)
        {
            MaxX = X;
        }
        if (MinY > Y)
        {
            MinY = Y;
        }
        if (MaxY < Y)
        {
            MaxY = Y;
        }
    }

    cout << (MaxX - MinX) * (MaxY - MinY);

    return 0;
}