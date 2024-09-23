#include <iostream>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int n = 0;
    cin >> n;

    while (n--)
    {
        int p = 0;
        cin >> p;

        int Coin = 0, MaxCoin = 0;
        string Name = "", BestName = "";
        for (int i = 0; i < p; ++i)
        {
            cin >> Coin >> Name;

            if (MaxCoin < Coin)
            {
                MaxCoin = Coin;
                BestName = Name;
            }
        }

        cout << BestName << '\n';
    }

    return 0;
}