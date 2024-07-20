#include <iostream>
#include <vector>
#include <algorithm>
#define MAX 100001
using namespace std;

int N = 0, M = 0, R = 0;
int Count = 0;
vector<vector<int>> vec;
bool visited[MAX] ;
int result[MAX] ;

void DFS(int r)
{
    if (true == visited[r])
    {
        return;
    }

    visited[r] = true;
    ++Count;
    result[r] = Count;

    int Size = vec[r].size();
    for (int i = 0; i < Size; i++)
    {
        DFS(vec[r][i]);
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> N >> M >> R;
    vec.resize(N + 1);

    int u = 0, v = 0;
    for (int i = 0; i < M; ++i)
    {
        cin >> u >> v;
        vec[u].push_back(v);
        vec[v].push_back(u);
    }

    for (int i = 1; i <= N; ++i)
    {
        sort(vec[i].begin(), vec[i].end(), greater<int>());
    }

    DFS(R);

    for (int i = 1; i <= N; i++)
    {
        cout << result[i] << '\n';
    }

    return 0;
}