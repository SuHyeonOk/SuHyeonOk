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

        // 이미 배열에 값이 들어갔는데 이전에 들어간 값과 다르다면 바퀴를 알 수 없음.
        if ('?' != arr[Index] && Alphabet != arr[Index])
        {
            Lucky = false;
            break;
        }

        arr[Index] = Alphabet;
        Temp = Index;
    }

    bool visited[26]{ false };
    for (int i = Temp; i > 0; --i)
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
    for (int i = N; i > Temp; --i)
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