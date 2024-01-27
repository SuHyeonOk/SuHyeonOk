#include <iostream>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int T = 0;
    cin >> T;

    int A = 0, B = 0;
    char Comma = ',';
    while (T--)
    {
        cin >> A >> Comma >> B;
        cout << A + B << '\n';
    }

    return 0;
}