#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int Input = 0;
    int Hamburger = 2000, Beverage = 2000;

    for (int i = 0; i < 3; ++i)
    {
        cin >> Input;
        Hamburger = min(Input, Hamburger);
    }

    for (int i = 0; i < 2; ++i)
    {
        cin >> Input;
        Beverage = min(Input, Beverage);
    }

    cout << Hamburger + Beverage - 50;

    return 0;
}