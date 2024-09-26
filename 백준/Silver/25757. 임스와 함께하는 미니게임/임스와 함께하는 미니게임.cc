#include <iostream>
#include <set>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int N = 0;
    cin >> N;

    char Game = ' ';
    cin >> Game;

    string Name = "";
    set<string> names;
    while (N--)
    {
        cin >> Name;
        names.insert(Name);
    }

    int Type = 1;
    if (Game == 'F')
    {
        Type = 2;
    }
    else if (Game == 'O')
    {
        Type = 3;
    }

    cout << names.size() / Type;

    return 0;
}