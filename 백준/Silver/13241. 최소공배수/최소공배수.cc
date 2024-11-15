#include <iostream>
using namespace std;

int GCD(long long int a, long long int b)
{
    if (b == 0)
    {
        return a;
    }

    return GCD(b, a % b);
}

int main()
{
    long long int a = 0, b = 0;
    cin >> a >> b;

    cout << (a * b) / GCD(a, b);

    return 0;
}