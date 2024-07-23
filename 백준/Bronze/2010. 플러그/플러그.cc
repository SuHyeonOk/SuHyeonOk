#include <iostream>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int N = 0;
    cin >> N;

    int Input = 0, Sum = 0;
    for (int i = 0; i < N; ++i)
    {
        cin >> Input;
        Sum += Input - 1;
    }

    cout << ++Sum;

    return 0;
}