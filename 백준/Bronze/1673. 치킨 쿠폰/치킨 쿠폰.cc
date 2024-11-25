#include <iostream>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int N = 0, K = 0;
    while (scanf("%d %d", &N, &K) != EOF) 
    {
        int Result = 0, Coipon = N, Temp = 0;
        while (Coipon) 
        {
            Result += Coipon;
            Temp += Coipon;
            Coipon = 0;
            Coipon += Temp / K;
            Temp %= K;
        }
        cout << Result << '\n';
    }

    return 0;
}