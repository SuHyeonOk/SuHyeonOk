#include <iostream>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int N = 0;
    cin >> N;

    char Input = ' ';
    int Bonus = 0, Sum = 0;
    for (int i = 1; i <= N; ++i)
    {
        cin >> Input;

        if (Input == 'O')
        {
            Sum += i + Bonus;
            ++Bonus;
        }
        else
        {
            Bonus = 0;
        }
    }

    cout << Sum;

    return 0;
}