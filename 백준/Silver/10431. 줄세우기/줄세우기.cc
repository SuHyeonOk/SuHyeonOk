#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int P = 0;
    cin >> P;

    int arr[20];

    int T = 0, Count = 0;
    while (P--)
    {
        cin >> T;

        for (int i = 0; i < 20; i++)
        {
            cin >> arr[i];
        }

        for (int i = 0; i < 20; i++) 
        {
            for (int j = i; j < 20; j++) 
            {
                if (arr[i] > arr[j])
                {
                    ++Count;
                }
            }
        }
        cout << T << ' ' << Count << "\n";
        Count = 0;
    }

    return 0;
}