#include <iostream>
#include <vector>
#define MAX 100001
using namespace std;

int N;
vector<vector<int>> vec;
bool visited[MAX];
int result[MAX];

void DFS(int _node)
{
    visited[_node] = true;

    size_t size = vec[_node].size();
    for (size_t i = 0; i < size; i++)
    {
        int next = vec[_node][i];
        if (false == visited[next])
        {
            result[next] = _node;
            DFS(next);
        }
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> N;

    vec.resize(N + 1);

    int a = 0, b = 0;
    for (int i = 0; i < N - 1; i++)
    {
        cin >> a >> b;
        vec[a].push_back(b);
        vec[b].push_back(a);
    }

    DFS(1);

    for (int i = 2; i <= N; i++)
    {
        cout << result[i] << '\n';
    }

    return 0;
}