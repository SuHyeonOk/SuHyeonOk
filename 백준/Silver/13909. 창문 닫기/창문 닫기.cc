#include <iostream>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int N = 0;
    cin >> N;

    int Count = 0;
    for (int i = 1; i * i <= N; ++i)
    {
        Count++;
    }
    cout << Count;

    return 0;
}