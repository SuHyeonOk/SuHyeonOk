#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
#define MAX 501
using namespace std;

int N;
vector<int> edge[MAX];//간선 저장(먼저 지어져야 하는 건물)
int inDegree[MAX];//진입 차수 저장
int cost[MAX];//비용 저장
int dp[MAX];//각 건물까지 드는 비용 저장

void TopologicalSort() 
{
    queue<int> q;
    for (int i = 1; i <= N; i++) 
    {
        if (inDegree[i] == 0) 
        {
            q.push(i);
            dp[i] = cost[i];
        }
    }

    while (false == q.empty()) 
    {
        int CurrentNode = q.front();
        q.pop();

        size_t Size = edge[CurrentNode].size();
        for (size_t i = 0; i < Size; i++)
        {
            int next = edge[CurrentNode][i];
            if (--inDegree[next] == 0) 
            {
                q.push(next);
            }

            dp[next] = max(dp[next], cost[next] + dp[CurrentNode]);
        }

    }

    for (int i = 1; i <= N; i++)
    {
        cout << dp[i] << '\n';
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> N;

    int Input = 0;
    for (int i = 1; i <= N; i++) 
    {
        cin >> cost[i];
        
        cin >> Input;
        while (Input != -1) 
        {
            inDegree[i]++;
            edge[Input].push_back(i);

            cin >> Input;
        }
    }

    TopologicalSort();

    return 0;
}