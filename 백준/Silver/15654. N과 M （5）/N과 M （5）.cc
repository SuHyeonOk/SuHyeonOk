#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

#define MAX 10000
int N{ 0 }, M{ 0 };
vector<int> ns;
vector<int> vec(MAX, 0);
vector<bool> visited(MAX, false);

void DFS(int _count)
{
    // 목표 M까지 도달 했다면
    if (_count == M)
    {
        for (int i = 0; i < M; i++)
        {
            cout << vec[i] << ' ';
        }
        cout << '\n';

        return;
    }

    // 목표에 도달하지 못 했다면
    for (int i = 0; i < N; i++)
    {
        if (false == visited[ns[i]])
        {
            visited[ns[i]] = true;
            vec[_count] = ns[i];
            DFS(_count + 1); // M까지 들어간다.
            visited[ns[i]] = false;
        }
    }
}

int main()
{
    cin >> N >> M;

    ns.resize(N);
    for (int i = 0; i < N; i++)
    {
        cin >> ns[i];
    }
    sort(ns.begin(), ns.end());

    DFS(0);

    return 0;
}