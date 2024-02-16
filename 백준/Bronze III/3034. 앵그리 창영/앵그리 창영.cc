#include <iostream>
#include<cmath>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int N = 0, W = 0, H = 0;
    cin >> N >> W >> H;

    int Width = W * W;
    int Length = H * H;
    int Sum = Width + Length;
    int Result = sqrt(Sum);
    
    int Input = 0;
    while (N--)
    {
        cin >> Input;

        if (Input <= Result)
        {
            cout << "DA" << '\n';
        }
        else
        {
            cout << "NE" << '\n';
        }
    }

    return 0;
}