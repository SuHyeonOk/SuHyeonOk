#include <iostream>
#include <algorithm>
#define MAX 8
using namespace std;

int N, M;
int arr[MAX];
int num[MAX];

void DFS(int _depth, int _i)
{
    if (M == _depth)
    {
        for (int i = 0; i < M; i++)
        {
            cout << num[i] << ' ';
        }
        cout << '\n';
        return;
    }

    int temp = 0;
    for (int i = _i; i < N; i++)
    {
        if (temp != arr[i])
        {
            temp = arr[i];
            num[_depth] = arr[i];
            DFS(_depth + 1, i);
        }
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> N >> M;
    for (int i = 0; i < N; i++)
    {
        cin >> arr[i];
    }
    sort(arr, arr + N);
    DFS(0, 0);

    return 0;
}