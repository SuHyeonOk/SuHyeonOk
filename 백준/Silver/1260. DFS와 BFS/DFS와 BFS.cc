#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int N, M, V;
vector<vector<int>> vec;
vector<bool> visited;

void DFS(int _V)
{
    cout << _V << ' ';

    size_t Size = vec[_V].size();
    for (int i = 0; i < Size; ++i)
    {
        int Temp = vec[_V][i];
        if (true == visited[Temp])
        {
            continue;
        }

        visited[Temp] = true;
        DFS(Temp);
    }
}

void BFS(int _V)
{
    queue<int> q;
    q.push(_V);
    cout << _V << ' ';

    while (false == q.empty())
    {
        int Next = q.front();
        q.pop();

        size_t Size = vec[Next].size();
        for (int i = 0; i < Size; ++i)
        {
            int Temp = vec[Next][i];
            if (true == visited[Temp])
            {
                continue;
            }

            visited[Temp] = true;
            cout << Temp << ' ';
            q.push(Temp);
        }
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    cin >> N >> M >> V;

    vec.resize(N + 1);
    visited.resize(N + 1);

    int A = 0, B = 0;
    for (int i = 0; i < M; ++i)
    {
        cin >> A >> B;
        vec[A].push_back(B);
        vec[B].push_back(A);
    }

    for (int i = 0; i < N + 1; ++i)
    {
        sort(vec[i].begin(), vec[i].end());
    }

    visited[V] = true;
    DFS(V);

    cout << '\n';
    visited.clear();
    visited.resize(N + 1);

    visited[V] = true;
    BFS(V);

    return 0;
}