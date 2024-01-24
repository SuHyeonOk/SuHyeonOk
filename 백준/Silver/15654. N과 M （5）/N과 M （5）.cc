#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N, M;
vector<int> vec;
vector<int> num;
vector<bool> visited;

void DFS(int _depth)
{
    if (M == _depth)
    {
        for (int i = 0; i < M; i++)
        {
            cout << num[i] << ' ';
        }
        cout << '\n';
        return;
    }

    for (int i = 0; i < N; i++)
    {
        if (false == visited[i])
        {
            visited[i] = true;
            num[_depth] = vec[i];
            DFS(_depth + 1);
            visited[i] = false;
        }
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> N >> M;

    vec.resize(N);
    num.resize(N);
    visited.resize(N);

    for (int i = 0; i < N; i++)
    {
        cin >> vec[i];
    }

    sort(vec.begin(), vec.end());
    DFS(0);

    return 0;
}