#include <iostream>
#include <vector>
#include <queue>
#define MAX 100001
using namespace std;

int N;
vector<vector<int>> vec;
bool visited[MAX];
int result[MAX];

void DFS(int _node)
{
    queue<int> q;
    q.push(_node);
    visited[_node] = true;

    while (false == q.empty())
    {
        int CurrentNode = q.front();
        q.pop();
        
        size_t size = vec[CurrentNode].size();
        for (size_t i = 0; i < size; i++)
        {
            int Next = vec[CurrentNode][i];
            if (false == visited[Next])
            {
                result[Next] = CurrentNode;
                visited[Next] = true;
                q.push(Next);
            }
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