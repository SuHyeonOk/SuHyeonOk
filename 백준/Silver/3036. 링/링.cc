#include <iostream>
using namespace std;

int GCD(int a, int b)
{
    if (b == 0)
    {
        return a;
    }

    return GCD(b, a % b);
}


int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int N = 0;
    cin >> N;

    int Numerator = 0, Denominator = 0;
    cin >> Numerator;
    --N;

    for (int i = 0; i < N; ++i)
    {
        cin >> Denominator;
        int Result = GCD(Numerator, Denominator);
        cout << Numerator / Result << '/' << Denominator / Result << '\n';
    }

    return 0;
}