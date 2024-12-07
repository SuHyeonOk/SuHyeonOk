#include <iostream>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int T = 0;
    cin >> T;

    int Index = 0;
    string Str = "";
    while (T--)
    {
        cin >> Index >> Str;
        cout << Str.erase(Index - 1, 1) << '\n';
    }

    return 0;
}