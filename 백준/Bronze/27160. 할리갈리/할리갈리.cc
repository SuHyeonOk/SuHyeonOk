#include <iostream>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int N = 0;
    cin >> N;


    string S = "";
    int X = 0;
    int arr[26]{ 0 };
    while(N--)
    {
        cin >> S >> X;
        arr[S[0] - 'A'] += X;
    }

    for (int i = 0; i < 26; ++i)
    {
        if (arr[i] == 5)
        {
            cout << "YES";
            return 0;
        }
    }

    cout << "NO";

    return 0;
}