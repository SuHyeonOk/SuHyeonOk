#include <iostream>
#include <array>

using namespace std;

#define MAX 41

int main() 
{
    array<int, MAX> zero{ 1, 0 };
    array<int, MAX> one{ 0, 1 };

    int T{ 0 }, N{ 0 };
    cin >> T;

    for (int i = 0; i < T; i++) 
    {
        cin >> N;

        for (int j = 2; j <= N; j++) 
        {
            zero[j] = zero[j - 1] + zero[j - 2];
            one[j] = one[j - 1] + one[j - 2];
        }

        cout << zero[N] << " " << one[N] << '\n';
    }

}