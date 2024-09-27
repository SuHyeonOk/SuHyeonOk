#include <iostream>
#include <string.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int N = 0, K = 0;
    cin >> N >> K;

    char arr[26];
    memset(arr, '?', sizeof(arr));

    int S = 0, Temp = 1;
    char Alphabet = ' ';
    bool Lucky = true;
    for (int i = 0; i < K; ++i)
    {
        cin >> S >> Alphabet;

        int Index = (Temp + S) % N;
        if (Index == 0)
        {
            Index = N;
        }

        // 1. 이미 값이 들어있고, 그 값이 다른 경우는 불가능
        if ('?' != arr[Index] && Alphabet != arr[Index])
        {
            Lucky = false;
            break;
        }

        arr[Index] = Alphabet;
        Temp = Index;
    }

    // 2. 같은 글자는 두 번 이상 등장하면 안 된다.
    bool visited[26]{ false };
    for (int i = 1; i <= N; ++i)
    {
        if ('?' == arr[i])
        {
            continue;
        }

        if (false == visited[arr[i] - 'A'])
        {
            visited[arr[i] - 'A'] = true;
        }
        else
        {
            Lucky = false;
        }
    }

    if (false == Lucky)
    {
        cout << '!';
        return 0;
    }

    for (int i = Temp; i > 0; --i)
    {
        cout << arr[i];
    }
    for (int i = N; i > Temp; --i)
    {
        cout << arr[i];
    }

    return 0;
}