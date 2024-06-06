#include <iostream>
using namespace std;

int main() 
{
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int T = 0;
    cin >> T;

    int N = 0;
    while (T--) 
    {
        cin >> N;
        int digit = 0;

        while (N > 0) 
        {
            if (N % 2 == 1)
            {
                cout << digit << " ";
            }

            N /= 2;
            digit++;
        }
    }

    return 0;
}