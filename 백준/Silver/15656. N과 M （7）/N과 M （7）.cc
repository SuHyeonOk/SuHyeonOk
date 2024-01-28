#include <iostream>
#include <vector>
#include <algorithm>
#define MAX 7
using namespace std;

int N, M;
int result[MAX];
vector<int> num;

void DFS(int _depth)
{
    if (_depth == M)
    {
        for (int i = 0; i < M; i++)
        {
            cout << result[i] << ' ';
        }
        cout << '\n';
        return;
    }

    for (int i = 0; i < N; i++)
    {
        result[_depth] = num[i];
        DFS(_depth + 1);
    }
}

int main()
{
    ios::sync_with_stdio(false); 
    cin.tie(NULL); cout.tie(NULL);

    cin >> N >> M;

    num.resize(N);
    for (int i = 0; i < N; i++)
    {
        cin >> num[i];
    }

    sort(num.begin(), num.end());
    DFS(0);

    return 0;
}