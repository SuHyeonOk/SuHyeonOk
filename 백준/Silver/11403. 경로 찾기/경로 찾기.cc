#include <iostream>
#include <vector>
using namespace std;

int N{ 0 };
vector<vector<int>> vec;
vector<bool> visited;

void DFS(int node)
{
    size_t size = vec[node].size();
    for (size_t i = 0; i < size; i++)
    {
        int next = vec[node][i];
        if (false == visited[next])
        {
            visited[next] = true;
            DFS(next);
        }
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> N;
    vec.resize(N);
    visited.resize(N);

    int input{ 0 };
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            cin >> input;

            if (input == 1)
            {
                vec[i].push_back(j);
            }
        }
    }

    for (int i = 0; i < N; i++)
    {
        DFS(i);

        for (int i = 0; i < N; i++)
        {
            cout << visited[i] << " ";
        }
        cout << '\n';
        fill(visited.begin(), visited.end(), false);
    }

    return 0;
}