#include <iostream>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int X = 0;
    cin >> X;
    
    int Rod = 64, Count = 0;
    while (X != 0)
    {
        if (X >= Rod)
        {
            X -= Rod;
            ++Count;
        }
        else
        {
            Rod /= 2;
        }
    }

    cout << Count;

    return 0;
}