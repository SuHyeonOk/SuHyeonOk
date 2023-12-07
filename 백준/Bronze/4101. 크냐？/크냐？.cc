#include <iostream>
#include<cmath>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int one{ 0 }, two{ 0 };
    
    while (cin >> one >> two)
    {
        if (one == 0 && two == 0)
        {
            break;
        }

        if (one > two)
        {
            cout << "Yes" << '\n';
        }
        else
        {
            cout << "No" << '\n';
        }
    }

    return 0;
}