#include <iostream>
#include <vector>
#include <algorithm>
#include <string.h>
#define MAX 100001
using namespace std;

int N, Temp;
int arr[MAX];
int visited[MAX];
vector<int> vec;

void DFS(int up, int down)
{
    while (true)
    {
        if (Temp == arr[down])
        {
            vec.push_back(Temp);
            break;
        }

        if (false == visited[down])
        {
            visited[down] = true;
            DFS(down, arr[down]);
        }
        else
        {
            break;
        }
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
        Temp = i;
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