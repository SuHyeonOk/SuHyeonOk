#include <iostream>
#define MAX 9
using namespace std;

int N, M;
int num[MAX];
bool visited[MAX];

void DFS(int _depth)
{
    if (_depth == M)
    {
        for (int i = 0; i < M; i++)
        {
            cout << num[i] << " ";
        }

        cout << '\n';
        return;
    }

    for (int i = 1; i <= N; i++)
    {
        if (visited[i] == false)
        {
            visited[i] = true;
            num[_depth] = i;
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

    DFS(0);

    return 0;
}