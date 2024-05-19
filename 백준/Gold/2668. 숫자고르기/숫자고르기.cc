#include <iostream>
#include <vector>
#include <algorithm>
#include <string.h>
#define MAX 101
using namespace std;

int N;
int arr[MAX];
int visited[MAX];
vector<int> vec;

void DFS(int up, int down)
{
    if (up == arr[down]) // 찾으려고 하는 값(up)을 찾으면 종료
    {
        vec.push_back(up);
        return;
    }

    if (false == visited[down])
    {
        visited[down] = true;
        DFS(up, arr[down]);
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    // 입력
    cin >> N;
    for (int i = 1; i <= N; i++ )
    {
        cin >> arr[i];
    }

    // N개의 데이터 모두 탐색
    for (int i = 1; i <= N; i++)
    {
        DFS(i, arr[i]);
        memset(visited, false, sizeof(visited));
    }

    // 결과 출력
    size_t Size = vec.size();
    cout << Size << '\n';
    
    sort(vec.begin(), vec.end());
    for (size_t i = 0; i < Size; i++)
    {
        cout << vec[i] << '\n';
    }

    return 0;
}