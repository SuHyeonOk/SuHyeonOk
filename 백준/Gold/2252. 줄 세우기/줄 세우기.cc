#include <iostream>
#include <vector>
#include <queue>
using namespace std;

vector<int> graph[32001];
int inDegree[32001];
int N, M;

void TopologicalSort(void) 
{
    queue<int> q;

    for (int i = 1; i <= N; i++)
    {
        if (false == inDegree[i])
        {
            q.push(i);
        }
    }
        
    while (false == q.empty()) 
    {
        int cur = q.front();
        q.pop();
        cout << cur << ' ';

        for (int i = 0; i < graph[cur].size(); i++) 
        {
            inDegree[graph[cur][i]]--;
            if (false == inDegree[graph[cur][i]])
            {
                q.push(graph[cur][i]);
            }
        }
    }
}

int main() 
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> N >> M;

    int a = 0, b = 0;
    for (int i = 0; i < M; i++) 
    {
        cin >> a >> b;
        graph[a].push_back(b);
        inDegree[b]++;
    }

    TopologicalSort();

    return 0;
}