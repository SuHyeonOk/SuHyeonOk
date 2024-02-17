#include <iostream>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int TestCase = 0;
    cin >> TestCase;

    while (TestCase--)
    {
        int V = 0, E = 0;
        cin >> V >> E;

        cout << (E - V) + 2 << '\n';
    }

    return 0;
}