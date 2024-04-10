#include <iostream>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    long long A = 0, B = 0;
    cin >> A >> B;

    cout << (A + B) * (A - B);

    return 0;
}