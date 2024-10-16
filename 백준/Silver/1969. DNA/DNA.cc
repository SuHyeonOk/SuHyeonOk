#include <iostream>
#include <algorithm>
using namespace std;

string arr[1000];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int N = 0, M = 0;
    cin >> N >> M;

    int alphabet[50][26]{ 0 };
    char Input = ' ';
    string Temp = "";
    for (int i = 0; i < N; ++i)
    {
        for (int j = 0; j < M; ++j)
        {
            cin >> Input;
            Temp += Input;
            ++alphabet[j][Input - 'A'];
        }
        arr[i] = Temp;
        Temp = "";
    }

    char Result[50]{ ' ' };
    int Max = 0, Count = 0;
    for (int i = 0; i < M; ++i)
    {
        for (int j = 0; j < 26; ++j)
        {
            if (alphabet[i][j] > Max)
            {
                Max = alphabet[i][j];
                Result[i] = j + 'A';
            }
        }
        Max = 0;
    }

    for (int i = 0; i < M; ++i)
    {
        cout << Result[i];
    }

    for (int i = 0; i < N; ++i)
    {
        for (int j = 0; j < M; ++j)
        {
            if (arr[i][j] != Result[j])
            {
                ++Count;
            }
        }
    }

    cout << '\n' << Count;

    return 0;
}