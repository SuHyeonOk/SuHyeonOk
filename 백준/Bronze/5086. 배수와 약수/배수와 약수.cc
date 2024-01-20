#include <iostream>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    while (true)
    {
        int N = 0, M = 0;
        cin >> N >> M;

        if (N == 0 && M == 0)
        {
            break;
        }

        if (M % N == 0)
        {
            cout << "factor\n";
        }
        else if (N % M == 0)
        {
            cout << "multiple\n";
        }
        else
        {
            cout << "neither\n";
        }
    }

    return 0;
}