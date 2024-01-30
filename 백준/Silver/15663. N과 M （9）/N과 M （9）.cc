#include <iostream>
#include <vector>
#include <algorithm>
#define MAX 8
using namespace std;

int N, M;
int num[MAX];
bool visited[MAX];
vector<int> vec;

void DFS(int _depth)
{
    if (M == _depth)
    {
        for (int i = 0; i < M; i++)
        {
            cout << vec[num[i]] << ' ';
        }
        cout << '\n';
        return;
    }

    int temp = 0;
    for (int i = 0; i < N; i++)
    {
        if (false == visited[i] && temp != vec[i])
        {
            num[_depth] = i;
            temp = vec[i];
            visited[i] = true;
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
    for (int i = 0; i < N; i++)
    {
        cin >> vec[i];
    }

    sort(vec.begin(), vec.end());
    DFS(0);

    return 0;
}