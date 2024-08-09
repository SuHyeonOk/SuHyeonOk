#include <iostream>
#include <cmath>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int TestCase = 0;
    cin >> TestCase;

    int Result = -1;
    int X1 = 0, Y1 = 0, R1 = 0, X2 = 0, Y2 = 0, R2 = 0;
    while (TestCase--)
    {
        cin >> X1 >> Y1 >> R1 >> X2 >> Y2 >> R2;

        double Distance = sqrt(pow(X1 - X2, 2) + pow(Y1 - Y2, 2));
        double Sub = R1 > R2 ? R1 - R2 : R2 - R1;

        if (Distance == 0 && R1 == R2)
        {
            cout << -1 << '\n';
        }
        else if (R1 + R2 == Distance || Sub == Distance)
        {
            cout << 1 << '\n';
        }
        else if (Sub < Distance && Distance < R1 + R2)
        {
            cout << 2 << '\n';
        }
        else
        {
            cout << 0 << '\n';
        }
    }

    return 0;
}