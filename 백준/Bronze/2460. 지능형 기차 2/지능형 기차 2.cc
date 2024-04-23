#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int Out = 0, In = 0;
    int Temp = 0, Max = 0;

    for (size_t i = 0; i < 10; i++)
    {
        cin >> Out >> In;
        Temp -= Out;
        Temp += In;
        Max = max(Max, Temp);
    }

    cout << Max;

    return 0;
}