#include <iostream>
using namespace std;

int N, M;
int arr[8];
bool visited[8];

void Backtracking(int _Depth)
{
    if (_Depth == M)
    {
        for (int i = 0; i < M; ++i)
        {
            cout << arr[i] << ' ';
        }
        cout << '\n';
    }

    for (int i = 0; i < N; ++i)
    {
        if (false == visited[i])
        {
            visited[i] = true;
            arr[_Depth] = i + 1;
            Backtracking(_Depth + 1);
            visited[i] = false;
        }
    }

    return;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> N >> M;

    Backtracking(0);

    return 0;
}