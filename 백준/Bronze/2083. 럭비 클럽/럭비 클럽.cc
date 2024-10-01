#include <iostream>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    string Name = "";
    int Age = 0, Weight = 0;

    while (true)
    {
        cin >> Name >> Age >> Weight;

        if (Name == "#")
        {
            break;
        }

        if (Age > 17 || Weight >= 80)
        {
            cout << Name << " Senior" << '\n';
        }
        else
        {
            cout << Name << " Junior" << '\n';
        }
    }

    return 0;
}