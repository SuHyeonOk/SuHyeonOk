#include <iostream>
#include <vector>
#include <algorithm>
#define MAX 200000
using namespace std;

int Count[MAX];
bool visited[MAX];
vector<vector<int>> graph(MAX);
int First = 1;

void DFS(int start)
{
    if (true == visited[start]) 
    {
        return;
    }

    visited[start] = true;
    Count[start] = First;
    First++;

    sort(graph[start].begin(), graph[start].end());

    for (int i = 0; i < graph[start].size(); i++) 
    {
        int y = graph[start][i];
        DFS(y);
    }
}

int main() 
{
    int n = 0, m = 0, First = 0;
    cin >> n >> m >> First;

    int a = 0, b = 0;
    for (int i = 0; i < m; i++)
    {
        cin >> a >> b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }

    DFS(First);

    for (int i = 1; i <= n; i++) 
    {
        cout << Count[i] << '\n';
    }

    return 0;
}