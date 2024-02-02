#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int a = 0, b = 0, c = 0;

    while (true)
    {
        cin >> a >> b >> c;
        
        if (a == 0 && b == 0 && c == 0)
        {
            break;
        }

        int NumMax = max({ a, b, c });
        if (NumMax >= a + b || NumMax >= a + c || NumMax >= b + c)
        {
            cout << "Invalid" << '\n';
        }
        else if (a == b && a == c && b == c)
        {
            cout << "Equilateral" << '\n';
        }
        else if (a == b || a == c || b == c)
        {
            cout << "Isosceles" << '\n';
        }
        else // if (a != b || a != c || b != c)
        {
            cout << "Scalene" << '\n';
        }
    }

    return 0;
}