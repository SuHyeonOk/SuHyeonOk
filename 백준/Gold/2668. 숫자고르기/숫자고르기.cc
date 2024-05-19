#include <iostream>
#include <vector>
#include <algorithm>
#include <string.h>
#define MAX 100001
using namespace std;

int N;
int arr[MAX];
int visited[MAX];
vector<int> vec;

void DFS(int up, int down)
{
    while (true)
    {
        if (up == arr[down])
        {
            vec.push_back(up);
            break;
        }

        if (false == visited[down])
        {
            visited[down] = true;
            DFS(up, arr[down]);
        }

        break; // 이전에 탐색했던 곳을 다시 탐색할 경우 종료.
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> N;

    for (int i = 1; i <= N; i++ )
    {
        cin >> arr[i];
    }

    for (int i = 1; i <= N; i++)
    {
        DFS(i, arr[i]);
        memset(visited, false, sizeof(visited));
    }

    size_t Size = vec.size();
    cout << Size << '\n';
    
    sort(vec.begin(), vec.end());
    for (size_t i = 0; i < Size; i++)
    {
        cout << vec[i] << '\n';
    }

    return 0;
}