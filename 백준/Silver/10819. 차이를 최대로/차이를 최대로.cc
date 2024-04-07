#include <iostream>
#include <algorithm>
#define MAX 8
using namespace std;

int N, Max;
int arr[MAX];
int temp[MAX];
bool visited[MAX];

void DFS(int _depth)
{
    if (_depth == N)
    {
        int Sum = 0;
        for (int i = 0; i < N - 1; i++) // 아래서 +1 까지 탐색 하기 때문에 N-1 까지만
        {
            Sum += abs(temp[i] - temp[i + 1]);
        }

        Max = max(Max, Sum);
        return;
    }

    for (int i = 0; i < N; i++)
    {
        if (true == visited[i])
        {
            continue;
        }

        visited[i] = true;
        temp[_depth] = arr[i];
        DFS(_depth + 1);
        visited[i] = false;
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> N;
    
    for (size_t i = 0; i < N; i++)
    {
        cin >> arr[i];
    }

    DFS(0);

    cout << Max;

    return 0;
}