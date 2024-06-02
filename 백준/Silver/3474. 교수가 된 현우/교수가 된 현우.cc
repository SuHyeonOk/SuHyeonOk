#include <iostream>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int N = 0, Num = 0;
    cin >> N;

    while (N--) 
    {
        cin >> Num;

        int Five = 0;

        for (int i = 5; i <= Num; i *= 5)
        {
            Five += Num / i;
        }

        cout << Five << "\n";
    }

    return 0;
}