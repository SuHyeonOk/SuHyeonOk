#include <iostream>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int N = 0;
    cin >> N;

    int Gap = N - 1;
    for (int i = 1; i <= N; i++)
    {
        for (int j = Gap; j > 0; j--)
        {
            cout << " ";
        }

        for (int j = 1; j <= i; j++)
        {
            cout << "* ";
        }

        --Gap;
        cout << '\n';
    }

    return 0;
}