#include <iostream>
#include <vector>
#include <queue>
#define M_MAX 1000001
using namespace std;

int N, M, K, X;
vector<vector<int>> vec;
vector<int> result;

void DFS(int _depth, int _x)
{
    size_t size = vec[_x].size();
    for (size_t i = 0; i < size; i++)
    {
        DFS(_depth + 1, vec[_x][i]);
    }

    if (result[_x] > _depth)
    {
        result[_x] = _depth;
    }
}

void Dijkstar(int _pos)
{
    result[_pos] = 0;
    queue<int> q;
    q.push(_pos);

    while (false == q.empty())
    {
        int current = q.front();
        q.pop();

        size_t size = vec[current].size();
        for (size_t i = 0; i < size; i++)
        {
            int next = vec[current][i];
            if (result[next] > result[current] + 1)
            {
                result[next] = result[current] + 1;
                q.push(next);
            }
        }
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> N >> M >> K >> X;
    
    vec.resize(N + 1);
    result.resize(N + 1, M_MAX);

    int A = 0, B = 0;
    for (int i = 0; i < M; i++)
    {
        cin >> A >> B;
        vec[A].push_back(B);
    }
    
    Dijkstar(X);

    bool find = false;
    for (int i = 1; i <= N; i++)
    {
        if (K == result[i]) 
        {
            find = true;
            cout << i << '\n';
        }
    }

    if (find == false)
    {
        cout << -1;
    }

    return 0;
}