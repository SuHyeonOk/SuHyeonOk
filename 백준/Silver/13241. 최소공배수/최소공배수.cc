#include <iostream>
using namespace std;

int GCD(long long a, long long b)
{
    if (b == 0)
    {
        return a;
    }

    return GCD(b, a % b);
}

int main()
{
    long long a = 0, b = 0;
    cin >> a >> b;

    cout << (a * b) / GCD(a, b);

    return 0;
}