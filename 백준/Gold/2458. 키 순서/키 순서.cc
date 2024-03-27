#include <iostream>
#include <vector>
#include <cstring>
#define MAX 501
using namespace std;

int N, M, Result;
vector<int> vec[MAX];
int in[MAX], out[MAX];
bool visited[MAX];

int DFS(int n) 
{
    visited[n] = true;
    int Temp = 1;

    size_t Size = vec[n].size();
    for (int i = 0; i < Size; ++i)
    {
        if (false == visited[vec[n][i]])
        {
            in[vec[n][i]]++;
            Temp += DFS(vec[n][i]);
        }
    }

    return Temp;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> N >> M;

    int a = 0, b = 0;
    for (int i = 0; i < M; i++)
    {
        cin >> a >> b;
        vec[a].push_back(b);
    }

    for (int i = 1; i <= N; i++)
    {
        out[i] = DFS(i);
        memset(visited, false, sizeof(visited));
    }

    for (int i = 1; i <= N; i++)
    {
        if (in[i] + out[i] == N) // i보다 작은 키, 큰 키의 합이 N과 같다면 자신의 키가 몇번째 인지 안다.
        {
            Result++;
        }
    }
    
    cout << Result;

    return 0;
}