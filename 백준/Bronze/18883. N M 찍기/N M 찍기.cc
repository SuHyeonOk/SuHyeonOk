#include <iostream>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int N = 0, M = 0;
    cin >> N >> M;

    for (int i = 0; i < N; i++) 
    {
        for (int j = 1; j <= M; j++) 
        {
            cout << i * M + j;
            if (j != M)
            {
                cout << ' ';
            }
        }
        cout << '\n';
    }

    return 0;
}