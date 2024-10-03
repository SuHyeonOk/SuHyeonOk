#include <iostream>
#include <queue>
#define MAX 1000001
using namespace std;

int A, K;
bool visited[MAX];

int BFS()
{
    queue<pair<int, int>> q;
    q.push({ K, 0 });
    visited[K] = true;

    while (false == q.empty())
    {
        int Temp = q.front().first;
        int Depth = q.front().second;
        q.pop();

        if (Temp == A)
        {
            return Depth;
        }

        // K에서 A로 가는 경우, 1을 뺀다.
        if (Temp - 1 >= A && false == visited[Temp - 1])
        {
            visited[Temp - 1] = true;
            q.push({ Temp - 1, Depth + 1 });
        }
        // 짝수인 경우 2로 나누는 연산
        if (Temp % 2 == 0 && Temp / 2 >= A && false == visited[Temp / 2])
        {
            visited[Temp / 2] = true;
            q.push({ Temp / 2, Depth + 1 });
        }
    }

    return 0;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> A >> K;

    cout << BFS();

    return 0;
}
