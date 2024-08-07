#include <iostream>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int N = 0;
    cin >> N;

    int TSize[6]{ 0 };
    for (int i = 0; i < 6; ++i)
    {
        cin >> TSize[i];
    }

    int T = 0, P = 0;
    cin >> T >> P;

    int TBundle = 0;
    for (int i = 0; i < 6; ++i)
    {
        if (TSize[i] % T == 0)
        {
            TBundle += TSize[i] / T;
        }
        else
        {
            TBundle += (TSize[i] / T) + 1;
        }
    }
    cout << TBundle << '\n';
    cout << N / P << ' ' << N % P;

    return 0;
}