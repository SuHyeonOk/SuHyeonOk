#include <iostream>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int N = 0, M = 0, J = 0;
    cin >> N >> M >> J;

    int Count = 0;
    int Start = 1, End = M;
    int X = 0;

    while (J--)
    {
        cin >> X;

        bool Flag = true;
        while (Flag)
        {
            if (Start <= X && X <= End) 
            {
                Flag = false;
            }
            else if (Start > X)
            {
                --Start;
                --End;
                ++Count;
            }
            else
            {
                ++Start;
                ++End;
                ++Count;
            }
        }
    }

    cout << Count;

    return 0;
}