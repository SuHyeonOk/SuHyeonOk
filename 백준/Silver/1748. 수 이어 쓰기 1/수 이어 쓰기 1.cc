#include <iostream>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int N = 0;
    cin >> N;

    int Sum = 0;
    for (int i = 1; i <= N; i *= 10) 
    {
        Sum += N - i + 1;
    }
    cout << Sum;

    return 0;
}